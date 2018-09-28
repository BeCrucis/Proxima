//PARA UNA MATRIZ DE DIMENSION N*M CALCULE EL PROMEDIO DE LOS VALORES UBICADOS EN LAS POSICIONES TALES QUE 
//I+J SEA PAR ASI MISMO HALLE LA MEDIA DE LOS VALORES IMPARES UBICADOS EN LAS POSICIONES I+J IMPARES DONDE I ES LA FILA Y J LA COLUMNA

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

using namespace std;

void mostrar(int x[][10], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(5) << x[i][j] << " |";
		}

        cout << endl;

        for (int n = 1; n <= cx; ++n) {

			cout << "---------";
		}
		

		cout <<  endl;
    }

    
    
}

int main(){

    int lx, cx, x[10][10], ap, ai, cp, ci; 
    float rp, ri;

    cout << "Inserte la cantidad de filas de su matriz x: "; //Empezamos pidiendo parametros de la matriz
	cin >> lx;
	cout << "Inserte la cantidad de columnas de su matriz x: ";
	cin >> cx;

	for (int i = 1; i <= lx; i++) { //Pide que se inserte la matriz   
		for (int j = 1; j <= cx; j++) {           
            cout << "Inserte la variable en [" << i << "][" << j << "] : ";
            cin >> x[i][j];
		}
	}

    mostrar(x, cx, lx, "Su matriz es: "); //Muestra la matriz insertada

    ap = 0; //Establezco variables de almacenamiento
    cp = 0;
    ai = 0;
    ci = 0;

    for (int i = 1; i <= lx; i++) { //Analiza elementos de la matriz  
		for (int j = 1; j <= cx; j++) {           
            
            if((i + j) % 2 == 0){ //Si i + j es par
                ap += x[i][j];
                cp += 1;
            }

            else if((i + j) % 2 == 1 && x[i][j] % 2 == 1){ //Si i + j es impar y el elemento que contiene tambien
                ai += x[i][j];
                ci += 1;
            }
		}
	}

    rp = ap / (float)cp;
    ri = ai / (float)ci;

    cout << "El promedio de elementos donde I + J es par es: " << rp << endl;
    cout << "El promedio de elementos donde I + J es impar y su valor tambien es: " << ri << endl;
    system("pause");
    return 0;
}