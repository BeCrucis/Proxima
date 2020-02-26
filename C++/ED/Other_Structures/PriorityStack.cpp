#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Nodo {
    int dato;
    int prioridad;
    Nodo *sig;
};

class Pila {

    private:

    Nodo *cima;

    public:

    Pila(){
        this->cima = NULL;
    }

    ~Pila(){

        Nodo *objetivo = cima;
        Nodo *temp;
        int datoEliminado;

        while (objetivo != NULL){
            temp = objetivo;
            datoEliminado = objetivo->dato;

            objetivo = objetivo->sig;
            delete temp;
            cout << "Dato: ["<<datoEliminado<< "] Eliminado!" << endl;
            
        }
    }

    void meter(){
        
        Nodo *nuevo = new Nodo();

        cout << "Inserte el dato agregar: ";
        cin >> nuevo->dato;

        cout << "Inserte el la prioridad del dato: ";
        cin >> nuevo->prioridad;

        if(cima == NULL){
            // Agrega el primer nodo
            cima = nuevo;
            cima->sig = NULL;
        } else {

            // Encuentra el nodo anterior a la posicion de donde debe ir el nodo nuevo
            Nodo *anterior = buscarPrioridad(nuevo->prioridad);
            
            if(anterior == NULL){
                // Agrega el ultimo nodo
                nuevo->sig = cima;
                cima = nuevo;
            } else {
                // Agrega un nodo intermedio
                nuevo->sig = anterior->sig;
                anterior->sig = nuevo;
            }
        }

    }

    Nodo *buscarPrioridad(int prioridad){

        // Obtiene el nodo anterior al nodo de insercion 
        // Si no existe nodo con menor prioridad, devuelve NULL

        Nodo *anterior;
		anterior = NULL;

		if (cima->prioridad >= prioridad){

            return anterior;

        } else {

			anterior = cima;

			while ((anterior->sig != NULL) && (anterior->sig->prioridad < prioridad)){

				anterior = anterior->sig;

			}
													
			return anterior;
		}
    }

    void sacar(){

        // Saca el nodo de la cima de la pila y lo imprime

        Nodo *objetivo = cima;

        if (objetivo == NULL){
            cout << "La pila esta vacia!" << endl;
            return;
        }

        cima = objetivo->sig;

        cout << "Dato sacado: ["<<objetivo->dato<<"]"<< endl;
    }

    void limpiar(){

        // Elimina los nodos de la pila y la deja vacia

        Nodo *objetivo = cima;
        Nodo *temp;
        int datoEliminado;

        while (objetivo != NULL){
            temp = objetivo;
            datoEliminado = objetivo->dato;

            objetivo = objetivo->sig;
            delete temp;
            cout << "Dato: ["<<datoEliminado<< "] Eliminado!" << endl;
        }

        cima = NULL;
    }

    void mostrarCima(){

        if(cima == NULL){
            cout << "La pila esta vacia!" << endl;
            return;
        }

        cout << "La cima es: ["<<cima->dato<<"]"<< endl;
    }

    void longitud(){

        int longitud = 0;

        Nodo *objetivo = cima;

        while(objetivo != NULL){
            longitud += 1;
            objetivo = objetivo->sig;
        }

        cout << "El largo de la pila es: ["<<longitud<<"]"<< endl;
        
    }

    void desplegar(){

        // Imprime la pila desde la cima hasta su primer elemento

        if(cima == NULL){
            // Si la pila esta vacia
			cout << "[]" << endl;
			return;
		}

		string out = "[";
        Nodo *nodoActual;
        nodoActual = cima;

        while (nodoActual->sig != NULL){
            // Mientras el nodo actual no sea el primero de la pila, agregar valores
            out = out + std::to_string(nodoActual->dato) + ", ";
            nodoActual = nodoActual->sig;

        }

        // Cuando el nodo actual es el primero de la pila, cierra el string
        out = out + std::to_string(nodoActual->dato) + "]";

        // Imprimir la pila resultante
        cout << out << endl;
    }

};

int main(){

    Pila pila;
    int opcion;

    do {

        cout << "Pila con prioridad!" << endl << endl;
        cout << "1. Agregar objeto a la pila" << endl;
        cout << "2. Sacar objeto con prioridad" << endl;
        cout << "3. Limpiar la pila" << endl;
        cout << "4. Mostrar cima de la pila" << endl;
        cout << "5. Mostrar largo de la pila" << endl;
        cout << "6. Mostrar la pila" << endl;
        cout << "99. Salir" << endl;
        cout << endl;

        cout << "Inserte su opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1){
            
            pila.meter();

        } else if (opcion == 2){

            pila.sacar();

        } else if (opcion == 3){

            pila.limpiar();

        } else if (opcion == 4){

            pila.mostrarCima();

        } else if (opcion == 5){

            pila.longitud();

        } else if (opcion == 6){
                
        }

        cout << "Pila actual: ";
        pila.desplegar();  
        cout << endl;
        
        system("pause");
        system("cls");
       
    } while (opcion != 99);

}