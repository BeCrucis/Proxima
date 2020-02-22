#include <iostream>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
    nodo *ant;
};

class Ldec {

	private:
		nodo *inicial;

	public:

		Ldec(){
			inicial = NULL;
		}

	void desplegarLista(){

        string opt;
        string out = "[";
        nodo *nodoActual;

        cout << "1: Sentido horario | Else: Sentido antihorario: ";
        cin >> opt;

        if(inicial == NULL){
			cout << "[]" << endl;
			return;
		}

        if(opt == "1"){

            nodoActual = this->inicial;

            while (nodoActual->sig != inicial){

                out = out + std::to_string(nodoActual->dato) + ", ";
                nodoActual = nodoActual->sig;

            }

        } else {

            nodoActual = this->inicial->ant;

            while (nodoActual->ant != inicial){

                out = out + std::to_string(nodoActual->dato) + ", ";
                nodoActual = nodoActual->ant;

            }
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

			while ((anterior->sig != NULL) && (anterior->sig->dato < clave)){

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
                nuevo->sig = nuevo;
                nuevo->ant = nuevo;

			} else {
				
				anterior = buscarLista(nuevo->dato);	
				
				if (anterior == NULL && nuevo->dato != inicial->dato){

				//Agrega un nodo que queda de primero
                //en una lista que no estaba vacia
                nuevo->sig = inicial;
                nuevo->ant = inicial->ant;
                inicial->ant = nuevo;
                inicial = nuevo;

				} else if (anterior == NULL || (anterior->sig != NULL && anterior->sig->dato == nuevo->dato)){

					cout << "El nodo a agregar ya existe!" << endl;

				} else if (anterior->sig != NULL){

					//Agrega un nodo que queda entre el
					//primero y el ultimo
					nuevo->sig = anterior->sig;
                    nuevo->ant = anterior;

					anterior->sig = nuevo;
                    nuevo->sig->ant = nuevo;

				} else {

					//Agrega un nodo que queda de ultimo
					nuevo->sig = inicial;
                    nuevo->ant = anterior;
                    
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
	Ldec l;
	l.agregar();
	l.desplegarLista();
    
}
