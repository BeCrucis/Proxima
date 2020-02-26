#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Nodo {
    int dato;
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

        if(cima == NULL){
            cima = nuevo;
            cima->sig = NULL;
        } else {
            nuevo->sig = cima;
            cima = nuevo;
        }

    }

    void sacar(){

        Nodo *objetivo = cima;

        if (objetivo == NULL){
            cout << "La pila esta vacia!" << endl;
            return;
        }

        cima = objetivo->sig;

        cout << "Dato sacado: ["<<objetivo->dato<<"]"<< endl;
    }

    void limpiar(){

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

        if(cima == NULL){
			cout << "[]" << endl;
			return;
		}

		string out = "[";
        Nodo *nodoActual;
        nodoActual = cima;

        while (nodoActual->sig != NULL){

            out = out + std::to_string(nodoActual->dato) + ", ";
            nodoActual = nodoActual->sig;

        }

        out = out + std::to_string(nodoActual->dato) + "]";

        cout << out << endl;
    }

};

int main(){

    Pila pila;
    int opcion;

    do {

        cout << "Pila!" << endl << endl;
        cout << "1. Agregar objeto a la pila" << endl;
        cout << "2. Sacar objeto de la pila" << endl;
        cout << "3. Limpiar la pila" << endl;
        cout << "4. Mostrar cima de la pila" << endl;
        cout << "5. Mostrar largo de la pila" << endl;
        cout << "6. Mostrar la pila" << endl;
        cout << "7. Salir" << endl;
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
       
    } while (opcion != 7);

}