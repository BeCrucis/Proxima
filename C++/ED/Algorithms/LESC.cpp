#include "iostream"

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
};

class listasEncadenadasSecuenciales {
	private:
		nodo *inicial, *anterior;
	public:
		listasEncadenadasSecuenciales() {
			inicial = NULL;
		};
		~listasEncadenadasSecuenciales() {
            nodo *aEliminar, *objetivo;

            cout << "duck";
            objetivo = inicial;
            delete inicial;
            cout << "duck2";
				while(objetivo != NULL) {
					aEliminar = objetivo;
					objetivo = objetivo -> sig;
					delete aEliminar;
				}
            cout << "destructor time!" << endl;
		};
	void desplejarLista() {
		nodo *objetivo = inicial;
		if(inicial != NULL) {
			while(objetivo -> sig != inicial) {
				cout << objetivo -> dato << endl;
				objetivo = objetivo -> sig;
			}
            cout << "wtf";
            cout << objetivo -> dato << endl;
            cout << "wtf2";
		} else {
			cout << "Lista vacia" << endl;
		}
	}

	nodo *BuscarLista(int codigo) {
		nodo *buscado = buscarUltimo();
		if(codigo < inicial -> dato) { 
			return buscado; 
		} else {
			buscado = inicial;
			while((buscado -> sig != inicial ) && (codigo > buscado -> sig -> dato)) {
                buscado = buscado -> sig;
            }
            return buscado;
        }
    }

    void agregarElemento() {
		nodo *nuevo;
		char respuesta;
		do {
			nuevo = new nodo;
			cout << "Ingrese la codigo del elemento a agregar" << endl;
			cin >> nuevo -> dato;

            if(inicial == NULL) {
                nuevo -> sig = nuevo;
                inicial = nuevo;
            } else {
                while (verificarExistencia(nuevo -> dato)) {
                    cout << "El elemento ya existe! Ingresar clave diferente" << endl;
                    cin >> nuevo -> dato;
                }
                nodo *anterior = BuscarLista(nuevo -> dato);
                nodo *ultimo = buscarUltimo();
                if(ultimo == anterior) {
                    nuevo -> sig = inicial;
                    anterior -> sig = nuevo;
                } else {
                    nuevo -> sig = anterior -> sig;
                    anterior -> sig = nuevo;
                }
            }

            cout << "Desea ingresar otro elemento?" << endl;
            cin >> respuesta;

		} while(tolower(respuesta) != 'n');  
	} 

    bool verificarExistencia(int codigo) {
        nodo *objetivo = inicial;
        while(objetivo -> sig != inicial) {
            if(codigo == objetivo -> dato) {
                return true;
            } else {
                objetivo = objetivo -> sig;
            }
        } 
        return false;
    }

    void eliminarNodo(int codigo) {
        nodo *aEliminar;
        nodo *objetivo = inicial;
        nodo *ultimo = buscarUltimo();
        if(objetivo -> dato == codigo) {
            inicial = objetivo -> sig;
            ultimo -> sig = inicial;
            delete objetivo;   
            return;     
        } else while(objetivo -> sig != inicial) {
            if(objetivo -> sig -> dato == codigo) {
                objetivo -> sig = objetivo -> sig -> sig;
                delete objetivo -> sig;
                return;    
            } else {
                objetivo = objetivo -> sig;
            }
        } 
        cout << "Nodo no encontrado" << endl;
    }

    nodo *buscarUltimo() {
        nodo *buscado = inicial;
        while(buscado -> sig != inicial) {
            buscado = buscado -> sig;
        } return buscado;
    }
}; 

int main() {
    char respuesta;
    int codigo;

    listasEncadenadasSecuenciales lista;

    lista.agregarElemento();
    lista.desplejarLista();

    cout << "Eliminar nodo? s/n" << endl;
    cin >> respuesta;
     if(tolower(respuesta) == 's') {
        do {
            cout << "ingrese el codigo del elemento a eliminar" << endl;
            cin >> codigo;
            lista.eliminarNodo(codigo);
            cout << "Eliminar otro elemento? s/n" << endl;
            cin >> respuesta;
        } while(tolower(respuesta) == 's');
    }
    lista.desplejarLista();
    cout << "duck0";
}