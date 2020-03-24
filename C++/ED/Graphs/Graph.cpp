#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Node {
    public:
    int label;
    float distance;
    Node *predecesor;
    vector<Node*> contiguousNodes;

    void connectNode(Node *newNode){

        if(getContiguousNode(newNode->label) == NULL){
            contiguousNodes.push_back(newNode);
        }
    }

    void disconnectNode(int label){

        for(int i = 0; i < contiguousNodes.size(); i++){
            Node *currentNode = contiguousNodes.at(i);

            if(currentNode->label == label){
                contiguousNodes.erase(contiguousNodes.begin()+i);
                return;
            }
        }
    }

    Node* getContiguousNode(int label){
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

        label = "[" + to_string(sourceNode->label) + "]->[" + to_string(destinationNode->label) + "]";
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

    void addNode(int label){

        if(getNode(label) != NULL){
            cout << "El nodo ya existe!" << endl;
            return;
        }

        Node *newNode = new Node();
        newNode->label = label;

        this->nodes.push_back(newNode);
    }

    void removeNode(int label){

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

    Node* getNode(int label){
        
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
                    
                negativeCycle.insert(negativeCycle.begin(), currentNode);
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
            
            cout << "[";
            
            for(int i = 0; i < shortestPath.size(); i++){
                cout << shortestPath.at(i)->label<< " → ";
            }
            cout << currentNode->label << "]"<< endl;

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

void demo1(){
    Graph graph = Graph();

    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);

    graph.connectNodes(graph.getNode(1), graph.getNode(2), 6);
    graph.connectNodes(graph.getNode(1), graph.getNode(3), 5);
    graph.connectNodes(graph.getNode(1), graph.getNode(4), 5);
    graph.connectNodes(graph.getNode(2), graph.getNode(5), -1);
    graph.connectNodes(graph.getNode(2), graph.getNode(1), -1);
    graph.connectNodes(graph.getNode(3), graph.getNode(5), 1);
    graph.connectNodes(graph.getNode(4), graph.getNode(3), -2);
    graph.connectNodes(graph.getNode(4), graph.getNode(6), -1);
    graph.connectNodes(graph.getNode(5), graph.getNode(7), 3);
    graph.connectNodes(graph.getNode(6), graph.getNode(7), 3);

    graph.getShortestPath(graph.getNode(1), graph.getNode(7));
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
    cout << "99 → Salir" << endl; 

}

int main(){

    system("chcp 65001");
    system("cls");

    int option = 0;
    Graph graph = Graph();

    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);

    graph.connectNodes(graph.getNode(1), graph.getNode(2), 6);
    graph.connectNodes(graph.getNode(1), graph.getNode(3), 5);
    graph.connectNodes(graph.getNode(1), graph.getNode(4), 5);
    graph.connectNodes(graph.getNode(2), graph.getNode(5), -1);
    graph.connectNodes(graph.getNode(2), graph.getNode(1), -1);
    graph.connectNodes(graph.getNode(3), graph.getNode(5), 1);
    graph.connectNodes(graph.getNode(4), graph.getNode(3), -2);
    graph.connectNodes(graph.getNode(4), graph.getNode(6), -1);
    graph.connectNodes(graph.getNode(5), graph.getNode(7), 3);
    graph.connectNodes(graph.getNode(6), graph.getNode(7), 3);

    while(option != 99){
        imprimirMenu();
        cout << endl << "Inserte su opcion: ";
        cin >> option;

        system("cls");

        if(option == 1){
            int label;

            cout << "Inserte el numero de nodo: ";
            cin >> label;

            graph.addNode(label);

        } else if(option == 2){
            int label;

            cout << "Inserte el numero de nodo: ";
            cin >> label;

            graph.removeNode(label);

        } else if(option == 3){
            int input;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccion de nodos" << endl << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << endl << "Seleccione el nodo de origen: ";
            cin >> input;
            cout << endl;

            sourceNode = graph.getNode(input);

            system("cls");
            cout << "Seleccion de nodos" << endl << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << endl << "Seleccione el nodo de destino: ";
            cin >> input;
            cout << endl;

            destinationNode = graph.getNode(input);

            cout << "Inserte la distancia entre nodos: ";
            cin >> input;
            
            graph.connectNodes(sourceNode, destinationNode, input);
            
        } else if(option == 4){
            
            int input;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccione los nodos a desconectar: " << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de origen: ";
            cin >> input;
            cout << endl;

            sourceNode = graph.getNode(input);

            system("cls");

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de destino: ";
            cin >> input;
            cout << endl;

            destinationNode = graph.getNode(input);
            
            graph.disconnectNodes(sourceNode, destinationNode);

        } else if(option == 5){

            int input;

            vector<Node*> nodes = graph.getNodes();
            Node *sourceNode, *destinationNode;

            cout << "Seleccione los nodos a conectar: " << endl;

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de origen: ";
            cin >> input;
            cout << endl;

            sourceNode = graph.getNode(input);

            system("cls");

            for(int i = 0; i < nodes.size(); i++){
                cout <<"Nodo → "<<nodes.at(i)->label<< endl;
            }

            cout << "Seleccione el nodo de destino: ";
            cin >> input;
            cout << endl;

            destinationNode = graph.getNode(input);
            
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
        }

        system("pause");
    }
    
    
    
    demo1();

    system("pause");
}