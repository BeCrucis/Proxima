from mechanize import Browser
import bs4 as bs
import urllib.request as ulib
from Grupo import Group
import Logger as log

class Subject:

    def __init__(self, subject_code, logging=True):

        self.subject_code = str(subject_code)

        #Las funciones que terminan en Log simplemente imprimen textos en formatos 
        #predeterminados para propositos de debugging

        print()
        log.course_log(f"Detectando asignatura de codigo : {self.subject_code}")

        self.html_lines = self.get_subjectHTML()

        log.info_log("Asignatura detectada!")

        self.name = str(self.html_lines[45]).strip()

        log.info_log(f"Nombre de la asignatura [{self.subject_code}] : {self.name}")
        log.course_log(f"Obteniendo grupos de {self.name} . . .")

        self.groups = self.get_groups(self.html_lines, logging)

    def get_subjectHTML(self):

        br = Browser()
        br.open("https://www.uis.edu.co/estudiantes/asignaturas_programadas/buscador.html")
        br.select_form(name = "form1") # pylint: disable=no-member
        br.form['codigo'] = self.subject_code # pylint: disable=no-member
        br.submit() # pylint: disable=no-member

        soup = bs.BeautifulSoup(br.response().read(), "html.parser") # pylint: disable=no-member
        soup = soup.prettify()
        html = soup.split("\n")

        #Se descubrio que si existe un parametro invalido, la respuesta del
        #servidor sera menor a 60 lineas de HTML
        if len(html) < 60: 
            log.error_log("Asignatura no detectada")
            raise InvalidSubjectCode()
            
        return html

    def get_groups(self, html_code, logging=True):

        index = 0
        groups = []

        for line in html_code:

            line = str(line).strip()

            if "Grupo" in line:
                group_code = line[7:]

                if logging:
                    log.info_log(f"Grupo de {self.name} detectado: {group_code}")
                    log.course_log(f"[{group_code}] Detectando información . . .")
                
                group_capacity = int(str(html_code[index + 13]).strip())
                group_students = int(str(html_code[index + 20]).strip())

                if logging:
                    log.info_log(f"[{group_code}] Capacidad : {group_capacity} -- Matriculados: {group_students}")

                group = Group(self.subject_code, self.name,  group_code, group_capacity, group_students, logging=logging)

                if logging:
                    print() #Deja un espacio para facilitar el logging entre grupos

                groups.append(group)

            index += 1
        
        return groups
    
    def get_group_by_code(self, group_code):

        for group in self.groups:
            if group.group_code == group_code:
                return group
        
        log.error_log(f'Grupo {group_code} no encontrado')
        return None
    
    def sort_groups(self):

        self.groups.sort(key=lambda x: x.death_index, reverse=False)

class InvalidSubjectCode(Exception):
    pass