#include <iostream>
using namespace std;

struct nodo
{
	int codigo;
	char *nombre;
	int nivel;
	nodo *sig;
};

class linkedList
{
	nodo *head,*tail;
	public:
		linkedList()
		{
			this->head = NULL;
			this->tail = NULL;
		}
		~linkedList()
		{
			while(this->head != this->tail->sig)
			{
				nodo *aux = this->head;
				this->head = this->head->sig;
				cout<<"Deleting "<<aux->codigo<<endl;
				delete aux;
			}
		}
		void reader(nodo *toFill)
		{
			cout<<"Enter the student code: "<<endl;
			cin>>toFill->codigo;
			cout<<"Enter the student name: "<<endl;
			cin.ignore();
			toFill->nombre = new char [30];
			cin.getline(toFill->nombre,30);
			cout<<"Enter the student level: "<<endl;
			cin>>toFill->nivel;
		}
		void createLinkedList()
		{
			nodo *newNode = new nodo();
			newNode -> sig = NULL;
			if(this -> tail == NULL)
			{
				reader(newNode);
				this -> head = newNode;
				this -> tail = newNode;
				cout<<"the student with code  "<<newNode->codigo<<" was successfully added."<<endl;
			}
			else
			{
				this -> tail -> sig = newNode;
				this -> tail = newNode;
				reader(newNode);
                cout<<"Adding a new student..."<<endl;
				cout<<"the node with code "<<newNode->codigo<<" was successfully added."<<endl;
			}
		}
		nodo * addNode(nodo *exchange,int code)
		{
			nodo *newNode = new nodo();
			if(code == 0 || exchange == this->head)
			{
				newNode->sig = this->head;
				this->head = newNode;
				reader(newNode);
				return this->head;
			}
			else
			{
				reader(newNode);
				newNode->sig = exchange->sig;
				if(exchange->sig == NULL)
				{
					this->tail = newNode;
				}
				exchange->sig = newNode;
				return newNode;
			}
			
		}
        void printInf(nodo *dato)
        {
			if(dato->sig != this->head)
			{
				cout<<"Codigo: "<<dato->codigo<<endl;
				cout<<"El nombre es: "<<dato->nombre<<endl;
				cout<<"Nivel: "<<dato->nivel<<endl;
			}	
        }
        void travel()
        {
            nodo *traveler = new nodo();
            *traveler = *this->head;
            while(traveler != NULL)
            {
				printInf(traveler);
				traveler = traveler -> sig; 
            };
        }
		nodo * search(int code)
		{
			nodo *matched = new nodo();
			*matched = *this->head;
			while(matched != NULL)
			{
				if(matched->codigo == code)
				{
					return matched;
				}
				else
				{
					matched=matched->sig;
				}
			}
			return NULL;
		}
        void quit(int code)
        {
            nodo *aux = this->head;
            nodo *aux1 = new nodo();
            if(this->head->codigo == code)
            {
                this->head = aux->sig;
                cout<<"deleting "<<aux->codigo<<endl;
                delete aux;
            }
            else
            {
               while(aux != NULL)
                {
                    if(aux->sig->codigo == code)
                    {
                        if(this->tail->codigo == code)
                        {
                            this->tail = aux;
                        }
                        aux1 = aux->sig; 
                        aux->sig = aux->sig->sig;
                        cout<<"deleting "<<aux1->codigo<<endl;
                        delete aux1;
                        return;
                    }
                    aux = aux->sig;
                } 
                cout<<"The student wasn't found."<<endl;
            }
        }
};
int main()
{
	char resp;
	int codigo;
	linkedList *list = new linkedList;
	do
	{
		list->createLinkedList();
		cout<<"Do you want to add another student?? (y/n): ";
		cin>>resp;
		resp = tolower(resp);
	}while(resp != 'n');
    cout<<"The created list is: "<<endl<<endl;
    list->travel();
	do
	{
		cout<<"Enter the key code (Enter 0 if you want to add a new head to the list, "<<endl;
		cout<<"otherwise, enter the code of the previous student)"<<endl<<endl;
		cin>>codigo;
		if(codigo == 0)
		{
			list->addNode(NULL,0);
		}
		else
		{
			nodo *aux = new nodo();
			aux = list->search(codigo);
			if(aux != NULL)
			{
				list->addNode(aux,codigo);
			}
			else
			{
				cout<<"The student wasn't found."<<endl;
			}
		}
		cout<<"Do you want to add another student? (y/n)"<<endl;
		cin>>resp;
		resp = tolower(resp);
	} while (resp != 'n');
	cout<<"The list after the modification is:"<<endl<<endl<<endl;
	list->travel();
    do
    {
        cout<<"Enter the code of the student to eliminate: "<<endl;
        cin>>codigo;
        list->quit(codigo);
        cout<<"Do you want to eliminate another student? (y/n)"<<endl;
        cin>>resp;
    } while(resp != 'n');
    cout<<"The list after the eliminations is: "<<endl<<endl;
    list->travel();

    delete list;
	system("pause");
	return 0;
}