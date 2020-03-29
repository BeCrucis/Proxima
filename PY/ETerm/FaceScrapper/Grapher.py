from igraph import *
from AdjacencyList import AdjacencyList
import Names
import unidecode

# pylint: disable=E1136
# pylint: disable=no-member

def main():

    adjacency_list_path = 'adyacencia3.txt'
    principal_vertex_id = 'YURMEL'

    adjacency_list = AdjacencyList(adjacency_list_path)

    man_names = Names.man_names
    woman_names = Names.woman_names

    friend_amount = len(adjacency_list.id_dictionary)

    graph = Graph()
    graph.add_vertices(friend_amount)

    graph_edges_numbers = {}

    # Agrega los vertices y les da sus atributos
    for i, friend_id in enumerate(adjacency_list.id_dictionary):
        graph_edges_numbers[friend_id] = i
        graph.vs[i]['name'] = friend_id

        friend_name = adjacency_list.id_dictionary[friend_id].strip()
        friend_name = unidecode.unidecode(friend_name)

        temp_label = friend_name
        label_names = temp_label.split(' ')

        if len(label_names) > 2:
            temp_label = label_names[:2]
            temp_label = f'{temp_label[0]} {temp_label[1]}'

        graph.vs[i]['label'] = temp_label

        temp_color = 'Light Gray'

        for name in man_names:
            if name in friend_name:
                temp_color = 'Steel Blue'
                break
    
        if temp_color != 'blue':
            for name in woman_names:
                if name in friend_name:
                    temp_color = 'Dark Salmon'
                    break

        graph.vs[i]['color'] = temp_color
        graph.vs[i]['size'] = 40
        graph.vs[i]['order'] = i+1
    

    # Agrega las aristas y le da sus atributos
    for host_id in adjacency_list.id_connections:

        for connection_id in adjacency_list.id_connections[host_id]:

            if host_id != connection_id:
                graph.add_edges([(host_id, connection_id)])
        
        host_vertex = graph.vs.find(name=host_id)

        connected_edges = host_vertex.all_edges()
        edge_whiteness = host_vertex.degree()
        
        edge_color = 'gray'

        if edge_whiteness <= 3:
            edge_color = 'black'
        
        elif edge_whiteness <= 5:
            edge_color = 'dim gray'
        
        elif edge_whiteness <= 8:
            edge_color = 'Web Gray'

        for edge in connected_edges:
            edge['color'] = edge_color
            edge['width'] = 3


    # Dibuja el grafo
    layout_types = ('kk', 'fr', 'grid_fr')
    
    graph_style = {}
    
    graph_style['bbox'] = (4000, 4000)
    graph_style['margin'] = (200, 200, 200, 200)
    graph_style['vertex_label_dist'] = 1.2
    graph_style['vertex_label_angle'] = 4.7

    host_vertex = graph.vs.find(name=principal_vertex_id)
    host_vertex['order'] = 100
    host_vertex['color'] = 'Black'
    host_vertex['size'] = 100
    
    for layout_type in layout_types:
        graph_style['layout'] = graph.layout(layout_type)
        plot(graph,f'graph_{principal_vertex_id}_{layout_type}.png', **graph_style)
        # plot(graph, **graph_style)


main()