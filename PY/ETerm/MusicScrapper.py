import os
import selenium
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver import ActionChains
from bs4 import BeautifulSoup
import time
import timeit
import pyautogui
import urllib.request

BANDCAMP_URL = "https://ridiculon.bandcamp.com/album/the-end-is-nigh-ost"
KHINSIDER_URL = "https://downloads.khinsider.com/game-soundtracks/album/stellaris-original-soundtrack-2016"

driver = webdriver.Chrome("F:/Downloads/Carpetas/Utility/Temp/chromedriver.exe")

def bandcamp():

    driver.get("http://downloadbandcamp.com/")
    driver.find_element_by_id("url_input").send_keys(BANDCAMP_URL)
    driver.find_element_by_id("url_input").send_keys(u"\ue007")

    # time.sleep(3)

    music_buttons = driver.find_elements_by_id("cleanlink")
    songs = []
    n = 0
    for button in music_buttons:
        if button.text == "Download":
            songs.append(button.get_attribute('href'))
            source = button.get_attribute('href')
            destination = f"{n}.mp3"
            urllib.request.urlretrieve(source, destination)
            n += 1

    print(songs)
    print()
    print(len(songs))
    os.system("pause")

def khinsider():

    driver.get(KHINSIDER_URL)

    elements = driver.find_elements_by_tag_name("a")
    urls = []

    for element in elements:
        if "MB" in element.text:
            href = element.get_attribute('href')
            if href[-3:] == "mp3" and href not in urls:
                urls.append(href)
    
    music_urls = []
    
    for url in urls:
        driver.get(url)
        try:
            music_urls.append(driver.find_element_by_partial_link_text("Click here to download as MP3").get_attribute('href'))
        except:
            pass
    
    n = 1
    for url in music_urls:
        source = url
        destination = f"{n}.mp3"
        urllib.request.urlretrieve(source, destination)
        n += 1

if __name__ == "__main__":
    khinsider()