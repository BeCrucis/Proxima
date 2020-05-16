from Asignatura import *
from Horario import *
import Logger as log

# codigos = [22956,22957,22958,22959]
codigos = [20255,22957,22958,22959]
# codigos = [22958]

horario = Horario()

equations = Subject(20255, False, 'A4')
horario.add_group(equations.groups[0])

physics = Subject(22956, False, 'A4A')
horario.add_group(physics.groups[0])

electricity = Subject(22957, False, 'D1')
horario.add_group(electricity.groups[0])

automats = Subject(22958, False, 'H2')
horario.add_group(automats.groups[0])

databases = Subject(22959, False, 'B1')
horario.add_group(databases.groups[0])

# dif = Subject(22956, logging=False)
# print(f'Cantidad de grupos disponibles: {len(dif.groups)}')

# compatible_groups = horario.get_compatible_groups(dif)

# print(compatible_groups)
# print(f'Cantidad de grupos compatibles: {len(compatible_groups)}')

horario.pretty_print()