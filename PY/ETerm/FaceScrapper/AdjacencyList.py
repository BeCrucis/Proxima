import os
import sys

class AdjacencyList:

    def __init__(self, path):

        raw_data = []

        print('[INFO] Iniciando importacion de lista de adyacencia')
        print(f'[INFO] Direccion de lista de adyacencia: {os.path.abspath(path)}')

        try:
            print(f'[PROCESS] Importando datos usando UTF-8 . . .')
            with open(path, 'r', encoding='utf-8') as f:
                raw_data = f.read().splitlines()
        
        except:
            print(f'[ERROR] Importacion fallida, intentando codificacion por defecto . . .')
            with open(path, 'r') as f:
                raw_data = f.read().splitlines()
        
        print(f'[SUCCESS] {len(raw_data)} vertices importados!')
        print('[INFO] Iniciando parsing de datos . . .')
        
        self.id_dictionary = {}
        self.id_connections = {}

        for line in raw_data:
            current_connections = {}

            temp = line.split('[')
            host_id = temp[1].split(']')[0]
            host_name = temp[2].split(']')[0]
            
            line_raw_connections = line.split('{')[-1][:-1] 
            line_connections = line_raw_connections.replace('\'', '').split(',')

            line_connections = [line.strip() for line in line_connections]
            self.id_dictionary[host_id] = host_name
            # print(f'[INFO] ID {host_id} agregada al diccionario de nombres . . .')

            self.id_connections[host_id] = []

            # if len(line_connections) < 4:
            #     print(f'Amigo {host_name} saltado por falta de conexiones')
            #     continue

            for connection in line_connections:

                if not connection:
                    continue

                connection_elements = connection.split(':')
                connection_id = connection_elements[0]
                connection_name = connection_elements[1]

                self.id_dictionary[connection_id] = connection_name
                # print(f'[INFO] ID {connection_id} agregada al diccionario de nombres . . .')

                self.id_connections[host_id].append(connection_id)
                # print(f'[INFO] ID {connection_id} agregado como conexion de {host_id} . . .')
        
        print(f'[SUCCESS] Datos procesados!')