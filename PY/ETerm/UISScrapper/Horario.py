from Asignatura import *
import Logger as log

class Horario:

    def __init__(self):
        
        self.days = {}
        self.days['LUNES'] = ['']*24
        self.days['MARTES'] = ['']*24
        self.days['MIERCOLES'] = ['']*24
        self.days['JUEVES'] = ['']*24
        self.days['VIERNES'] = ['']*24
        self.days['SABADO'] = ['']*24

        self.start_hour = 6
        self.finish_hour = 22

        self.teachers = []
        self.subject_info = {}
    
    def add_group(self, group):

        log.course_log(f'Agregando grupo {group.group_code} de {group.subject_name}')
        group_schedule = group.schedule
        temp_days = self.days.copy()
        
        for day in group_schedule:

            for lesson in group_schedule[day]:
                lesson_hours = lesson
                lesson_hour_data = [int(hour.strip()) for hour in lesson_hours.split('-')]
                lesson_start_hour = lesson_hour_data[0]
                lesson_finish_hour = lesson_hour_data[1]
                lesson_duration = lesson_finish_hour - lesson_start_hour

                if not self.check_schedule(day, lesson_start_hour) or not self.check_schedule(day, lesson_finish_hour-1):
                    log.error_log('Grupo no compatible')
                    return False

                temp_days[day][lesson_start_hour:lesson_finish_hour] = [f'{group.subject_code} {group.group_code}']*lesson_duration
        
        self.days = temp_days
        
        for teacher in group.teachers:
            if teacher != 'Sin profesor':
                self.teachers.append(teacher)
        
        self.subject_info[group.subject_name] = group.subject_code

        return True
    
    def check_schedule(self, day, hour):

        day = day.upper()

        if self.days[day][hour]:
            return False
        
        return True

    def get_compatible_groups(self, subject):
        
        if str(subject).isdigit():
            subject = Subject(subject, logging=False)

        log.course_log(f'Detectando horarios compatibles de {subject.name}')
        compatible_groups = []

        for group in subject.groups:

            is_compatible = True
            group_schedule = group.schedule
            
            for day in group_schedule:

                for lesson in group_schedule[day]:
                    lesson_hours = lesson
                    lesson_hour_data = [int(hour.strip()) for hour in lesson_hours.split('-')]
                    lesson_start_hour = lesson_hour_data[0]
                    lesson_finish_hour = lesson_hour_data[1]
                    lesson_duration = lesson_finish_hour - lesson_start_hour

                    if not self.check_schedule(day, lesson_start_hour) or not self.check_schedule(day, lesson_finish_hour-1):
                        is_compatible = False
                        break
            
            if is_compatible:
                compatible_groups.append(group.group_code)
        
        return compatible_groups

    def pretty_print(self):

        print()
        justify_length = 13

        # Lineas separadoras verticales
        print('-'*3, end='')

        for day in self.days:
            print('-'*justify_length , end='')
        print()

        # Dias de la semana
        print('H'.ljust(3), end='')

        for day in self.days:
            print('|' + f'{day}'.center(justify_length-2) + '|' , end='')
        print()

        # Lineas separadoras verticales
        print('-'*3, end='')

        for day in self.days:
            print('-'*justify_length , end='')
        print()

        # Horario
        for hour in range(self.start_hour, self.finish_hour):

            print(f'{hour}'.ljust(3), end='')
            for day in self.days:
                print('|' + f'{self.days[day][hour]}'.center(justify_length-2) + '|', end='')   
            print()
        
        # Lineas separadoras verticales
        print('-'*3, end='')

        for day in self.days:
            print('-'*justify_length , end='')
        print()

        
        print()