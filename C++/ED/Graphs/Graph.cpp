#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>

using namespace std;

struct Node {
    public:
    int label;
    vector<Node*> contiguousNodes;

    void connectNode(Node *newNode){

        contiguousNodes.push_back(newNode);
    }

};

struct Edge {
    public:
    int weight;
    vector<Node*> connectingNodes;

    void connectEdge(Node *newNode){

        if(connectingNodes.size() > 2){
            cout << "An edge can only connect up to 2 nodes!" << endl;
        }

        connectingNodes.push_back(newNode);
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

        Node *newNode = new Node();
        newNode->label = label;

        this->nodes.push_back(newNode);
    }
};

int main(){

    cout << "Nodos!" << endl;
    
    Graph grafo = Graph();

    grafo.addNode(4);
    system("pause");
}