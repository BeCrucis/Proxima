//Implementación de la clase Fila
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct nodo
{
	int dato;
	nodo *sig;
};

class Queue
{
    //insercion, supresion, inspeccion
	private:
		nodo *front;
		nodo *back;
	public:
		Queue();
		~Queue();
		void enqueue();
		void dequeue();
		void clear();
		void showQueue();
		int getFront();
		int size();
};

Queue::Queue()
{
    front = NULL;
	back = NULL;
}

Queue::~Queue()
{
    nodo *apunt;
	apunt = front;
	while (apunt != NULL)
	{
		front = apunt->sig;
		delete apunt;
		apunt = front;
	}
	cout << "Destructor implementado" << endl;
}

void Queue::enqueue()
{    
    nodo *actual;
    actual = new nodo();
	cout << "Entre la clave del nodo a agregar" << endl;
	cin>>actual->dato;

	if (front == NULL){
		// Agrega el primer nodo
		actual->sig = NULL;
		front = actual;
		back = actual;
	} else {
		// Agrega el resto de nodos
		back->sig = actual;
		back = actual;
	}

}

void Queue::dequeue()
{
    if (front != NULL)
    {
        int data = front->dato;
        front = front->sig;
        if (front == NULL)
        {
            back = NULL;
        }
        cout << "Se elimino el nodo que contenia el dato: " << data << endl;
    }
    else cout << "No hay lista" << endl;
}

void Queue::clear()
{
    nodo *aux;
	aux = front;
    if (front == NULL)
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        while (aux != NULL)
        {
            front = aux->sig;
            delete aux;
            aux = front;
        }
        cout << "Lista eliminada" << endl;
    }
}

void Queue::showQueue()
{
    nodo *apunt;
    apunt = front;
    if(front == NULL)
	{
		cout<<"La lista esta vacia"<<endl;
	}
	else
	{
		cout << "La lista deplegada es:" << endl;
		while(apunt != NULL)
		{
			cout<<apunt->dato << endl;
			apunt=apunt->sig;
		}
	}
}

int Queue::getFront()
{
    int data = 0;
    if (front != NULL) 
    {
        data = front->dato;
        return data;
    }
    else
    {
        cout << "No hay lista " << endl;
        return 0;
    }
}

int Queue::size()
{
    nodo *aux = new nodo();
    int lenght = 0;

    if (front != NULL)
    {
        aux = front;
        while (aux != NULL)
        {
            aux = aux->sig;
            lenght = lenght + 1;
        }
        return lenght;
    }
    else
    {
        cout << "No hay lista" << endl;
        return 0;
    }
}

int main(){
	int opc;
	Queue l;
	do
	{
		cout << "Bienvenido al menu de Fila (o queue)" << endl;
		cout << "A continuacion seleccione la opcion que desee realizar:" << endl;
		cout << "(1) Agregar a la fila" << endl;
		cout << "(2) Eliminar de la fila" << endl;
		cout << "(3) Limpiar fila" << endl;
		cout << "(4) Mostrar frente de la fila" << endl;
		cout << "(5) Mostrar longitud de fila" << endl;
		cout << "(6) Mostrar fila" << endl;
		cout << "(7) Salir" << endl;

		cin >> opc;
		system("cls");
		
		switch (opc)
		{
			case 1:
				l.enqueue();			
				system("pause");
				system("cls");
				break;

			case 2:
				l.dequeue();
				system("pause");
				system("cls");
				break;

			case 3:
				l.clear();
				system("pause");
				system("cls");
				break;

            case 4:
                cout << "El valor del dato inicial es: " << endl;
				cout << l.getFront() << endl; 
				system("pause");
				system("cls");
				break;

            case 5:
                cout << "La longitud de la fila es: " << l.size() << endl;
				system("pause");
				system("cls");
				break;

            case 6:
				l.showQueue();
				system("pause");
				system("cls");
				break;

			case 7:
				break;

			default:
				cout << "Ingrese una opcion valida" << endl;
				system("pause");
				system("cls");
				continue;
		}
	}while (opc != 7);
}