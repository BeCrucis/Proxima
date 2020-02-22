#include <iostream>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

class Lse {

	private:
		nodo *inicial;

	public:

		Lse(){
			inicial = NULL;
		}

	void desplegarLista(){

		if (inicial == NULL) {

			cout << "La lista esta vacia" << endl;

		} else {

			nodo *apunt;
			apunt = inicial;
			while (apunt != NULL){
				cout << apunt->dato << endl;
				apunt = apunt->sig;

			}
		}
	}

	nodo* buscarLista(int clave){

		//Devuelve la direccion del nodo que antecede al nuevo
		//nodo que va a ser agregado, o que va a ser eliminado.

		//Si la clave es menor o igual al dato del primer nodo
		//el valor devuelto es NULL.

		//Si la clave es mayor que el dato del �ltimo nodo
		//devuelve la direcci�n del �ltimo nodo.

		nodo *anterior;
		anterior = NULL;

		if (inicial->dato > clave){

            return anterior;

        } else {

			anterior = inicial;

			while ((anterior->sig != NULL) && (anterior->sig->dato <= clave)){

				anterior=anterior->sig;

			}
													
			return anterior;
		}
	}

    void agregar(){

        nodo *nuevo, *anterior;
        char resp;

        do {
            nuevo = new nodo();
            cout << "Entre la clave del nodo a agregar: ";
            cin >> nuevo->dato;

            if (inicial == NULL){

                //Agrega el primer nodo a la lista
                inicial = nuevo;
                nuevo->sig = NULL;

			} else {
				
				anterior = buscarLista(nuevo->dato);	
				
				if (anterior == NULL && nuevo->dato != inicial->dato){

				//Agrega un nodo que queda de primero
                //en una lista que no estaba vacia
                nuevo->sig = inicial;
                inicial = nuevo;

				} else if (anterior == NULL || (anterior->sig != NULL && anterior->sig->dato == nuevo->dato)){

					cout << "El nodo a agregar ya existe!" << endl;

				} else if (anterior->sig != NULL){

					//Agrega un nodo que queda entre el
					//primero y el ultimo
					nuevo->sig = anterior->sig;
					anterior->sig = nuevo;

				} else {

					//Agrega un nodo que queda de ultimo
					nuevo->sig = NULL;
					anterior->sig = nuevo;

				}

			}

            cout << "Desea agregar otro nodo? (S/N): ";
            cin >> resp;
            resp = tolower(resp);
        } while (resp == 's');
    }
};

int main(){
	Lse l;
	l.agregar();
	l.desplegarLista();
    
}
