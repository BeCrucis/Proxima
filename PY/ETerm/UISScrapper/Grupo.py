import bs4 as bs
import urllib.request as ulib
from Logger import *
import os

class Grupo:

    def __init__(self, subjectCode, groupCode, capacity: int, studentQuantity: int):

        self.subjectCode = subjectCode
        self.groupCode = groupCode
        self.capacity = capacity
        self.studentQuantity = studentQuantity

        if studentQuantity >= capacity:
            self.isFull = True
            infoLog(f"[{self.groupCode}] Grupo lleno!")
        else:
            self.isFull = False
        
        # El link debajo es la base para obtener la informacion del grupo.
        # Para ello se usa web scraping en el link designado para el grupo
        # obtenido con el codigo de asignatura y codigo de grupo

        customLink = f"http://uis.edu.co/estudiantes/asignaturas_programadas/horario_asignatura.jsp?codigo={self.subjectCode}&grupo={self.groupCode}%20&nombre=CUSTOM"
        groupInfo = ulib.urlopen(customLink).read()
        groupSoup = bs.BeautifulSoup(groupInfo, "html.parser")
        self.html = groupSoup.prettify().split("\n")

        self.profesores = self.getTeachers()
        infoLog(f"[{self.groupCode}] Profesores: {self.profesores}")

        # Se calcula el indice de muerte o bolsa en relacion a la cantidad de
        # estudiantes matriculados respecto a la capacidad del grupo, pues
        # me da pereza sacar un algoritmo mas complejo para algo tan subjetivo
        # como ver si el profesor es coche o bolsa, quiza algun dia lo saque de
        # las referencias de DetodoUIS si averiguo como sacar las referencias de ahi

        try:
            self.deathIndex = round(capacity/studentQuantity, 2) 
        except:
            self.deathIndex = 99

        self.schedule = self.getSchedule()
        infoLog(f"[{self.groupCode}] Horario: {self.schedule}")
    
    def getTeachers(self):

        teachers = []

        lineIndex = 0

        for line in self.html:

            if "profesor" in line.lower():
                teacher = self.html[lineIndex + 3]

                # En caso de que no haya un profesor designado, aparecera el string
                # </td> en la variable teacher, se verifica que no este este string con 
                # el if de abajo, en caso de no estar significa que existe un profesor
                # valido en la variable teacher

                if "<" not in teacher:
                    teachers.append(teacher.strip())       
                else:
                    if not teachers:
                        teachers.append("Sin profesor")

            lineIndex += 1

        teachers = list(dict.fromkeys(teachers)) #Elimina los profesores duplicados

        return teachers
    
    def getSchedule(self):

        schedule = {}

        lineIndex = 0

        for line in self.html:

            if "día" in line.lower():

                day = self.html[lineIndex + 4].strip()
                schedule.setdefault(day, [])

                hours = self.html[lineIndex + 14].strip()

                schedule[day].append(hours)

            lineIndex += 1

        return schedule

    # Este es el formato que se usa en el archivo de texto creado para la asignatura pero
    # con colores, sin embargo parece no funcionar bien en la consola de Windows
    def prettyPrint(self):
        
        groupInfo = F"Grupo: [{self.groupCode}] // #: {self.studentQuantity} !: {self.capacity}"
        groupTeachers = F"Profesores: {self.profesores} IB: {self.deathIndex}"
        formattedString = F"{groupInfo}\n{groupTeachers}"

        if self.isFull:
            formattedString = bcolors.FAIL + formattedString + bcolors.ENDC

        print(formattedString)

    # Este es el formato que se usa en el archivo de texto creado para la asignatura
    def __repr__(self):
        
        groupInfo = F"Grupo: [{self.groupCode}] // #: {self.studentQuantity} !: {self.capacity}"
        groupTeachers = F"Profesores: {self.profesores} IB: {self.deathIndex}"
        groupSchedule = F"Horario: {self.schedule}"
        formattedString = F"{groupInfo}\n{groupTeachers}\n{groupSchedule}\n"

        if self.isFull:
            formattedString = formattedString + "||||||||||||||||||||||||||||||||||||||||"

        return formattedString

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'