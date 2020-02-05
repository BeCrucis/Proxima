from mechanize import Browser
import bs4 as bs
import urllib.request as ulib
from Grupo import Grupo
from Logger import *

class Asignatura:

    def __init__(self, subjectCode):

        self.subjectcode = str(subjectCode)

        #Las funciones que terminan en Log simplemente imprimen textos en formatos 
        #predeterminados para propositos de debugging

        print()
        courseLog(f"Detectando asignatura de codigo : {self.subjectcode}")

        self.HTMLLines = self.getSubjectHTML()

        infoLog("Asignatura detectada!")

        self.name = str(self.HTMLLines[45]).strip()

        infoLog(f"Nombre de la asignatura [{self.subjectcode}] : {self.name}")
        courseLog(f"Obteniendo grupos de {self.name} . . .")

        self.groups = self.getGroups(self.HTMLLines)

    def getSubjectHTML(self):

        br = Browser()
        br.open("http://uis.edu.co/estudiantes/asignaturas_programadas/buscador.html")
        br.select_form(name = "form1") # pylint: disable=no-member
        br.form['codigo'] = self.subjectcode # pylint: disable=no-member
        br.submit() # pylint: disable=no-member

        soup = bs.BeautifulSoup(br.response().read(), "html.parser") # pylint: disable=no-member
        soup = soup.prettify()
        html = soup.split("\n")

        #Se descubrio que si existe un parametro invalido, la respuesta del
        #servidor sera menor a 60 lineas de HTML
        if len(html) < 60: 
            errorLog("Asignatura no detectada")
            raise InvalidSubjectCode()
            
        return html

    def getGroups(self, HTMLCode):

        index = 0
        groups = []

        for line in HTMLCode:

            line = str(line).strip()

            if "Grupo" in line:
                groupCode = line[7:]

                infoLog(f"Grupo de {self.name} detectado: {groupCode}")
                courseLog(f"[{groupCode}] Detectando información . . .")
                
                groupCapacity = int(str(HTMLCode[index + 13]).strip())
                groupStudents = int(str(HTMLCode[index + 20]).strip())

                infoLog(f"[{groupCode}] Capacidad : {groupCapacity} -- Matriculados: {groupStudents}")

                group = Grupo(self.subjectcode, groupCode, groupCapacity, groupStudents)

                print() #Deja un espacio para facilitar el logging entre grupos

                groups.append(group)

            index += 1
        
        return groups
    
    def sortGroups(self):

        self.groups.sort(key=lambda x: x.deathIndex, reverse=False)

class InvalidSubjectCode(Exception):
    pass