import networkx as nx
import matplotlib.pyplot as plt

g = nx.Graph()

g.add_node(1)
g.add_node(-1)
nx.draw(g)

g.add_edge(-1,1)
nx.draw(g)
g.add_edge(1,3)
g.add_edges_from([(2,5), (1,3)])

print(nx.info(g))


plt.show()
