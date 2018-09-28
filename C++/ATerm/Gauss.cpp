#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>

using namespace std;

int main(){

    double x[10][10], di, nm;
    int lx, cx, cc;

    cout << "Inserte la cantidad de filas de su matriz x: ";
	cin >> lx;
	cout << "Inserte la cantidad de columnas de su matriz x: ";
	cin >> cx;

    cx = cx + 1;

	for (int i = 1; i <= lx; i++) {
        cc = 0;
		for (int j = 1; j <= cx; j++) {
     
            cout << "Inserte la coordenada [" << i << "][" << j << "] : ";
			cin >> x[i][j];
            
		}
	}

	cout << "Su matriz es: " << endl;
	for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(5) << x[i][j] << " |";
		}

		cout << endl;
    }
//WIP
    cc = 1; //Columna clave, columna en que debe aparecer un 1 en la matriz en funcion de la fila analizada
    for(int i = 1; i <= lx;++i ){
        if(cc == i || x[i][cc] != 1){ // Verifico si la coordenada es 1, si no lo es, multiplico toda la fila por su inversa

            di = 1/x[i][cc]; //Inversa del punto de la matriz que debe convertirse en 1

            for(int j = 1; j <= cx; ++j){

                x[i][j] = x[i][j] * di; //Se multiplica toda la fila por esta inversa

            }
   
        }

        for (int n = 1;n <= lx; ++n ){

            if(n != i){
                nm = x[i][cc] * x[n][cc] * -1;
                x[n][cc] = (x[i][cc] * nm) + x[n][cc];
            }
        }
    cc += 1;
    }


    cout << endl << endl << "Resultado: " << endl;
    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(9) << x[i][j] << " |";
		}

		cout << endl;
    }

    system("pause");
}