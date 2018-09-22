// Arboles  bien crack

#include "iostream"


using namespace std;
//using namespace system;

class  nodoarbol
{
public:
	int info;
	nodoarbol *der, *izq;
	nodoarbol();
	nodoarbol()
	{
		izq = NULL;
		der = NULL;
	}
	nodoarbol(int dato)
	{
		info = dato;
		izq = NULL;
		der = NULL;
	}
};

class ABB
{
public:
	ABB()
	{
		raiz = NULL;
	}
	~ABB()
	{
		cout << "entro al destructor" << endl;
		borrar_nodos(raiz);
		cout << "salgo del destructor" << endl;
	}
	void borrar_nodos(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			borrar_nodos(raiz->izq);
			borrar_nodos(raiz->der);
			cout << "destructor de " << raiz->info << endl;
			delete raiz;
		}
	}
	void insertar()
	{
		nodoarbol *aux1, *aux2, *aux3;
		aux1 = new nodoarbol;
		aux2 = raiz;
		aux3 = NULL;

		cout << "entre el valor del nodo a insertar" << endl;
		cin >> aux1->info;
		while (aux2 != NULL)
		{
			aux3 = aux2;
			if (aux1->info > aux2->info)
			{
				aux2 = aux2->der;
			}
			else{
				aux2 = aux2->izq;
			}

			if (aux3=NULL)
			{
				raiz = aux1;
			}else
			{
				if (aux1->info < aux3->info)
				{
					aux3->izq = aux1;
				}
				else
				{
					aux3->der = aux1;
				}
			}
		}
	}

	nodoarbol *devolver_raiz()
	{
		return raiz;
	}

	void despliega(nodoarbol *raiz)
	{
		if (raiz !=NULL)
		{
			despliega(raiz->izq);
			cout << raiz->info << endl;
			despliega(raiz->der);
		}
	}

	void eliminar_nodo(int valor)
	{
		nodoarbol *aux1, *aux2, *aux3, *temp;
		bool b;
		//inicio busqueda del nodo a eliminar
		if (raiz !=NULL)
		{
			aux1 = raiz;
			aux2 = NULL;
			while (aux1->info != valor)
			{
				aux2 = aux1;
				if (valor<aux1->info)
				{
					aux1 = aux1->izq;
				}else
				{
					aux1 = aux1->der;
				}

				if (aux1==NULL)
				{
					cout << "El nodo a eliminar no existe" << endl;
					break;
				}
			}
		}else
		{
			cout << "El arbol no contiene nodos" << endl;
			aux1 = NULL;
		}
		//fin de busqueda del nodo a eliminar
		//en aux1 queda la direccion del nodo a eliminar
		//en aux2 queda la direccion del nodo padre del nodo a eliminar

		if (aux1 !=NULL)
		{
			//cuando no tiene hijos
			temp = aux1;
			if ((aux1->izq==NULL)&&(aux1->der==NULL))
			{
				if (aux2 !=NULL)
				{
					if (aux1->info > aux2->info)
					{
						aux2->der = NULL;
					}else
					{
						aux2->izq = NULL;
					}
				}else
				{
					raiz = NULL;
				}
			}else
			{
				if ((aux1->izq != NULL) && (aux1->der != NULL))
				{	//cuando tiene dos hijos
					aux2 = aux1;	//con el predecesor
					temp = aux1->izq;
					b = true;
					while (temp->der !=NULL)
					{
						aux2 = temp;
						temp = temp->der;
						b = false;
					}
					aux1->info = temp->info;
					if (b == true)
					{
						aux1->izq = temp->izq;
					}else
					{
						if (temp->izq !=NULL)
						{
							aux2->der = temp->izq;
						}
						else
						{
							aux2->der = NULL;
						}
					}
				}else
				{	//cuando tiene un solo hijo
					if (aux1->izq==NULL)
					{
						if (aux2 !=NULL)
						{
							if (aux1->info<aux2->info)
							{
								aux2->izq = aux1->der;
							}else
							{
								aux2->der = aux1->der;
							}
						}else
						{
							raiz = aux1->der;
						}
					}
					else
					{
						if (aux2 !=NULL)
						{
							if (aux1->info<aux2->info)
							{
								aux2->izq = aux1->izq;
							}else
							{
								aux2->der = aux1->izq;
							}
						}else
						{
							raiz = aux1->izq;
						}
					}
				}
				delete temp;
			}
		}
	}


private:
	nodoarbol *raiz;
};

ABB::ABB()
{
}

ABB::~ABB()
{
}

 nodoarbol:: nodoarbol()
{
}


void main()
{
	nodoarbol *raiz;
	char resp;
	int valor;
	ABB n;
	do
	{	//agregar nodos
		n.insertar();
		cout << "Desea crear otro nodo (s/n): ";
		cin >> resp;
		cout << endl;
		resp = tolower(resp);
	} while (resp != 'n');
	//imprime despues de agrrgar
	cout << "los nodos del arbol (inorden) son" << endl;
	raiz = n.devolver_raiz();
	n.despliega(raiz);

	//elimiar nodos
	do
	{
		cout << "entre el valor del nodo a eliminar" << endl;
		cin >> valor;
		n.eliminar_nodo(valor);
		cout << endl;
		cout << "los nodos del arbol (inorden) son" << endl;
		raiz = n.devolver_raiz();
		n.despliega(raiz);
		cout << "Desea eliminar otro nodo (s/n): ";
		cin >> resp;
		cout << endl;
		resp = tolower(resp);
	} while (resp != 'n');
}
