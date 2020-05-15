from Asignatura import *
from Horario import *
import Logger as log

# codigos = [22956,22957,22958,22959]
codigos = [22956,22957,22958,22959]
# codigos = [22958]

horario = Horario()

for codigo in codigos:

    try:
        asignatura = Subject(codigo, logging=False)
        asignatura.sort_groups()
        
        
    except InvalidSubjectCode:
        continue

    if asignatura.name == 'FISICA III':
        grupo = asignatura.get_group_by_code('A3A')
    elif asignatura.name == 'ELECTRICIDAD Y ELECTRONICA':
        grupo = asignatura.get_group_by_code('B1')
    elif asignatura.name == 'AUTOMATAS Y LENGUAJES FORMALES':
        grupo = asignatura.get_group_by_code('H2')
    elif asignatura.name == 'BASES DE DATOS I':
        grupo = asignatura.get_group_by_code('B1')
    else:
        log.error_log(f'Asignatura {asignatura.name} no reconocida')
        continue
    
    horario.add_group(grupo)

dif = Subject(20254, logging=False)
print(f'Cantidad de grupos disponibles: {len(dif.groups)}')

compatible_groups = horario.get_compatible_groups(dif)

print(compatible_groups)
print(f'Cantidad de grupos compatibles: {len(compatible_groups)}')

horario.pretty_print()