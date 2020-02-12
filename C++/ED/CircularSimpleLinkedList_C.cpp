#include <iostream>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

class Lsec {

	private:
		nodo *inicial;

	public:

		Lsec(){
			inicial = NULL;
		}

	void desplegarLista(){

		if(inicial == NULL){
			cout << "[]" << endl;
			return;
		}

		string out = "[";
        nodo *nodoActual;
        nodoActual = inicial;

        while (nodoActual->sig != inicial){

            out = out + std::to_string(nodoActual->dato) + ", ";
            nodoActual = nodoActual->sig;

        }

        out = out + std::to_string(nodoActual->dato) + "]";

        cout << out << endl;
	}

	nodo* buscarLista(int clave){

		//Devuelve la direccion del nodo que antecede al nuevo
		//nodo que va a ser agregado, o que va a ser eliminado.

		//Si la clave es menor o igual al dato del primer nodo
		//el valor devuelto es NULL.

		//Si la clave es mayor que el dato del Ãºltimo nodo
		//devuelve la direcciÃ³n del Ãºltimo nodo.

		nodo *anterior;
		anterior = NULL;

		if (inicial->dato >= clave){

            return anterior;

        } else {

			anterior = inicial;

			while ((anterior->sig != inicial) && (anterior->sig->dato < clave)){

				anterior=anterior->sig;

			}
													
			return anterior;
		}
	}

    nodo *buscarUltimo(){

        nodo *ultimo;
        ultimo = inicial;
        while(ultimo->sig != inicial){
            ultimo = ultimo->sig;
        }
        return ultimo;
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
                nuevo->sig = inicial;

			} else {
				
				anterior = buscarLista(nuevo->dato);	
				
				if (anterior == NULL && nuevo->dato != inicial->dato){

				//Agrega un nodo que queda de primero
                //en una lista que no estaba vacia
				nodo* ultimo = buscarUltimo();
                nuevo->sig = inicial;
                inicial = nuevo;
                ultimo->sig = nuevo;

				} else if (anterior == NULL || anterior->sig->dato == nuevo->dato){

					cout << "El nodo a agregar ya existe!" << endl;

				} else if (anterior->sig != inicial){

					//Agrega un nodo que queda entre el
					//primero y el ultimo
					nuevo->sig = anterior->sig;
					anterior->sig = nuevo;

				} else {

					//Agrega un nodo que queda de ultimo
					nuevo->sig = inicial;
					anterior->sig = nuevo;

				}
			}

            cout << "Desea agregar otro nodo? (S/N): ";
            cin >> resp;
            resp = tolower(resp);
        } while (resp == 's');
    }

    void eliminarNodo(){

		char resp;
		int clave;
		nodo* anterior;

		do {

			cout << "Desea eliminar un nodo? (S/N): ";
            cin >> resp;
            resp = tolower(resp);

			if(resp == 's'){

				cout << "Inserte la clave del nodo a eliminar: ";
				cin >> clave;
				
				anterior = buscarLista(clave);

				if(anterior == NULL || anterior->sig == inicial || anterior->sig->dato != clave){

					if(inicial->dato != clave){

						cout << "El nodo no existe" << endl;

					} else {
						
						nodo* ultimo = buscarUltimo();
						nodo* temp = inicial;
						int deletedData = temp->dato;

						if(ultimo == inicial){

							inicial = NULL;
							delete temp;

						} else {

							inicial = inicial->sig;
							ultimo->sig = inicial;
							delete temp;

						}

						cout << "Borrado dato: "<<deletedData<< endl;
					}
				
				} else {

					nodo* temp = anterior->sig;
					int deletedData = temp->dato;
					anterior->sig = anterior->sig->sig;
					delete temp;

					cout << "Borrado dato: "<<deletedData<< endl;
				}

			}
		} while ( resp == 's');

    }
};

int main(){

	Lsec l;
	l.agregar();
    l.eliminarNodo();
	l.desplegarLista();
    
}
