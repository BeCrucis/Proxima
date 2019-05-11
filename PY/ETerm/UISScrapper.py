from mechanize import Browser
import bs4 as bs
import urllib.request as ulib
import os

codigo = "20254"

br = Browser()
br.open("http://uis.edu.co/estudiantes/asignaturas_programadas/buscador.html")

br.select_form(name = "form1") # pylint: disable=no-member

br.form['codigo'] = codigo # pylint: disable=no-member
br.submit() # pylint: disable=no-member

soup = bs.BeautifulSoup(br.response().read(), "html.parser") # pylint: disable=no-member
soup = soup.prettify()

HTMLLines = soup.split("\n")

asignatura = str(HTMLLines[45]).strip()
print(F"Asignatura detectada: {asignatura}")

grupos = []
capacidades = []
estudiantes = []

index = 0
for line in HTMLLines:

    line = str(line).strip()

    if "Grupo" in line:
        grupo = line[7:]
        grupos.append(grupo)
        
        groupCapacity = str(HTMLLines[index + 13]).strip()
        groupStudents = str(HTMLLines[index + 20]).strip()
        capacidades.append(int(groupCapacity))     
        estudiantes.append(int(groupStudents))  
    
    index += 1

print("Grupos encontrados!")
print("Encotrando profesores . . .")

profesores = []

for grupo in grupos:

    customLink = F"http://uis.edu.co/estudiantes/asignaturas_programadas/horario_asignatura.jsp?codigo={codigo}&grupo={grupo}%20&nombre=CUSTOM"
    
    groupInfo = ulib.urlopen(customLink).read()
    groupSoup = bs.BeautifulSoup(groupInfo, "html.parser")
    groupSoup = groupSoup.prettify().split("\n")
    
    profesor = str(groupSoup[75]).strip()
    profesores.append(profesor)


for n in range(len(grupos)):

    print(F"Grupo {grupos[n]} con capacidad de {capacidades[n]} y {estudiantes[n]} matriculados", end=" ")
    print(F"profesor detectado: {profesores[n]}")

    if capacidades[n] <= estudiantes[n]:
        print("LLENO")
    else:
        print() 


os.system("pause")

