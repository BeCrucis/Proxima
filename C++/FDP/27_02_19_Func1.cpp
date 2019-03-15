#include <iostream>
#include <conio.h>
#include <math.h>
#include <unistd.h>

using namespace std;
//TRIGONOMETRICAS, POTENCIA Y RAIZ CUADRADA
int linea, op;

void fijo(){

    string titulo = R"(   ______            __                   __               __                       
  / ____/  ____ _   / /  _____  __  __   / /  ____ _  ____/ /  ____    _____  ____ _
 / /      / __ `/  / /  / ___/ / / / /  / /  / __ `/ / __  /  / __ \  / ___/ / __ `/
/ /___   / /_/ /  / /  / /__  / /_/ /  / /  / /_/ / / /_/ /  / /_/ / / /    / /_/ / 
\____/   \__,_/  /_/   \___/  \__,_/  /_/   \__,_/  \__,_/   \____/ /_/     \__,_/  )";

    cout << titulo << endl << endl;
    system("@echo off &for /l %z in (1, 1, 90) do for /l %n in (1, 1, 9) do for /l %x in (1, 1, 9) do color %n%x & ping 127.0.0.1 -n 1 > nul");

}

void limpiaopciones(){
    system("cls");
    fijo();
}

void opciones(){
    system("color 0b");//letra Azul Fondo gris

    cout << "\n FUNCIONES DE CALCULADORA " << endl << endl;;
    cout << "1. SUMAR A Y B " << endl;
    cout << "2. MULTIPLICAR A Y B " << endl;
    cout << "3. FACTORIAL DE A " << endl;
    cout << "4. SENO DE A" << endl;
    cout << "5. COSENO DE A" << endl;
    cout << "6. RAIZ CUADRADA DE A" << endl;
    cout << "9. para TERMINAR "<< endl;
    cout << "\n\n   Digite opcion: ";
    cin >> op;
    limpiaopciones();
}

void suma(){
    float x,y,z;
    cout << "SUMA DE A Y B " << endl;
    cout << "Digite a: "; 
    cin >> x;
    cout << "Digite b: "; 
    cin >> y;
    z = x + y;
    cout << "\n\nSuma = a  " << z;
    cout << "... Enter para salir ";
    getch();
}

void producto(){
    float x,y,z;

    cout << "PRODUCTO DE A Y B " << endl;
    cout << "Digite a: ";
    cin >> x;
    cout << "Digite b: ";
    cin >> y;
    z = x * y;
    cout << "\n\nProducto: " << z;
    cout << "... Enter para salir ";
    getch();
}

long double fact(int n){ // Esto es una funcion que obtiene el factorial de un numero

    long double fac;
    int i;

    fac = 1;

    for(i = 1; i <= n; i++){
        fac = fac * i;
    }
    return fac;
}

void factorial(){

    int x, i;
    long double fac;

    cout << "Digite el numero x: ";
    cin >> x;

    fac = fact(x);

    cout << "El factorial de " << x << " es: " << fac;
    cout << "... Enter para salir ";
    getch();

}

void seno(){
     
    long double sx, x, dec;
    long double fac, pot;
    int signo = 1;
    int e = 1;
    int d = 1;
    sx = 0;

    cout << "Inserte x: ";
    cin >> x;

    for( int i = 1 ; i <= 40 ; ++i ){
    
        fac = fact(d);
        pot = pow(x,e);

        dec  = static_cast<long double>(pot)/fac;

        sx = sx + signo * dec; //Esto obtiene el seno de x
        signo *= -1;
        d += 2;
        e += 2;
    }

    cout << "El seno de " << x << " es: " << sx;
    cout << "... Enter para salir ";
    getch();
}

void coseno(){
     
    long double cx, x, dec;
    long long fac, pot;
    int signo = 1;
    int e = 0;
    int d = 0;
    cx = 0;

    cout << "Inserte x: ";
    cin >> x;

    for( int i = 1 ; i <= 40 ; ++i ){
    
        fac = fact(d);
        pot = pow(x,e);

        dec  = static_cast<long double>(pot)/fac;

        cx = cx + signo * dec; //Esto obtiene el coseno de x
        signo *= -1;
        d += 2;
        e += 2;
    }

    cout << "El coseno de " << x << " es: " << cx;
    cout << "... Enter para salir ";
    getch();
}

void raizcuadrada(){

    long double ans, x, b, i;

    cout << "Inserte x: ";
    cin >> x;

    b = x;

    for(i = 1; i <= 20; i++){
        b = ((x/b)+b)/2;
    }

    cout << "La raiz de " << x << " es: " << b;
    cout << "... Enter para salir ";
    getch();
}



int main(){
    fijo();

    do{

	opciones();

	switch(op){   
        case 1:{ 
            suma();
            limpiaopciones();
            break;
            }
		case 2:{ 
            producto();
            limpiaopciones();
            break;
            }
		case 3:{ 
            factorial();
            limpiaopciones();
            break;
            }
        case 4:{ 
            seno();
            limpiaopciones();
            break;
            }
        case 5:{ 
            coseno();
            limpiaopciones();
            break;
            }
        case 6:{ 
            raizcuadrada();
            limpiaopciones();
            break;
        }
	       	  


	                  
	      }
  }
  while(op != 9);


}