class AdjacencyList:

    def __init__(self, path):

        raw_data = []
        with open(path, 'r') as f:
            raw_data = f.read().splitlines()
        
        self.id_dictionary = {}
        self.id_connections = {}

        for line in raw_data:
            temp = line.split('[')[2]
            raw_id = temp.split(']')[1]
            raw_name = temp.split(']')[0]
            a = 1