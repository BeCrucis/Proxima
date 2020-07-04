#include <iostream>

using namespace std;

struct nodo
{
	int data;
	nodo *sig;
};

class Vector{

    nodo *firstNode, *lastNode;
    int lenght;

    public:

    Vector(){

        this->firstNode = NULL;
        this->lastNode = NULL;
        this->lenght = 0;
    }

    void add(int data){


        nodo *newNode = new nodo();
        newNode->data = data;
        newNode->sig = NULL;

        if(this->firstNode == NULL){

            cout << "Creando lista por primera vez!" << endl;
            cout << "Insertando " << data << " en la posicion" << " [0]" << endl;
            this->firstNode = newNode;
            this->lastNode = newNode;
        }

        else {
            
            cout << "Insertando " << data << " en la posicion" << " ["<<this->lenght<<"]"<<endl;
            this->lastNode->sig = newNode;
            this->lastNode = newNode;
        }

        this->lenght += 1;
    }

    void add(int data, int index){

        if(index > lenght){

            cout << "Indice "<<"["<<index<<"]"<<" invalido, inserte un indice menor al largo de la lista!" << endl;
            return;
        }

        nodo *newNode = new nodo();
        newNode->data = data;
        newNode->sig = NULL;

        if(this->firstNode == NULL){

            cout << "Creando lista por primera vez!" << endl;
            cout << "Insertando " << data << " en la posicion" << " [0]" << endl;
            this->firstNode = newNode;
            this->lastNode = newNode;
        }

        else {

            if (index == 0){

                cout << "Insertando " << data << " en la posicion" << " ["<<index<<"]"<<endl;

                nodo *replaceNode = firstNode;
                newNode->sig = replaceNode;
                this->firstNode = newNode;
                this->lenght += 1;
                return;
            }

            if (index == this->lenght){
                this->add(data);
                return;
            }

            cout << "Insertando " << data << " en la posicion" << " ["<<index<<"]"<<endl;

            nodo *previousNode;
            previousNode = firstNode;

            for (int i = 1; i < index; i++){
                previousNode = previousNode->sig;
            }

            nodo *replaceNode = previousNode->sig;
            previousNode->sig = newNode;
            newNode->sig = replaceNode;
        }

        this->lenght += 1;
    }

    int get(int index){

        if(index >= lenght || index < 0){

            cout << "Indice "<<"["<<index<<"]"<<" invalido, inserte un indice menor al largo de la lista!" << endl;
            return -1;
        }

        nodo *currentNode;
        currentNode = firstNode;

        for (int i = 0; i < index; i++){
            currentNode = currentNode->sig;
        }

        return currentNode->data;
    }

    // Leer vector
    string to_string(){

        string out = "[";
        nodo *currentNode;
        currentNode = this->firstNode;

        for (int i = 0; i < lenght-1; i++){
            out = out + std::to_string(currentNode->data) + ", ";
            currentNode = currentNode->sig;
        }

        out = out + std::to_string(currentNode->data) + "]";

        return out;

    }

};

int main(){

    Vector list;

    for (int i = 1; i <= 10; i++){

        list.add(i*2, i-1);
    }
    
    cout << list.to_string() << endl;

    list.add(1000, 7);

    cout << list.to_string() << endl;

    system("pause");

    delete &list;

    return 0;
}

