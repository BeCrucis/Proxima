#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class nodo{

    public:
    nodo* siguiente;
    int valor;
};

int main(){

    nodo primero = nodo();
    primero.valor = 5;

    nodo segundo = nodo();
    segundo.valor = 10;

    primero.siguiente = &segundo;

    cout << primero.valor << endl;
    
    cout << primero.siguiente << endl;
    cout << (primero.siguiente)->valor << endl;

}