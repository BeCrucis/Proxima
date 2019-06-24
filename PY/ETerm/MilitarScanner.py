import os
import selenium
from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
import time


def importObserverInfo(driver, observerLink, observerName, courseName):
	
	driver.get(observerLink)

	searchBox = driver.find_elements_by_id("people_search")[0]
	searchBox.send_keys("Comportamiento " + courseName)

	driver.implicitly_wait(2)

	aRandomElement = driver.find_elements_by_class_name("audience_result") #No se por que, pero sin esto no funciona

	searchResult = driver.find_element_by_id("people_results")
	searchResult.click()

	time.sleep(1)

	searchBox.send_keys(u"\ue007")
	
	elements = driver.find_elements_by_tag_name("a")

	links = []

	for element in elements:
		if element.get_attribute("class") == "poll record":
			links.append(element.get_attribute("href"))

	links = list(dict.fromkeys(links))

	students = {}
	
	for link in links:

		driver.get(link)

		studentInfo = driver.find_elements_by_css_selector("span[person_role=\"estudiante\"]")[0]

		studentName = studentInfo.get_attribute("innerHTML")

		students[studentName] = []
		listaFechas = []

		fechas = driver.find_elements_by_css_selector("td[class =\"poll record fixedrow sel\"]")
		
		if fechas:

			soup = BeautifulSoup(driver.page_source, features="lxml")
			elements = soup.find_all("tr")

			observerEntries = elements[4:]
			
			for entry in observerEntries:
				entryData = entry.findChildren("td" , recursive=False)
				if entryData[5].text.upper() == "Segundo Periodo".upper():
					rawFecha = entryData[2].text
					formattedFecha = rawFecha[:10]
					listaFechas.append(formattedFecha)
				
			listaFechas.append(observerName)

		students[studentName] = listaFechas

	return students

		
username = "william.parada81"
password = "Caballeria1972" 

global driver

driver = webdriver.Chrome("F:/Downloads/Carpetas/Utility/Temp/chromedriver.exe")
driver.get("https://colmilgeneralsantander.phidias.co/")

userBox = driver.find_element_by_id("autofocus")
userBox.send_keys(username)

passwordBox = driver.find_elements_by_xpath("//*[@id=\"login_form\"]/fieldset/div[2]/input")[0]
passwordBox.send_keys(password)

passwordBox.send_keys(u"\ue007")

courses = {}

courses["PRIMERO"] = ["PRIMERO 1"]
courses["SEGUNDO"] = ["SEGUNDO 1"]

for courseGrade in courses:

	for course in courses[courseGrade]:

		courseName = F"{courseGrade} {course}"

		print(courseName)

		observerInfo = importObserverInfo(driver, "https://colmilgeneralsantander.phidias.co/poll/consolidate/people?poll=23", "OED", courseName)

		for student in observerInfo:
			print(F"{student}: {observerInfo[student]}")
			print()


