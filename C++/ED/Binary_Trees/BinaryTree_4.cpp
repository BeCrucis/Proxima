#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class NodoArbol {

    public:
    int info;
    NodoArbol *der, *izq;

    NodoArbol(){
        info = 0;
        izq = NULL;
        der = NULL;
    }

    NodoArbol(int dato){
        info = dato;
        izq = NULL;
        der = NULL;
    }
};

class ABB{

    private:
    NodoArbol *raiz;

    public:

    ABB(){
        raiz = NULL;
    }

    ~ABB(){
        cout << "Entro al destructor" << endl;
        borrarNodos(raiz);
        cout << "Salgo del destructor" << endl;  
    }

    void borrarNodos(NodoArbol *raiz){
        if(raiz != NULL){
            // Borra datos en inorden
            NodoArbol *temp = raiz;

            borrarNodos(temp->izq);
            delete raiz;
            borrarNodos(temp->der);

            cout << "Destructor de "<<raiz->info<< endl;
            delete temp;            
        }
    }

    void insertar(){
        NodoArbol *nuevo, *aux2, *aux3;

        nuevo = new NodoArbol();
        
        aux2 = raiz;
        aux3 = NULL;

        cout << "Entre el valor del nodo a insertar: ";
        cin >> nuevo->info;

        while (aux2 != NULL){
            aux3 = aux2;
            if(nuevo->info > aux2->info){
                aux2 = aux2->der;
            } else  if (nuevo->info == aux2->info){
                cout << "El nodo a insertar ya existe!"  << endl;
                return;
            } else {
                aux2 = aux2->izq;
            }
        }

        if(aux3 == NULL){
            // Si el arbol esta vacio
            raiz = nuevo;
        } else {
            if(nuevo->info >= aux3->info){
                aux3->der = nuevo;
            } else {
                aux3->izq = nuevo;
            }
        }
                
    }

    NodoArbol *obtenerRaiz(){
        return raiz;
    }

    void despliega(NodoArbol *raiz){
        
        if (raiz != NULL){
            despliega(raiz->izq);
            cout <<raiz->info<< endl;
            despliega(raiz->der);            
        }
    }

    void eliminarValor(int valor){

        NodoArbol *objetivo, *padreObjetivo, *temp;
        bool b;

        //Inicio de busqueda del nodo a eliminar

        if(raiz != NULL){
            objetivo = raiz;
            padreObjetivo = NULL;

            while(objetivo->info != valor){
                padreObjetivo = objetivo;

                if(valor < objetivo->info){
                    objetivo = objetivo->izq;
                } else {
                    objetivo = objetivo->der;
                }

                if(objetivo==NULL){
                    cout << "El nodo a eliminar no existe" << endl;
                    break;
                }
            }
        } else {
            cout << "El arbol no contiene nodos" << endl;
            objetivo = NULL;
        }

        // Fin de la busqueda del nodo a eliminar
        // En objetivo queda la direccion del nodo a eliminar
        // En padreObjetivo queda la direccion del nodo padre del nodo a eliminar

        if(objetivo != NULL){
            // Cuando no tiene hijos
            temp = objetivo;
            if((objetivo->izq == NULL) && (objetivo->der==NULL)){
                if(padreObjetivo != NULL){
                    if(objetivo->info > padreObjetivo->info){
                        padreObjetivo->der = NULL;
                    } else {
                        padreObjetivo->izq = NULL;
                    }
                } else {
                    raiz = NULL;
                }
            } else {
                
                if((objetivo->izq != NULL) && (objetivo->der != NULL)){
                    // Cuando tiene dos hijos
                    padreObjetivo = objetivo; // Con el predecesor
                    temp = objetivo->izq;
                    b = true;

                    while(temp->der != NULL){
                        padreObjetivo = temp;
                        temp = temp->der;
                        b = false;
                    }

                    objetivo->info = temp->info;

                    if(b == true){
                        objetivo->izq = temp->izq;
                    } else {
                        if(temp->izq != NULL){
                            padreObjetivo->der = temp->izq;
                        } else {
                            padreObjetivo->der = NULL;
                        }
                    }
                } else {
                    //Cuando tiene solo un hijo
                    if(objetivo->izq == NULL){
                        if(padreObjetivo != NULL){
                                padreObjetivo->izq = objetivo->der;
                            if(objetivo->info < padreObjetivo->info){
                            } else {
                                padreObjetivo->der = objetivo->der;
                            }
                        } else {
                            raiz = objetivo->der;
                        }
                    } else {
                        if(padreObjetivo != NULL){
                            if(objetivo->info < padreObjetivo->info){
                                padreObjetivo->izq = objetivo->izq;
                            } else {
                                padreObjetivo->der = objetivo->izq;
                            }
                        } else {
                            raiz = objetivo->izq;
                        }
                    }
                }
            }

            delete objetivo;
        } 
    }
};

int main(){

    NodoArbol *raiz;
    char resp;
    int valor;
    ABB n;

    do {
        n.insertar();
        cout << "Desea crear otro nodo? S/N: ";
        cin >> resp;
        cout << endl;
        
        resp = tolower(resp);
    } while(resp != 'n');

    cout << "Los nodos del arbol son: " << endl;
    raiz = n.obtenerRaiz();
    n.despliega(raiz);

    do {
        cout << "Entre el valor del nodo a eliminar: ";
        cin >> valor;
        n.eliminarValor(valor);
        cout << endl;
        
        cout << "Los nodos del arbol (Inorden) son: " << endl;
        raiz = n.obtenerRaiz();
        n.despliega(raiz);
        
        cout << "Desea eliminar otro nodo? S/N: ";
        cin >> resp;
        cout << endl;
        
        resp = tolower(resp);
    } while(resp != 'n');
}