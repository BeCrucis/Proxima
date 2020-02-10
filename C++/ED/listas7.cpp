#include "iostream"

using namespace std;

struct nodo {
			int codigo, semestre;
			char *nombre; 
			nodo *sig;
		};

class lista {
	public:
		nodo *inicial, *aEliminar, *temp;
		int contador = 0, codigo;
		nodo *anterior = NULL, *nuevo, *objetivo;

		//Inicializa con el contructor de la clase el nodo inicial
			lista() { inicial = NULL; }
			~lista() { 
				cout << "destructor time!" << endl;

				while(inicial != NULL) {
					aEliminar = inicial;
					inicial = inicial -> sig;
					delete aEliminar;
				}
			}

		//Metodo de creación del siguente nodo
		void crearLista() {
			nuevo = new nodo;

			if(anterior == NULL) {
				nuevo -> sig = inicial;
				darValorAlNodo();
				inicial = nuevo;

			} else {
				nuevo -> sig = anterior -> sig;
				darValorAlNodo();
				anterior -> sig = nuevo;
			}

			anterior = nuevo;
		}

		//da el valor int al nodo
		void darValorAlNodo() {
			cout << "codigo del estudiante: ";
			cin >> nuevo -> codigo;
			cout << "semestre: ";
			cin >> nuevo -> semestre;
			cin.ignore();
			cout << "Nombre: ";
			nuevo -> nombre = new char[60];
			cin.getline(nuevo -> nombre, 60);
		}

		//imprime el nodo actual 
		void outputDelNodo() {
			cout << "Codigo del estudiante "   << contador << ":" << objetivo -> codigo << endl; 
			cout << "Semestre del estudiante " << contador << ":" << objetivo -> semestre << endl;
			cout << "Nombre del estudiante "   << contador << ":" << objetivo -> nombre << endl << endl;
			contador++;
		}

		//Recorre la lista creada
		void RecuRecorrer() {
			if(objetivo != NULL){
				outputDelNodo();
				objetivo = objetivo -> sig;
				RecuRecorrer();
			}
		}	

		//Fix this garbage
		nodo *agregarNodo() {
			nuevo = new nodo;
			if(codigo == 0) {
				nuevo -> sig = inicial;
				inicial = nuevo;
				darValorAlNodo();
				return inicial;
			} else {
				nuevo -> sig = anterior -> sig;
				anterior -> sig = nuevo;
				darValorAlNodo();
				return anterior;
			}	
		}

		nodo *buscarNodo () {
			nodo *apun = inicial;
			while(apun != NULL) {
				if (apun -> codigo == codigo) {
					return apun;
				} else {
					apun = apun -> sig;
				}
			}
			return NULL;
		}

		void eliminarNodo() {
			if((anterior -> sig) == NULL) { //tratando de eliminar el siguente elemento del ultimo
				cout << "no existe siguente elemento, no se puede eliminar nada" << endl;
				return;
			/*} else if((anterior -> sig) -> sig == NULL) { //Elminiando el ultimo elemento
				anterior - sig= NULL;
				delete (anterior -> sig);*/
			} else { //Eliminando cualquier otro elemento 
				nodo *aEliminar = anterior -> sig;
				anterior -> sig = (anterior -> sig) -> sig;
				delete aEliminar;
			}
		}

};

int main() {
	lista Ini;
	char opcion;
	cout << "Crear elementos inciales de la lista" << endl;
	do {
		Ini.crearLista();
		cout << "¿Crear otro nodo? s/n" << endl;
		cin >> opcion;
	} while(tolower(opcion) != 'n');

	cout << "Lista original: " << endl;
	Ini.objetivo = Ini.inicial;
	Ini.RecuRecorrer();

	Ini.objetivo = Ini.inicial;

	cout << "Desea agregar un nuevo elemento a la lista? s/n" << endl;
	cin >> opcion;
	if (tolower(opcion) == 's') {
		do {

			cout << "Ingrese el codigo del estudiante anterior al que va a ser agregado,"  << endl << " de querer agregar el nuevo estudiante al inico de la lista, ingrese '0' " << endl;

			cin >> Ini.codigo;

			if(Ini.codigo == 0) {
				Ini.inicial = Ini.agregarNodo();
			} else {
				Ini.anterior =  Ini.buscarNodo();
				if(Ini.anterior != NULL) {
					Ini.nuevo = new nodo;
					Ini.anterior = Ini.agregarNodo();
				} else {
					cout << "El nodo no ha sido encontrado" << endl;
				}
			}

			cout << "Desea agregar otro nodo? s/n" << endl;
			cin >> opcion;

		} while (tolower(opcion) != 'n');

		cout << "La Lista completa, despues de los cambios es:" << endl;

		Ini.objetivo = Ini.inicial;
		Ini.contador = 0;
		Ini.RecuRecorrer();
	}

	cout << "Desea eliminar algun elemento de la lista s/n" << endl;
	cin >> opcion;

	if(tolower(opcion) == 's') {
		do {
			cout << "Ingrese el elemento anterior al que va a ser eliminado, " << endl << " de querer eliminar el primer elemento de la lista, ingrese '0'" << endl;

			cin >> Ini.codigo;

			if(Ini.codigo == 0) {
				Ini.temp = Ini.inicial; 
				Ini.inicial = Ini.inicial -> sig;
				delete Ini.temp;
			} else {
				Ini.anterior = Ini.buscarNodo();
				Ini.eliminarNodo();
			}

			cout << "Desea eliminar otro elemento? s/n" << endl;
			cin >> opcion;

		} while (tolower(opcion) != 'n');

		cout << "La Lista completa, despues de los cambios es:" << endl;

		Ini.objetivo = Ini.inicial;
		Ini.contador = 0;
		Ini.RecuRecorrer();
	}
}