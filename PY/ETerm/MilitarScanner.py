import os
import selenium
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
import timeit


def importObserverInfo(driver, observerLink, observerName, courseName):
	
	driver.get(observerLink)

	searchBox = driver.find_elements_by_id("people_search")[0]
	searchBox.send_keys("Comportamiento " + courseName)

	time.sleep(2)

	moreElements = driver.find_elements_by_class_name("result_type_course")

	moreElements[0].click()

	time.sleep(2)

	searchBox.send_keys(u"\ue007")

	time.sleep(2)
	
	elements = driver.find_elements_by_tag_name("a")

	links = []

	for element in elements:
		if element.get_attribute("class") == "poll record":
			links.append(element.get_attribute("href"))

	links = list(dict.fromkeys(links))

	students = {}
	
	for link in links:

		studentInfoOED = importStudentInfoOED(driver, link)
		studentName = studentInfoOED[0]
		studentDates = studentInfoOED[1]

		students[studentName] = studentDates

	return students

def importStudentInfoOED(driver, link):

	driver.get(link)

	studentInfo = driver.find_elements_by_css_selector("span[person_role=\"estudiante\"]")[0]

	studentName = studentInfo.get_attribute("innerHTML")

	studentInfo = []

	studentInfo.append(studentName)

	dateList = []

	fechas = driver.find_elements_by_css_selector("td[class =\"poll record fixedrow sel\"]")
	
	if fechas:

		soup = BeautifulSoup(driver.page_source, features="lxml")
		elements = soup.find_all("tr")

		observerEntries = elements[4:]
		
		for entry in observerEntries:
			entryData = entry.findChildren("td" , recursive=False)
			if entryData[5].text.upper() == "Tercer Periodo".upper():
				rawFecha = entryData[2].text
				formattedFecha = rawFecha[:10]
				dateList.append(formattedFecha)

		if dateList:	
			dateList.append("OED")

	studentInfo.append(dateList)

	return studentInfo


def main(headless = False):
	
	username = "william.parada81"
	password = "Caballeria1972" 

	if headless:

		options = Options()
		options.headless = True
		driver = webdriver.Chrome("F:/Downloads/Carpetas/Utility/Temp/chromedriver.exe", options=options)
	
	else:
		driver = webdriver.Chrome("F:/Downloads/Carpetas/Utility/Temp/chromedriver.exe")
		print("Usando Chrome con cabeza")

	driver.get("https://colmilgeneralsantander.phidias.co/")

	userBox = driver.find_element_by_id("autofocus")
	userBox.send_keys(username)

	passwordBox = driver.find_elements_by_xpath("//*[@id=\"login_form\"]/fieldset/div[2]/input")[0]
	passwordBox.send_keys(password)

	passwordBox.send_keys(u"\ue007")

	courses = {}

	# # courses["PREJARDIN"] = ["PREJARDIN 1"]
	# courses["JARDIN"] = ["JARDIN 1"]
	# courses["TRANSICION"] = ["TRANSICION 1"]
	# courses["PRIMERO"] = ["PRIMERO 1"]
	# courses["SEGUNDO"] = ["SEGUNDO 1"]
	# courses["TERCERO"] = ["TERCERO 1"]
	# courses["CUARTO"] = ["CUARTO 1"]
	# courses["QUINTO"] = ["QUINTO 1"]
	courses["SEXTO"] = ["SEXTO 1", "SEXTO 2"]
	courses["SEPTIMO"] = ["SEPTIMO 1", "SEPTIMO 2"]
	courses["OCTAVO"] = ["OCTAVO 1","OCTAVO 2"]
	courses["NOVENO"] = ["NOVENO 1", "NOVENO 2"]
	courses["DECIMO"] = ["DECIMO 1"]
	courses["UNDECIMO"] = ["UNDECIMO 1", "UNDECIMO 2"]



	for courseGrade in courses:

		for course in courses[courseGrade]:

			courseName = F"{courseGrade} {course}"

			observerInfo = importObserverInfo(driver, "https://colmilgeneralsantander.phidias.co/poll/consolidate/people?poll=23", "OED", courseName)

			with open(F"{courseName}.txt", "w") as f:

				infoFile = open(F"{courseName}INFO.txt", "w")
				califFile = open(F"{courseName}GRADES.txt", "w")
				nameFile = open(F"{courseName}NAMES.txt", "w")

				print(courseName)

				for student in observerInfo:
					print(F"{student}: {observerInfo[student]}")
					print()

					if len(observerInfo[student]) > 1:	
						f.write(F"{student} : {(98-(len(observerInfo[student])*3))/10} : {' '.join(observerInfo[student]) }\n")
						califFile.write(F"{(98-(len(observerInfo[student])*3))/10}\n")
					else:
						f.write(F"{student} : {95/10} : {' '.join(observerInfo[student]) }\n")
						califFile.write(F"{95/10}\n")
					
					infoFile.write(F"{' '.join(observerInfo[student]) }\n")
					nameFile.write(F"{student.upper()}\n")

				infoFile.close()
				califFile.close()
				nameFile.close()
			

main()
