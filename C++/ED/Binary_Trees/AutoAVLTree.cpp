#include "iostream"
#include "conio.h"
#include "stdio.h"
using namespace std;

class NodoArbol
{
public:
	string direccion;
	NodoArbol *der, *izq;
	NodoArbol()
	{
		der = NULL;
		izq = NULL;
	}

    NodoArbol(int dato){
        info = dato;
        direccion = "x" + to_string(info);
		izq = NULL;
		der = NULL;
    }

	NodoArbol(int dato, int fb)
	{
		fb = fb;
		info = dato;
		izq = NULL;
		der = NULL;
	}

    int getInfo(){
        return this->info;
    }

    void setInfo(int info){
        this->info = info;
    }

    int getBalance(){
        return this->fb;
    }

    void setBalance(int fb){
        this->fb = fb;
    }

    private:
    int info;
    int fb;

};
class AVL
{
private:
	NodoArbol *raiz;

public:
	AVL()
	{
		raiz = NULL;
	}
	~AVL()
	{
		cout << "\nborrando..." << endl;
		borrar_nodos(raiz);
		cout << "borrado finalizado" << endl;
		system("pause");
	}
	void borrar_nodos(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			borrar_nodos(raiz->izq);
			borrar_nodos(raiz->der);
			cout << "Borro " << raiz->getInfo() << endl;
			delete raiz;
		}
	}

	void desplegarNodo(string prefijo, NodoArbol* raiz, bool esIzquierdo){
        if( raiz == NULL ){
            return;
        }

        cout << prefijo;

        cout << (esIzquierdo ? "├──" : "└──" );
        
        cout << raiz->getInfo() <<"["<<raiz->direccion<<"]"<< endl;

        desplegarNodo( prefijo + (esIzquierdo ? "│   " : "    "), raiz->izq, true);
        desplegarNodo( prefijo + (esIzquierdo ? "│   " : "    "), raiz->der, false);
    }

    void desplegarEstructura(){
        desplegarNodo("", raiz, false);
    }

	void insertar(int dato)
	{
		NodoArbol *nuevo, *explorador, *padreNuevo;
		int salir;
		salir = 0; //Variable que controla el ingreso de nodos repetidos
		nuevo = new NodoArbol(dato);
		explorador = raiz;
		padreNuevo = NULL;

		evaluar_repetido(raiz, dato, salir);
		if (salir != 1)
		{
			while (explorador != NULL)
			{
				padreNuevo = explorador;
				if (nuevo->getInfo() > explorador->getInfo())
					explorador = explorador->der;
				else
					explorador = explorador->izq;
			}
			if (padreNuevo == NULL)
			{
				raiz = nuevo;
			}
			else if (nuevo->getInfo() < padreNuevo->getInfo())
				padreNuevo->izq = nuevo;
			else
				padreNuevo->der = nuevo;
			factor_de_balanceo(raiz); //Asigna el factor de balance (fb) a //cada nodo del arbol
			balancear(raiz);		  //Balancea el arbol
			factor_de_balanceo(raiz); //Asigna el fb a cada nodo despues de      //balancear el arbol
		}
	}
	void evaluar_repetido(NodoArbol *raiz, int valor, int &salir) //Recorre la //lista comparando el nodo ingresado con los demas del arbol.
	{															  //si se encuentra un nodo que coincide, la variable salir se modifica.
		if (raiz != NULL)
		{
			evaluar_repetido(raiz->izq, valor, salir);
			if (raiz->getInfo() == valor)
			{
				salir = 1;
				cout << "\nEl nodo ya existe\n"
					 << endl;
			}
			else
				evaluar_repetido(raiz->der, valor, salir);
		}
	}

	void factor_de_balanceo(NodoArbol *raiz) //Determina el factor de //balance de cada nodo
	{
		if (raiz != NULL)
		{
			int nivelizq, nivelder, diferencia;
			nivelizq = nivel(raiz->izq);
			nivelder = nivel(raiz->der);
			diferencia = nivelizq - nivelder;
			raiz->setBalance(diferencia);
			factor_de_balanceo(raiz->izq);
			factor_de_balanceo(raiz->der);
		}
	}

	int nivel(NodoArbol *raiz) //Determina los niveles del arbol
	{
		if (raiz == NULL)
			return 0;
		else
		{
			int a, b;
			a = nivel(raiz->izq);
			b = nivel(raiz->der);
			if (a < b)
				return b + 1;
			else
				return a + 1;
		}
	}
	void balancear(NodoArbol *raiz)
	{

		if (raiz != NULL)
		{

			//nodoarbol *apunt;
			//nodoarbol *temp;
			//int aux;
			balancear(raiz->izq);
			balancear(raiz->der);

			if (raiz->getBalance() == (-2))
			{
				cout << "Balanceo necesario! Raiz culpable:"<<raiz->getInfo()<<"["<<raiz->direccion<<"]"<< endl;
				cout << "Imprimiendo arbol previo: " << endl;
				
				this->desplegarEstructura();
				cout << "" << endl;

				if (raiz->der->getBalance() == -1)
				{
					rotar_izq(raiz);
				}
				else
				{
					if (raiz->der->getBalance() == 1)
					{

						rotar_der(raiz->der);
						rotar_izq(raiz);
					}
					else
					{
						if (raiz->der->getBalance() == 0)
						{
							rotar_izq(raiz);
						}
					}
				}

				cout << "Arbol resultante:" << endl;
				this->desplegarEstructura();
				cout << "" << endl;
			}

			if (raiz->getBalance() == 2)
			{
				cout << "Balanceo necesario! Raiz culpable:"<<raiz->getInfo()<<"["<<raiz->direccion<<"]"<< endl;
				cout << "Imprimiendo arbol previo: " << endl;
				this->desplegarEstructura();
				cout << "" << endl;

				if (raiz->izq->getBalance() == 1)
				{
					rotar_der(raiz);
				}
				else
				{
					if (raiz->izq->getBalance() == -1)
					{
						rotar_izq(raiz->izq);
						rotar_der(raiz);
					}
					else
					{
						if (raiz->izq->getBalance() == 0)
						{
							rotar_der(raiz);
						}
					}
				}

				cout << "Arbol resultante:" << endl;
				this->desplegarEstructura();
				cout << "" << endl;
			}
		}
	}
	NodoArbol *devolver_raiz()
	{
		return raiz;
	}

	void rotar_izq(NodoArbol *raiz)
	{
		int aux;
		NodoArbol *apunt;
		apunt = raiz->der;
		aux = raiz->getInfo();
		raiz->der = apunt->der;
		apunt->der = apunt->izq;
		apunt->izq = raiz->izq;
		raiz->izq = apunt;
        raiz->setInfo(apunt->getInfo());
		apunt->setInfo(aux);

		cout << "Rotacion izquierda realizada, raiz: "<<"["<<raiz->direccion<<"], apunt: "<<"["<<apunt->direccion<<"]"<< endl;
		
	}

	void rotar_der(NodoArbol *raiz)
	{
		int aux;
		NodoArbol *apunt;
		apunt = raiz->izq;
		aux = raiz->getInfo();
		raiz->izq = apunt->izq;
		apunt->izq = apunt->der;
		apunt->der = raiz->der;
		raiz->der = apunt;
		raiz->setInfo(apunt->getInfo());
		apunt->setInfo(aux);
		cout << "Rotacion derecha realizada, raiz: "<<"["<<raiz->direccion<<"], apunt: "<<"["<<apunt->direccion<<"]"<< endl;
	}

	//  DESPLIEGA EL ARBOL USANDO INORDEN - INCLUYE fb
	void despliega_inorden_fb(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			despliega_inorden_fb(raiz->izq);
			cout << raiz->getInfo() << "-> " << raiz->getBalance() << endl;
			despliega_inorden_fb(raiz->der);
		}
	}
	//DESPLIEGA EL ARBOL USANDO PREORDEN
	void despliega_preorden(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			cout << raiz->getInfo() << "    ";
			despliega_preorden(raiz->izq);
			despliega_preorden(raiz->der);
		}
	}
	//DESPLIEGA EL ARBOL USANDO INORDEN
	void despliega_inorden(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			despliega_inorden(raiz->izq);
			cout << raiz->getInfo() << "    ";
			despliega_inorden(raiz->der);
		}
	}
	//DESPLIEGA EL ARBOL USANDO POSTORDEN
	void despliega_postorden(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			despliega_postorden(raiz->izq);
			despliega_postorden(raiz->der);
			cout << raiz->getInfo() << "    ";
		}
	}

	//DESPLIEGA EL ARBOL USANDO NIVEL POR NIVEL
	struct nodo
	{
		int dato;
		nodo *sig;
	};
	
	void despliega_nivel_por_nivel(NodoArbol *raiz)
	{
		if (raiz != NULL)
		{
			nodo *final, *temp, *nuevo;
			NodoArbol *apunt;
			nuevo = new nodo;
			nuevo->dato = raiz->getInfo();
			final = nuevo;
			temp = nuevo;
			apunt = raiz;
			final->sig = NULL;
			while (temp != NULL)
			{
				cout << temp->dato << "    ";
				if (apunt->izq != NULL)
				{
					nuevo = new nodo;
					final->sig = nuevo;
					nuevo->dato = apunt->izq->getInfo();
					final = nuevo;
					final->sig = NULL;
					if (apunt->der != NULL)
					{
						nuevo = new nodo;
						final->sig = nuevo;
						nuevo->dato = apunt->der->getInfo();
						final = nuevo;
						final->sig = NULL;
					}
				}
				else
				{
					if (apunt->der != NULL)
					{
						nuevo = new nodo;
						final->sig = nuevo;
						nuevo->dato = apunt->der->getInfo();
						final = nuevo;
						final->sig = NULL;
					}
				}
				temp = temp->sig;
				if (temp != NULL)
				{
					comparar_nodo_a_nodo(raiz, temp->dato);
					apunt = resultado;
				}
			}
		}
		else
		{
			cout << "\n El arbol esta vacio" << endl;
		}
	}

	NodoArbol *resultado;

	void comparar_nodo_a_nodo(NodoArbol *raiz, int valor)
	{

		if (raiz != NULL)
		{
			comparar_nodo_a_nodo(raiz->izq, valor);
			if (raiz->getInfo() == valor)
			{
				resultado = raiz;
			}
			else
				comparar_nodo_a_nodo(raiz->der, valor);
		}
	}
	//eliminar
	void eliminar_nodo(int dato)
	{
		NodoArbol *aux1, *aux2, *temp;
		bool b;

		//Inicia la busqueda del nodo a eliminar
		aux1 = raiz;
		aux2 = NULL;
		while (aux1->getInfo() != dato)
		{
			aux2 = aux1;
			if (dato < aux1->getInfo())
				aux1 = aux1->izq;
			else
				aux1 = aux1->der;
			if (aux1 == NULL)
			{
				cout << "El nodo no existe en el arbol" << endl;
				break;
			}
		}
		//Fin de la busqueda del nodo a eliminar
		//en aux1 queda la direccion del nodo a eliminar
		//en aux2 queda la direccion del nodo padre del nodo a eliminar
		if (aux1 != NULL)
		{
			cout << "Arbol previo:" << endl;
			this->desplegarEstructura();
			cout << "" << endl;
			
			temp = aux1;
			//cuando no tiene hijos
			if ((aux1->izq == NULL) && (aux1->der == NULL))
			{
				if (aux2 != NULL)
				{
					if (aux1->getInfo() > aux2->getInfo())
						aux2->der = NULL;
					else
						aux2->izq = NULL;
				}
				else
					raiz = NULL;
			}
			else
			{
				//cuando tiene dos hijos
				if ((aux1->izq != NULL) && (aux1->der != NULL))
				{
					int num = 0;
					cout << "Si desea remplazar con el predecesor    marque 1" << endl
						 << endl;
					cout << "Si desea remplazar con el sucesor marque 2" << endl;
					cin >> num;
					if (num == 1)
					{
						aux2 = aux1;
						temp = aux1->izq;
						b = true;
						while (temp->der != NULL)
						{
							aux2 = temp;
							temp = temp->der;
							b = false;
						}
						aux1->setInfo(temp->getInfo());
						if (b == true)
							aux1->izq = temp->izq;
						else
						{
							if (temp->izq != NULL)
								aux2->der = temp->izq;
							else
								aux2->der = NULL;
						}
					}
					else
					{
						if (num == 2)
						{
							aux2 = aux1;
							temp = aux1->der;
							b = true;
							while (temp->izq != NULL)
							{
								aux2 = temp;
								temp = temp->izq;
								b = false;
							}
							aux1->setInfo(temp->getInfo());
							if (b == true)
								aux1->der = temp->der;
							else
							{
								if (temp->izq != NULL)
									aux2->izq = temp->der;
								else
									aux2->izq = NULL;
							}

							cout << "Valor final de b: " <<b<< endl;
							
						}
						else
							cout << "La opcion no es correcta" << endl
								 << endl;
					}
				}
				else
				{
					//cuando tiene un solo hijo
					if (aux1->izq == NULL)
					{
						if (aux2 != NULL)
						{
							if (aux1->getInfo() < aux2->getInfo())
								aux2->izq = aux1->der;
							else
								aux2->der = aux1->der;
						}
						else
							raiz = aux1->der;
					}
					else
					{
						if (aux2 != NULL)
						{
							if (aux1->getInfo() < aux2->getInfo())
								aux2->izq = aux1->izq;
							else
								aux2->der = aux1->izq;
						}
						else
							raiz = aux1->izq;
					}
				}
			}

			if(aux1 != NULL){
			cout << "Valor final de aux1: " <<aux1->direccion<< endl;
			} else {
				cout << "Valor final de aux1: " <<"NULL"<< endl;
			}
			
			if(aux2 != NULL){
				cout << "Valor final de aux2: " <<aux2->direccion<< endl;
			} else {
				cout << "Valor final de aux2: " <<"NULL"<< endl;
			}
			if(temp != NULL){
				cout << "Valor final de temp: " <<temp->direccion<< endl;
			} else {
				cout << "Valor final de temp: " <<"NULL"<< endl;
			}

			delete temp;
			factor_de_balanceo(raiz); //aqui asigno el Factor de Balanceo //(fb) para el nuevo arbol
			balancear(raiz);		  //aqui balanceo el arbol
			factor_de_balanceo(raiz); //aqui asigno el FB despues de //balancearlo
			balancear(raiz);		  //aqui balanceo el arbol
		}

	}
};

int main()
{
	NodoArbol *raiz;
	int opc;
	AVL n;
    bool haInsertadoNumero;


	system("chcp 65001");
    system("cls");

	do
	{
		system("cls");
		raiz = n.devolver_raiz();
		cout << "\n************MENU PRINCIPAL*****************" << endl;
		cout << "1. Agregar elementos al arbol" << endl;
		cout << "2. Desplegar los elementos en inorden" << endl;
		cout << "3. Desplegar los elementos en postorden" << endl;
		cout << "4. Desplegar los elementos en preorden" << endl;
		cout << "5. Desplegar los elementos nivel por nivel" << endl;
		cout << "8. Desplegar arbol estructurado" << endl;
		cout << "6. Eliminar elementos del arbol" << endl;
		cout << "7. Salir" << endl;
		cout << "*******************************************" << endl;
		cin >> opc;
		system("cls");
		haInsertadoNumero = true;
		switch (opc)
		{
		case 1:

            while(haInsertadoNumero){

                string valor;
                int valorNumerico;

                cout << "Inserte el valor a insertar: ";
                cin >> valor;
                valorNumerico = (int) strtol(valor.c_str(), NULL, 10);

                if (valorNumerico != 0){
                    n.insertar(valorNumerico);
                } else {
                    haInsertadoNumero = false;
                }

                cout << "Arbol actual: " << endl;
                n.desplegarEstructura();
            }
			break;
		case 2:
			if (raiz != NULL)
				n.despliega_inorden(raiz);
			else
				cout << " El arbol esta vacio" << endl;
			system("pause");
			break;
		case 3:
			if (raiz != NULL)
				n.despliega_postorden(raiz);
			else
				cout << " El arbol esta vacio" << endl;
			system("pause");
			break;
		case 4:
			if (raiz != NULL)
				n.despliega_preorden(raiz);
			else
				cout << " El arbol esta vacio" << endl;
			system("pause");
			break;
		case 5:
			n.despliega_nivel_por_nivel(raiz);
			system("pause");
			break;
		case 6:
			while(haInsertadoNumero){

                string valor;
                int valorNumerico;

                cout << "Inserte el valor a eliminar: ";
                cin >> valor;
                valorNumerico = (int) strtol(valor.c_str(), NULL, 10);

                if (valorNumerico != 0){
                    n.eliminar_nodo(valorNumerico);
                } else {
                    haInsertadoNumero = false;
                }

                cout << "Arbol actual: " << endl;
                n.desplegarEstructura();
            }
			break;
		case 7:
			//exit(0);
			break;
		case 8:
			n.desplegarEstructura();
			system("pause");
			break;
		default:
			cout << "Lo sentimos, " << opc << " no es una opcion valida, por favor intente de nuevo" << endl;
			system("pause");
			break;
		}

	} while (opc != 7);
}
