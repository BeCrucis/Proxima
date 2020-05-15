from __future__ import unicode_literals
import os
import sys
import selenium
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver import ActionChains
from bs4 import BeautifulSoup
import time
import timeit
import urllib.request
import mutagen
from mutagen.mp3 import MP3
from mutagen.id3 import ID3, APIC, error
from mutagen.easyid3 import EasyID3
import youtube_dl

BANDCAMP_URL = "https://curtisschweitzer.bandcamp.com/album/starbound-original-soundtrack"
KHINSIDER_URL = "https://downloads.khinsider.com/game-soundtracks/album/rimworld"
# YOUTUBE_URL = ""

def bandcamp(driver, URL):

    driver.get(URL)
    track_elements = driver.find_elements_by_class_name("track-title")
    track_names = [track.text for track in track_elements]
    album_name = driver.find_element_by_class_name("trackTitle").text.strip()

    album_image_url = driver.find_element_by_class_name("popupImage").get_attribute("href")

    urllib.request.urlretrieve(album_image_url, "album_cover.jpg")

    bandcamp_artist_id = URL.split('/')[2]
    bandcamp_artist_url = f"https://{bandcamp_artist_id}"

    for element in driver.find_elements_by_tag_name("span"):
        try:
            if element.get_attribute("itemprop") == "byArtist":
                artist_name = element.text
        except:
            continue

    track_number = 0

    for track_name in track_names:

        track_number += 1

        track_name = track_name.replace('(', '').replace(')', '')
        track_name = track_name.replace(':', '')
        track_name = track_name.replace('[', '').replace(']', '')

        print(f'[INFO] Importando cancion {track_name}')

        if os.path.exists(f'{track_name}.mp3'):
            print(f'[INFO] Cancion {track_name} ya existente, continuando . . .')
            continue

        track = track_name.replace(" ", "-")
        driver.get(f"{bandcamp_artist_url}/track/{track}")

        

        driver.find_elements_by_class_name("playbutton")[0].click()
        driver.find_elements_by_class_name("playbutton")[0].click()

        audio_elements = driver.find_elements_by_tag_name("audio")

        for element in audio_elements:
            try:
                mp3_file = element.get_attribute("src")
                break
            except:
                continue
        
        try:
            mp3_filename = f"{track_name}.mp3"
            urllib.request.urlretrieve(mp3_file, mp3_filename)

        except:
            print(f"Cancion {track_name} no pudo ser recogida!")
            continue

        # Dandole tags al archivo mp3
        mp3 = MP3(mp3_filename, ID3=ID3)

        # add ID3 tag if it doesn't exist
        try:
            mp3.add_tags()
        except error:
            pass

        mp3.tags.add(
            APIC(
                encoding=3, # 3 is for utf-8
                mime='image/jpg', # image/jpeg or image/png
                type=3, # 3 is for the cover image
                desc=u'Cover',
                data=open('album_cover.jpg', "rb").read()
            )
        )
        mp3.save()

        mp3_tags = EasyID3(mp3_filename)

        mp3_tags['title'] = track_name
        mp3_tags['artist'] = artist_name
        mp3_tags['album'] = album_name
        mp3_tags['tracknumber'] = str(track_number).zfill(2)

        mp3_tags.save()
    
    os.remove("album_cover.jpg")

def khinsider(driver, URL):

    driver.get(URL)

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

def youtube(driver, URL):

    class MyLogger(object):

        def debug(self, msg):
            print(f"[INFO] {msg}")

        def warning(self, msg):
            print(f"[WARNING] {msg}")

        def error(self, msg):
            print(f"[ERROR] {msg}")


    def my_hook(d):
        if d['status'] == 'finished':
            print('[INFO] Download Complete, converting to mp3 . . .')


    ydl_opts = {
        'format': 'bestaudio/best',
        'postprocessors': [{
            'key': 'FFmpegExtractAudio',
            'preferredcodec': 'mp3',
            'preferredquality': '320',
        }],
        'logger': MyLogger(),
        # 'progress_hooks': [my_hook],
    }
    with youtube_dl.YoutubeDL(ydl_opts) as ydl:
        ydl.download([URL])

def print_title():
    print("""
 __   __  __   __  _______  ___   _______  _______  _______  ______    _______  _______  _______  _______  ______   
|  |_|  ||  | |  ||       ||   | |       ||       ||       ||    _ |  |   _   ||       ||       ||       ||    _ |  
|       ||  | |  ||  _____||   | |       ||  _____||       ||   | ||  |  |_|  ||    _  ||    _  ||    ___||   | ||  
|       ||  |_|  || |_____ |   | |       || |_____ |       ||   |_||_ |       ||   |_| ||   |_| ||   |___ |   |_||_ 
|       ||       ||_____  ||   | |      _||_____  ||      _||    __  ||       ||    ___||    ___||    ___||    __  |
| ||_|| ||       | _____| ||   | |     |_  _____| ||     |_ |   |  | ||   _   ||   |    |   |    |   |___ |   |  | |
|_|   |_||_______||_______||___| |_______||_______||_______||___|  |_||__| |__||___|    |___|    |_______||___|  |_|
""")
    print("\n by Gacrucis \n")

def print_menu():

    print("Bandcamp = 1")
    print("KHInsider = 2")
    print("Youtube = 3")
    print()

def main():

    print_title()
    print_menu()
    option = input("Select option : ")

    driver = webdriver.Chrome("F:/Downloads/Carpetas/Utility/Temp/chromedriver.exe")
    
    if option == "1":

        try:
            url = BANDCAMP_URL
        except:
            url = input("Ha seleccionado Bandcamp, Inserte URL: ")
        
        bandcamp(driver, url)
    
    elif option == "2":

        try:
            url = KHINSIDER_URL
        except:
            url = input("Ha seleccionado KHInsider, Inserte URL: ")
        
        khinsider(driver, url)
    
    elif option == "3":

        try:
            url = YOUTUBE_URL
        except:
            url = input("Ha seleccionado Youtube, Inserte URL: ")
        
        youtube(driver, url)

if __name__ == "__main__":
    main()

