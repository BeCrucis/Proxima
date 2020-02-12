#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    int n, x;

    cout << "Inserte N: ";
    cin >> n;
    

    cout << "Inserte su numero X: ";
    cin >> x;
    
    // El modulo a continuación obtendra el numero de cifras de un numero

    int cifras = 1;
    int regulador = 1; // El regulador busca ser un numero mayor a x una vez x tenga una cifra menos que el regulador

    while (x > regulador){
        int a;
        cifras += 1; //Esto es equivalente a cifras = cifras + 1
        regulador *= 10; //Esto es equivalente a regulador = regulador * 10
    }

    // El modulo a continuacion obtendra la suma de cifras del numero X

    int suma = 0;
    int divisor = regulador;
    int temp = x;
    int digito;

    while (divisor > 0){
        digito = temp / divisor;
        temp -= digito * divisor;
        cout << "Digito encontrado: " << digito << endl;
        suma += digito;
        divisor /= 10;
    }

    cout << suma << endl;

    // El modulo a continuacion determinara si suma es primo


}