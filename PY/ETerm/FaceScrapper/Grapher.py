from igraph import *
from AdjacencyList import AdjacencyList
import Names
import unidecode
import os
import shutil

title = ''' _______  ______    _______  _______  __   __  _______  ______   
|       ||    _ |  |   _   ||       ||  | |  ||       ||    _ |  
|    ___||   | ||  |  |_|  ||    _  ||  |_|  ||    ___||   | ||  
|   | __ |   |_||_ |       ||   |_| ||       ||   |___ |   |_||_ 
|   ||  ||    __  ||       ||    ___||       ||    ___||    __  |
|   |_| ||   |  | ||   _   ||   |    |   _   ||   |___ |   |  | | v0.3
|_______||___|  |_||__| |__||___|    |__| |__||_______||___|  |_| by: Gacrucis
'''
# pylint: disable=E1136
# pylint: disable=no-member
# pylint: disable=not-an-iterable

# CONFIGURACION

# Id de facebook del nodo principal (el que esta en el centro de todo)
principal_vertex_id = 'YURMEL'
# Posicion del archivo que tiene la lista de adyacencia
adjacency_list_path = f'adyacency_{principal_vertex_id}_l6.txt'
# Nombre de la carpeta en donde se van a colocar los grafos
output_dir_name = f'{principal_vertex_id}_graphs'

def main():

    print(title)
    print(f'[INFO] ID del vertice principal: {principal_vertex_id}')
    print(f'[INFO] Nombre de carpeta output: {output_dir_name}')

    print('[INFO] Iniciando importacion de datos')

    adjacency_list = AdjacencyList(adjacency_list_path)

    print(f'[PROCESS] Importando nombres para verificar genero de cuenta . . . ')
    man_names = Names.man_names
    woman_names = Names.woman_names
    print(f'[SUCCESS] {len(man_names)+len(woman_names)} nombres importados!')
    print(f'[SUCCESS] Importacion de datos finalizada')

    print(f'[INFO] Iniciando creacion de grafo')

    graph = Graph()

    print(f'[PROCESS] Introduciendo vertices . . .')
    friend_amount = len(adjacency_list.id_dictionary)
    graph.add_vertices(friend_amount)
    print(f'[SUCCESS] {friend_amount} vertices creados!')

    graph_edges_numbers = {}

    # Agrega los vertices y les da sus atributos
    print(f'[PROCESS] Asignando informacion a vertices . . .')
    for i, friend_id in enumerate(adjacency_list.id_dictionary):

        if i % 10 == 0:
            print(f'[INFO] {friend_amount-i} vertices restantes . . .')

        # Toma el vertice numero i del vertice
        graph_edges_numbers[friend_id] = i
        # Le asigna una id de facebook a dicho vertice
        graph.vs[i]['name'] = friend_id

        # Extrae y procesa el nombre de facebook relacionado a dicha id
        # Para ello se eliminan los espacios sobrantes
        friend_name = adjacency_list.id_dictionary[friend_id].strip()
        # Se quitan los acentos
        friend_name = unidecode.unidecode(friend_name)

        # Verifica el largo del nombre
        temp_label = friend_name
        label_names = temp_label.split(' ')

        # Si tiene muchas palabras, lo acorta a 2
        if len(label_names) > 2:
            temp_label = label_names[:2]
            temp_label = f'{temp_label[0]} {temp_label[1]}'

        # Le asigna un nombre al vertice para mostrar en la imagen
        graph.vs[i]['label'] = temp_label

        # Le asigna un color por defecto al vertice
        temp_color = 'Light Gray'

        # Si el nombre asociado al vertice es de hombre, lo colorea de azul acero
        for name in man_names:
            if name in friend_name:
                temp_color = 'Steel Blue'
                break
    
        # Si el nombre asociado al vertice es de mujer, lo colorea de rosado salmon
        if temp_color != 'blue':
            for name in woman_names:
                if name in friend_name:
                    temp_color = 'Dark Salmon'
                    break

        # Asigna el color y grandeza del vertice
        graph.vs[i]['color'] = temp_color
        graph.vs[i]['size'] = 40
    
    print(f'[SUCCESS] {i+1} vertices procesados!')

    print(f'[PROCESS] Introduciendo aristas . . .')
    # Agrega las aristas
    for host_id in adjacency_list.id_connections:

        # Recorre las conexiones asignadas a cada id de facebook y las convierte a aristas
        for connection_id in adjacency_list.id_connections[host_id]:
            
            graph.add_edges([(host_id, connection_id)])

    print(f'[INFO] {len(graph.es)} aristas creadas')
    print(f'[PROCESS] Eliminando aristas multiples . . .')
    # Elimina las aristas multiples y ciclicas
    graph.simplify()
    print(f'[INFO] {len(graph.es)} aristas resultantes')

    print(f'[PROCESS] Asignando informacion a aristas . . .')
    # Otorga atributos a las aristas
    for vertex in graph.vs:

        connected_edges = vertex.all_edges()
        edge_whiteness = vertex.degree()
        
        edge_color = 'gray'

        if edge_whiteness <= -1:
            edge_color = 'black'
        
        elif edge_whiteness <= 2:
            edge_color = 'dim gray'
        
        elif edge_whiteness <= 3:
            edge_color = 'Web Gray'

        for edge in connected_edges:
            edge['color'] = edge_color
            edge['width'] = 3
    
    print(f'[SUCCESS] Aristas hechas!')

    print(f'[INFO] Iniciando representacion grafica del grafo')
    print(f'[PROCESS] Dibujando grafo resultante . . .')
    # Dibuja el grafo
    
    graph_style = {}
    
    graph_style['bbox'] = (4000, 4000)
    graph_style['margin'] = (200, 200, 200, 200)
    graph_style['vertex_label_dist'] = 1.2
    graph_style['vertex_label_angle'] = 4.7
    graph_style['autocurve'] = True

    print(f'[INFO] Parametros de dibujo')
    for key in graph_style:
        print(f'[INFO] {key} = {graph_style[key]}')

    print(f'[PROCESS] Asignando parametros al vertice principal [{principal_vertex_id}] . . .')
    host_vertex = graph.vs.find(name=principal_vertex_id)
    host_vertex['color'] = 'Black'
    host_vertex['size'] = 100
    print(f'[SUCCESS] Parametros agregados!')

    # plot(graph, **graph_style)

    print(f'[PROCESS] Agregando algoritmos de posicionamiento . . .')
    layout_types = []
    layout_types.append('fr')
    layout_types.append('kk')
    layout_types.append('large')
    print(f'[SUCCESS] {len(layout_types)} algoritmos agregados!')
    
    for layout_type in layout_types:
        print(f'[PROCESS] Dibujando grafo con algoritmo {layout_type} . . .')

        if layout_type == 'fr':
            graph_style['layout'] = graph.layout_fruchterman_reingold(weights=None, niter=10000, seed=None, start_temp=5, minx=None, maxx=None, miny=None, maxy=None, minz=None, maxz=None, grid="nogrid")
        else:
            graph_style['layout'] = graph.layout(layout_type)

        plot(graph,f'graph_{principal_vertex_id}_{layout_type}.png', **graph_style)
        print(f'[SUCCESS] Grafo con algoritmo {layout_type} creado!')
    
    print(f'[SUCCESS] Grafos creados!')
    print(f'[INFO] Iniciando movimiento de grafos a carpeta [{output_dir_name}]')
    
    if not os.path.exists(output_dir_name):
        print(f'[PROCESS] Creando carpeta [{output_dir_name}] . . .')
        os.mkdir(output_dir_name)
        print(f'[SUCCESS] Carpeta [{output_dir_name}] creada!')
    
    print(f'[PROCESS] Moviendo grafos . . .')
    for layout_type in layout_types:

        graph_file_name = f'graph_{principal_vertex_id}_{layout_type}.png'
        print(f'[PROCESS] Moviendo {graph_file_name} . . .')

        if os.path.exists(f'{output_dir_name}\\{graph_file_name}'):
            os.remove(f'{output_dir_name}\\{graph_file_name}')

        shutil.move(f'graph_{principal_vertex_id}_{layout_type}.png', output_dir_name)
        print(f'[SUCCESS] Grafo {graph_file_name} movido a {output_dir_name}!')
    print(f'[SUCCESS] Grafos movidos!')
    print(f'[SUCCESS] Grapher ha terminado exitosamente!')


main()