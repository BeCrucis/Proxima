#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    public:
    int label;
    float distance;
    Node *predecesor;
    vector<Node*> contiguousNodes;

    void connectNode(Node *newNode){

        if(getNode(newNode->label) != NULL){
            contiguousNodes.push_back(newNode);
        }
    }

    Node* getNode(int label){
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

    Graph(){
    
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

    void connectNode(Node *sourceNode, Node *destinationNode, double weight){

        Edge *newEdge = new Edge(sourceNode, destinationNode, weight);

        edges.push_back(newEdge);
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

    void getShortestPath(Node *firstNode, Node *secondNode){

        // Empieza asignando la distancia de todos los nodos como infinita
        // Menos la del nodo del que se parte, que sera 0

        for(int i = 0; i < nodes.size(); i++){
            nodes.at(i)->distance = numeric_limits<double>::infinity();
            nodes.at(i)->predecesor = NULL;
        }

        firstNode->distance = 0;

        // Relaja las aristas

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

        for(Node *node : nodes){
            cout <<"["<<node->label<<"] : "<<node->distance<< endl;
        }

        cout << endl << "Imprimiendo camino mas corto: " << endl;
        
        Node *currentNode = secondNode;
        
        do {
            cout << currentNode->label << "<-";
            currentNode = currentNode->predecesor;

        } while (currentNode->predecesor != NULL);

        cout << currentNode->label << endl;
        
    }
};

int main(){

    cout << "Nodos!" << endl;
    
    Graph grafo = Graph();

    grafo.addNode(1);
    grafo.addNode(2);
    grafo.addNode(3);
    grafo.addNode(4);
    grafo.addNode(5);
    grafo.addNode(6);
    grafo.addNode(7);

    grafo.connectNode(grafo.getNode(1), grafo.getNode(2), 6);
    grafo.connectNode(grafo.getNode(1), grafo.getNode(3), 5);
    grafo.connectNode(grafo.getNode(1), grafo.getNode(4), 5);
    grafo.connectNode(grafo.getNode(2), grafo.getNode(5), -1);
    grafo.connectNode(grafo.getNode(3), grafo.getNode(5), 1);
    grafo.connectNode(grafo.getNode(4), grafo.getNode(3), -2);
    grafo.connectNode(grafo.getNode(4), grafo.getNode(6), -1);
    grafo.connectNode(grafo.getNode(5), grafo.getNode(7), 3);
    grafo.connectNode(grafo.getNode(6), grafo.getNode(7), 3);

    grafo.getShortestPath(grafo.getNode(1), grafo.getNode(7));
    system("pause");
}