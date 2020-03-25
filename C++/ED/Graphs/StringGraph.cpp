#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Node {
    public:
    string label;
    float distance;
    Node *predecesor;
    vector<Node*> contiguousNodes;

    void connectNode(Node *newNode){

        if(getContiguousNode(newNode->label) == NULL){
            contiguousNodes.push_back(newNode);
        }
    }

    void disconnectNode(string label){

        for(int i = 0; i < contiguousNodes.size(); i++){
            Node *currentNode = contiguousNodes.at(i);

            if(currentNode->label == label){
                contiguousNodes.erase(contiguousNodes.begin()+i);
                return;
            }
        }
    }

    Node* getContiguousNode(string label){
        for(Node* node : contiguousNodes){
            if(node->label == label){
                return node;
            }
        }

        return NULL;
    }

};

struct Edge {
    public:
    string label;
    double weight;
    Node* sourceNode;
    Node* destinationNode;

    Edge(Node *sourceNode, Node *destinationNode, double weight){

        label = "[" + sourceNode->label + "]→[" + destinationNode->label + "]";
        this->weight = weight;
        this->sourceNode = sourceNode;
        this->destinationNode = destinationNode;

        sourceNode->connectNode(destinationNode);
    }

};

class Graph {

    private:
    vector<Node*> nodes;
    vector<Edge*> edges;

    public:

    ~Graph(){
        for(int i = 0; i < nodes.size(); i++){
            this->removeNode(nodes.at(i)->label);
        }
    }

    void addNode(string label){

        if(getNode(label) != NULL){
            cout << "El nodo ya existe!" << endl;
            return;
        }

        Node *newNode = new Node();
        newNode->label = label;

        this->nodes.push_back(newNode);
    }

    void removeNode(string label){

        Node *target = getNode(label);

        if(target == NULL){
            cout << "El nodo no existe!" << endl;
            return;
        }

        for(int i = 0; i < edges.size(); i++){

            Edge *edge = edges.at(i);

            if(edge->sourceNode == target || edge->destinationNode == target){
                edges.erase(edges.begin()+i);
            }
        }

        for(int i = 0; i < nodes.size(); i++){

            Node *currentNode = nodes.at(i);
            vector<Node*> *adjacentNodes = &currentNode->contiguousNodes;

            for(int j = 0; j < adjacentNodes->size(); j++){

                Node* node = adjacentNodes->at(j);

                if(target == node){
                    adjacentNodes->erase(adjacentNodes->begin()+j);
                    break;
                }
            }
        }
    }

    void connectNodes(Node *sourceNode, Node *destinationNode, double weight){

        Edge *newEdge = new Edge(sourceNode, destinationNode, weight);
        sourceNode->connectNode(destinationNode);

        edges.push_back(newEdge);
    }

    void disconnectNodes(Node *sourceNode, Node *destinationNode){

        // Busca la aristas a borrar
        for(int i = 0; i < edges.size(); i++){

            Edge *edge = edges.at(i);

            if(edge->sourceNode == sourceNode && edge->destinationNode == destinationNode){
                
                edges.erase(edges.begin()+i);
                sourceNode->disconnectNode(destinationNode->label);
            }
        }
    }

    Node* getNode(string label){
        
        for(Node* node: nodes){
            if (node->label == label){
                return node;
            }
        }
        // cout << "Nodo no encontrado" << endl;
        return NULL;
    }

    vector<Edge*> getEdges(){
        return edges;
    }

    vector<Node*> getNodes(){
        return nodes;
    }

    void getShortestPath(Node *sourceNode, Node *destinationNode){

        // Obtiene el camino mas corto por el algoritmo de Bellman-Ford
        // Empieza asignando la distancia de todos los nodos como infinita
        // Menos la del nodo del que se parte, que sera 0

        for(int i = 0; i < nodes.size(); i++){
            nodes.at(i)->distance = numeric_limits<double>::infinity();
            nodes.at(i)->predecesor = NULL;
        }

        sourceNode->distance = 0;

        // Relajacion de aristas
        for(int i = 0; i < edges.size()-1; i++){

            for(int j = 0; j < edges.size(); j++){
                
                Edge* edge = edges.at(j);
                double sourceDistance = edge->sourceNode->distance;
                double destinationDistance = edge->destinationNode->distance;
                double edgeDistance = edge->weight;

                if(sourceDistance + edgeDistance < destinationDistance){
                    edge->destinationNode->distance = sourceDistance + edgeDistance;
                    edge->destinationNode->predecesor = edge->sourceNode;
                }
            }

        }

        // Deteccion de ciclos negativos
        bool hasNegativeCycle = false;
        Node* negativeCycleNode;

        for(int i = 0; i < edges.size()-1; i++){

            for(int j = 0; j < edges.size(); j++){
                
                Edge* edge = edges.at(j);
                double sourceDistance = edge->sourceNode->distance;
                double destinationDistance = edge->destinationNode->distance;
                double edgeDistance = edge->weight;

                // Si detecta un ciclo negativo, guarda el nodo causante
                if(sourceDistance + edgeDistance < destinationDistance){
                    edge->destinationNode->distance = sourceDistance + edgeDistance;
                    edge->destinationNode->predecesor = edge->sourceNode;

                    if(!hasNegativeCycle){
                        // Se cambia el booleano para avisar que hay un
                        // ciclo negativo
                        hasNegativeCycle = true;
                        negativeCycleNode = edge->sourceNode;
                    } 
                }
            }
        }

        // Muestra el output del programa
        cout << endl << "Imprimiendo resultados: " << endl;
        
        if(hasNegativeCycle){
            // Si tiene un ciclo negativo
            cout << "El grafo tiene un ciclo negativo, no hay camino mas corto!" << endl;
            cout << "Ciclo negativo: " << endl;

            Node *currentNode = negativeCycleNode;
            vector<Node*> negativeCycle;

            // Almacena el ciclo negativo en un vector
            do {
                    
                negativeCycle.push_back(currentNode);
                currentNode = currentNode->predecesor;

            } while(currentNode != negativeCycleNode);

            // Imprime el vector

            cout << "[";
            
            for(int i = 0; i < negativeCycle.size(); i++){
                cout << negativeCycle.at(i)->label<< " → ";
            }
            cout << currentNode->label <<" → "<< currentNode->predecesor->label << " . . . ]"<< endl;         
            
        } else if(destinationNode->distance != numeric_limits<double>::infinity()){
            
            // Si no tiene un ciclo negativo y tiene un camino mas corto

            Node *currentNode = destinationNode;
            vector<Node*> shortestPath;
        
            do {
                // Almacena el camino mas corto en un vector
                shortestPath.insert(shortestPath.begin(), currentNode);
                currentNode = currentNode->predecesor;

            } while (currentNode->predecesor != NULL);

            // Imprime el vector
            cout << "Camino mas corto: " << endl;
            
            cout << "[" << currentNode->label << " → ";
            
            for(int i = 0; i < shortestPath.size()-1; i++){
                cout << shortestPath.at(i)->label<< " → ";
            }
            cout << destinationNode->label << "]"<< endl;

            cout << "Imprimiendo distancias mas cortas: " << endl;

            for(Node *node : nodes){
                cout <<"["<<sourceNode->label<<"→"<<node->label<<"] : "<<node->distance<< endl;
            }
        
        } else {
            // Si no tiene un ciclo negativo y no hay camino hacia el nodo destino
            
            cout << "No existe camino hacia el destino!" << endl;
        }        
    }
};

void demo_uis(){
    Graph graph = Graph();

    

}

void imprimirMenu(){

    cout << "  _   _           _             _ " << endl;
    cout << " | \\ | |         | |           | |" << endl;
    cout << " |  \\| | ___   __| | ___  ___  | |" << endl;
    cout << " | . ` |/ _ \\ / _` |/ _ \\/ __| | |" << endl;
    cout << " | |\\  | (_) | (_| | (_) \\__ \\ |_|" << endl;
    cout << " |_| \\_|\\___/ \\__,_|\\___/|___/ (_)" << endl;
    cout << "                                  " << endl;

    cout << "1 → Agregar nodo al grafo" << endl;
    cout << "2 → Eliminar nodo del grafo" << endl;
    cout << "3 → Conectar nodos" << endl;
    cout << "4 → Desconectar nodos" << endl;
    cout << "5 → Encontrar camino mas corto entre nodos" << endl;
    cout << "6 → Imprimir lista de adyacencia" << endl; 
    cout << "7 → Imprimir lista de incidencia" << endl;  
    cout << "8 → Colocar nodos para demostracion" << endl; 
    cout << "99 → Salir" << endl; 

}

int main(){

    system("chcp 65001");
    system("cls");

    int option = 0;
    Graph graph = Graph();

    // graph.connectNodes(graph.getNode(3), graph.getNode(1), -10);

    while(option != 99){
        imprimirMenu();
        cout << endl << "Inserte su opcion: ";
        cin >> option;

        system("cls");

        if(option == 1){
            string label;

            cout << "Inserte el numero de nodo: ";
            cin >> label;

            graph.addNode(label);

        } else if(option == 2){
            string label;

            cout << "Inserte el numero de nodo: ";
            cin >> label;

            graph.removeNode(label);

        } else if(option == 3){
            int input;
            string label;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccion de nodos" << endl << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << endl << "Seleccione el nodo de origen: ";
            cin >> label;
            cout << endl;

            sourceNode = graph.getNode(label);

            system("cls");
            cout << "Seleccion de nodos" << endl << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << endl << "Seleccione el nodo de destino: ";
            cin >> label;
            cout << endl;

            destinationNode = graph.getNode(label);

            cout << "Inserte la distancia entre nodos: ";
            cin >> input;
            
            graph.connectNodes(sourceNode, destinationNode, input);
            
        } else if(option == 4){
            
            int input;
            string label;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccione los nodos a desconectar: " << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de origen: ";
            cin >> label;
            cout << endl;

            sourceNode = graph.getNode(label);

            system("cls");

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de destino: ";
            cin >> label;
            cout << endl;

            destinationNode = graph.getNode(label);
            
            graph.disconnectNodes(sourceNode, destinationNode);

        } else if(option == 5){

            int input;
            string label;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccione los nodos a conectar: " << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de origen: ";
            cin >> label;
            cout << endl;

            sourceNode = graph.getNode(label);

            system("cls");

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de destino: ";
            cin >> label;
            cout << endl;

            destinationNode = graph.getNode(label);
            
            graph.getShortestPath(sourceNode, destinationNode);

        } else if(option == 6){

            vector<Node*> nodes = graph.getNodes();
            Node *currentNode, *currentContiguousNode;

            for(int i = 0; i < nodes.size(); i++){

                currentNode = nodes.at(i);
                cout << "["<<currentNode->label<<"] → ";
                

                for(int j = 0; j < currentNode->contiguousNodes.size(); j++){
                    
                    currentContiguousNode = currentNode->contiguousNodes.at(j);

                    cout << "["<<currentContiguousNode->label<<"] → ";
                }

                cout << "[/]" << endl;
                
            }
        } else if(option == 7){

            vector<Edge*> edges = graph.getEdges();

            cout << "[";
            
            for(int i = 0; i < edges.size(); i++){
                Edge* currentEdge = edges.at(i);

                cout << " " <<currentEdge->label<<" ";
                
            }

            cout << "]" << endl;
        } else if(option == 8){

            graph.addNode("9A");
            graph.addNode("10A");
            graph.addNode("11A");
            graph.addNode("9C");
            graph.addNode("10B");
            graph.addNode("11B");
            graph.addNode("11C");
            graph.addNode("27");
            graph.addNode("SRC");
            graph.addNode("GOAL");

            graph.connectNodes(graph.getNode("SRC"), graph.getNode("10A"), 8);
            graph.connectNodes(graph.getNode("9A"), graph.getNode("9C"), 8);
            graph.connectNodes(graph.getNode("9A"), graph.getNode("10A"), 100);
            graph.connectNodes(graph.getNode("10A"), graph.getNode("SRC"), 5);
            graph.connectNodes(graph.getNode("10A"), graph.getNode("9A"), 8);
            graph.connectNodes(graph.getNode("10A"), graph.getNode("11A"), 5);
            graph.connectNodes(graph.getNode("10A"), graph.getNode("10B"), -5); 
            graph.connectNodes(graph.getNode("11A"), graph.getNode("10A"), 5);
            graph.connectNodes(graph.getNode("11A"), graph.getNode("11B"), 10);
            graph.connectNodes(graph.getNode("9C"), graph.getNode("9A"), 100);
            graph.connectNodes(graph.getNode("9C"), graph.getNode("10B"), 8);
            graph.connectNodes(graph.getNode("9C"), graph.getNode("GOAL"), 20);
            graph.connectNodes(graph.getNode("10B"), graph.getNode("10A"), 5);
            graph.connectNodes(graph.getNode("10B"), graph.getNode("9C"), 8);
            graph.connectNodes(graph.getNode("10B"), graph.getNode("11B"), 8);
            graph.connectNodes(graph.getNode("11B"), graph.getNode("11A"), 5);
            graph.connectNodes(graph.getNode("11B"), graph.getNode("10B"), 8);
            graph.connectNodes(graph.getNode("11B"), graph.getNode("11C"), 5);
            graph.connectNodes(graph.getNode("11C"), graph.getNode("11B"), 4);
            graph.connectNodes(graph.getNode("11C"), graph.getNode("27"), 8);
            graph.connectNodes(graph.getNode("GOAL"), graph.getNode("9C"), 10);
            graph.connectNodes(graph.getNode("GOAL"), graph.getNode("27"), 5);
            graph.connectNodes(graph.getNode("27"), graph.getNode("11C"), 5);
            graph.connectNodes(graph.getNode("27"), graph.getNode("GOAL"), 5);

            // Imprime la lista de incidencia
            cout << "Nodos colocados, grafo actual (Lista de incidencia): " << endl;
            
            vector<Edge*> edges = graph.getEdges();

            cout << "[";
            
            for(int i = 0; i < edges.size(); i++){
                Edge* currentEdge = edges.at(i);

                cout << " " <<currentEdge->label<<" ";
                
            }

            cout << "]" << endl;
        }

        system("pause");
    }
}