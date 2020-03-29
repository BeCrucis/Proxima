class AdjacencyList:

    def __init__(self, path):

        raw_data = []
        with open(path, 'r') as f:
            raw_data = f.read().splitlines()
        
        self.id_dictionary = {}
        self.id_connections = {}

        for line in raw_data:
            current_connections = {}

            temp = line.split('[')
            host_name = temp[1].split(']')[0]
            host_id = temp[2].split(']')[0]

            self.id_dictionary[host_id] = host_name

            line_raw_connections = line.split('{')[-1][:-1] 
            line_connections = line_raw_connections.replace('\'', '').split(',')
            line_connections = [line.strip() for line in line_connections]

            self.id_connections[host_id] = []

            for connection in line_connections:
                connection_elements = connection.split(':')
                connection_id = connection_elements[0]
                connection_name = connection_elements[1]
                self.id_dictionary[connection_id] = connection_name

                self.id_connections[host_id].append(connection_id)
                



        

            