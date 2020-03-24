#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>

using namespace std;

int main(){

    double numero;

    cout << "Comprobacion de raiz de newton!" << endl;
    
    cout << "Inserte el numero cuya raiz se obtendrá: ";
    cin >> numero;

    // Obteniendo raiz por newton
    double raizNewton;
    int iteraciones;

    raizNewton = numero;
    iteraciones = 5; //A mayor numero, mayor precision

    for(int i = 1; i < iteraciones; i++){
         raizNewton = (0.5)*((numero/raizNewton)+raizNewton);
    }

    // Obteniendo raiz por el computador
    double raizComputador;

    raizComputador = sqrt(numero);

    cout << "Raiz por Newton: "<<raizNewton<< endl;
    cout << "Raiz por Computador: "<<raizComputador<< endl;
    
}