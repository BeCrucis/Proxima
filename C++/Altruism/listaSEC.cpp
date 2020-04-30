#include <conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include "iostream"

using namespace std;
struct nodo
{
    int dato;
    nodo*sig;
};
class Lsec
{
	private:
		nodo *inicial;
		nodo *buscarLista(int clave);
		nodo *buscarUltimo();
	public:
		Lsec();
		~Lsec();
		void agregar();
		void eliminar();
		void desplegarLista();
};
Lsec::Lsec()
{
	inicial=NULL;
}
Lsec::~Lsec()
{
	nodo *apunt;
	apunt = inicial;
	do
	{
		cout<<"borro"<<endl;
	 inicial=apunt->sig;
	 delete apunt;
	 apunt = inicial->sig;
    }while(apunt!=inicial);
}
void Lsec::desplegarLista()
{
	nodo *apunt;
	if(inicial==NULL)
	{
		cout<<"la lista esta vasia"<<endl;
	}
	else 
	{
		apunt=inicial;
		do
		{
			cout<<apunt->dato<<" "<<endl;
			apunt=apunt->sig;
		}while(apunt!=inicial);
	}
	cout<<endl;
}
nodo *Lsec::buscarUltimo()
{
	nodo *ultimo;
	ultimo=inicial;
	while(ultimo->sig!=inicial)
	{
		ultimo=ultimo->sig;
	}
	return ultimo;
}
nodo *Lsec::buscarLista(int clave)
{
	//devuelve la direccion del nodo que antecede al nuevo
	//nodo que va a ser agregado, o que va a ser eliminado.
	//si la clae es menor o igual al dato del primer nodo
	//el valor devuelto es NULL
	
	//si la clave es mayor que el dato del ultimo nodo
	//devuelve la direccion del ultimo nodo
	nodo*anterior;
	anterior=NULL;
	if(clave<=inicial->dato)
	{
	 return anterior;
    }
    else 
    {
    	anterior=inicial;
    	while( (clave > anterior->sig->dato) && (anterior->sig!=inicial))
    	{
    		anterior=anterior->sig;
		}
		return anterior;
    }
}
void Lsec::agregar()
{
	nodo *nuevo, *anterior, *apunt;
	char resp;
	int cont=0;
	do
	{
		nuevo=new nodo();
		cout<<"entre clave del nodo a agregar"<<endl;
		cin>>nuevo->dato;
		if(inicial==NULL)
		{
			//agrega al primer nodo de la lista se apunta asi mismo
			inicial=nuevo;
			nuevo->sig=nuevo;
		}
			else
		{
			//
			 apunt=inicial;
        while(apunt!=NULL){
        	if(apunt->dato==nuevo->dato){
        		cont=1;
        		cout<<"Elemento encontrado (Ya existe y no se puede agg)!!!"<<endl;
        		break;
        	}
        	apunt=apunt->sig;
        }
		
		if(cont==0){
			 
			 //
			 anterior=buscarLista(nuevo->dato);
			 
			if(anterior==NULL)
			{
				//agrega un nodo que queda de primero
				//en una lista que no estaba vacia
				
				nuevo->sig=inicial;
				inicial=nuevo;
			}
			else
			{
				//agrega un nodo que no queda de primero en la lista
				nuevo->sig=anterior->sig;
			    anterior->sig=nuevo;
				
			}
		}
		cout<<"Desea agregar otro nodo? (s/n)"<<endl;
		cin>>resp;
		resp=tolower(resp);
	}
	}while (resp=='s');
}
void Lsec::eliminar()
{
   int clave,cont=0;;
   char resp;
   nodo *anterior,*ultimo,*elimina,*apunt;
   ultimo=buscarUltimo();
   do 
    {
        cout<<endl;
        cout<<"Entre el dato del nodo a eliminar"<<endl<<endl;
        cin>>clave;
        
        if(inicial->dato==clave)
       {
       	ultimo->sig=inicial->sig;
        elimina = inicial;
        inicial = inicial->sig;
        
        delete elimina;
       }
       
       else
      {
      	apunt = inicial;
        while(apunt!=NULL){
        	if(apunt->dato==clave){
        		cont=1;
        		cout<<"Elemento encontrado!!!"<<endl;
        		break;
        	}
        	apunt=apunt->sig;
        }
      	if(cont==1){
      		
    	 anterior=buscarLista(clave);
    	 if(anterior!=NULL)
			{
				
			 elimina = anterior->sig;
             anterior->sig = elimina->sig;
             delete elimina;
            }
            
			
      	}
      	else
           {
           	 cout<<"El nodo a eliminar no existe"<<endl;
        }
       }
        
        
        cout<<"DESEA ELIMINAR OTRO NODO? (s/n)"<<endl;
        cin>>resp;
        resp=tolower(resp);
    }while(resp!='n');
}
void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}
int main()
{
	bool k=false;
	char a;
	Lsec j;
	do
	{
	system("cls");
	cin.clear();
	cout<<"      --LISTA SIMPLEMENTE ENCADENADA CIRCULAR--"<<endl<<endl;
	cout<<" 1.Agregar nodo"<<endl;
    cout<<" 2.Mostrar lista"<<endl;
	cout<<" 3.Eliminar nodo"<<endl;
	cout<<" 4.Salir"<<endl<<endl;
	cout<<" DIGITE EL NUMERO DE LA OPCION QUE DESEA:";
	cin>>a;
	switch(a)
	{
		case '1':
			system("cls");
	        j.agregar();
	        pausa();
	    break;
	    case '2':
	    	system("cls");
	        j.desplegarLista();
	        pausa();
	    break;
	    case '3':
	    	system("cls");
	        j.eliminar();
	        pausa();
	    break;
	    case '4':
	    	system("cls");
	        k=true;
	    break;
	    default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
    }
}while(k!=true);
	
	return(0);
}
