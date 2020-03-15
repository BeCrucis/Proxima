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

            borrarNodos(raiz->der);  
            borrarNodos(raiz->izq);

            cout << "Destructor de "<<raiz->info<< endl;
            delete raiz;          
        }
    }

    void insertarValor(int valor){
        NodoArbol *nuevo, *explorador, *padreNuevo;

        nuevo = new NodoArbol();
        nuevo->info = valor;
        
        explorador = raiz;
        padreNuevo = NULL;

        while (explorador != NULL){

            padreNuevo = explorador;

            if(nuevo->info == explorador->info){
                cout << "El nodo a insertar ya existe!"  << endl;
                return;
            } else  if (nuevo->info > explorador->info){
                explorador = explorador->der;
            } else {
                explorador = explorador->izq;
            }
        }

        if(padreNuevo == NULL){
            // Si el arbol esta vacio
            raiz = nuevo;
        } else {
            if(nuevo->info >= padreNuevo->info){
                padreNuevo->der = nuevo;
            } else {
                padreNuevo->izq = nuevo;
            }
        }
                
    }

    NodoArbol *obtenerRaiz(){
        return raiz;
    }

    void desplegarInorden(NodoArbol *raiz){
        
        if (raiz != NULL){
            desplegarInorden(raiz->izq);
            cout <<raiz->info<< endl;
            desplegarInorden(raiz->der);            
        }
    }

    bool desplegarNivel(NodoArbol *raiz, int nivel){

        if (raiz == NULL){
            return false;
        }

        if (nivel == 1){
            cout << raiz->info;
            return true;
        }

        bool izq = desplegarNivel(raiz->izq, nivel - 1);
        bool der = desplegarNivel(raiz->der, nivel - 1);

        return izq || der;
    }

    void desplegarAmplitud(NodoArbol *raiz){
        int nivel = 1;

        while (desplegarNivel(raiz, nivel)){
            cout << "\n";
            nivel++;
        }
        
        cout << endl;
    }

    void desplegarNodo(string prefijo, NodoArbol* raiz, bool esIzquierdo){
        if( raiz == NULL ){
            return;
        }

        cout << prefijo;

        cout << (esIzquierdo ? "├──" : "└──" );
        
        cout << raiz->info << endl;

        desplegarNodo( prefijo + (esIzquierdo ? "│   " : "    "), raiz->izq, true);
        desplegarNodo( prefijo + (esIzquierdo ? "│   " : "    "), raiz->der, false);
    }

    void desplegarEstructura(){
        desplegarNodo("", raiz, false);
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

        if(objetivo == NULL){
            return;
        }

        if(objetivo->der == NULL && objetivo->izq == NULL){
            // Nodo sin hijos

            if(padreObjetivo == NULL){
                raiz = NULL;
            } else if (padreObjetivo->info > objetivo->info){
                padreObjetivo->izq = NULL;
            } else {
                padreObjetivo->der = NULL;
            }

            delete objetivo; 

        } else if (objetivo->der != NULL && objetivo->izq != NULL){
            // Nodo con dos hijos

            // Busca un sucesor
            NodoArbol *sucesor = objetivo->der;
            NodoArbol *padreSucesor = objetivo;

            while(sucesor->izq != NULL){
                padreSucesor = sucesor;
                sucesor = sucesor->izq;
            }

            //Reemplaza los datos del objetivo por los datos del sucesor
            objetivo->info = sucesor->info;

            // Arregla el arbol para quitar el sucesor de su posicion anterior
            // y relocar los hijos del sucesor

            NodoArbol *huerfanoSucesor = sucesor->der;

            if (padreSucesor != objetivo){
                padreSucesor->izq = huerfanoSucesor;
            } else {
                objetivo->der = huerfanoSucesor;
            }

            delete sucesor;

        } else {
            //Nodo con un hijo

            // Busca el hijo del objetivo
            NodoArbol *hijoObjetivo;

            if(objetivo->der != NULL){
                hijoObjetivo = objetivo->der;
            } else {
                hijoObjetivo = objetivo->izq;
            }

            // Reloca los hijos de objetivo

            if(padreObjetivo == NULL){
                raiz = hijoObjetivo;
            } else if(padreObjetivo->info > objetivo->info){
                padreObjetivo->izq = hijoObjetivo;
            } else {
                padreObjetivo->der = hijoObjetivo;
            }

            delete objetivo;
        }
    }

};

int main(){

    system("chcp 65001");
    system("cls");

    NodoArbol *raiz;
    string valor;
    int valorNumerico;
    ABB arbol;
    char *end;

    cout << "Arbol binario!" << endl;
    cout << "Para dejar de insertar datos, colocar un dato no numerico" << endl << endl;

    bool haInsertadoNumero = true;

    while(haInsertadoNumero){

        cout << "Inserte el valor a insertar: ";
        cin >> valor;
        valorNumerico = (int) strtol(valor.c_str(), &end, 10);

        if (valorNumerico != 0){
            arbol.insertarValor(valorNumerico);
        } else {
            haInsertadoNumero = false;
        }

        cout << "Arbol actual: " << endl;
        arbol.desplegarEstructura();
    }

    haInsertadoNumero = true;

    while(haInsertadoNumero){

        cout << "Inserte el valor a eliminar: ";
        cin >> valor;
        valorNumerico = (int) strtol(valor.c_str(), &end, 10);

        if (valorNumerico != 0){
            arbol.eliminarValor(valorNumerico);
        } else {
            haInsertadoNumero = false;
        }

        cout << "Arbol actual: " << endl;
        arbol.desplegarEstructura();
    }
}

// n.insertarValor(50);
    // n.insertarValor(30);
    // n.insertarValor(70);
    // n.insertarValor(15);
    // n.insertarValor(40);
    // n.insertarValor(55);
    // n.insertarValor(80);
    // n.insertarValor(10);
    // n.insertarValor(20);
    // n.insertarValor(35);