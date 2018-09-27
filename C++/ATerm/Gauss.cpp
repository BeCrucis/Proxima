#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>

using namespace std;

int main(){

    double x[10][10], y[10][10];
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
    for(int i = 1; i <= lx; ++i){
        for(int j = 1; j <= cx; ++j){

            if(i == j || x[i][j] != 1){

                for(int k = 1; k <= cx; ++k){
                    x[i][k] = x[i][k] * (1/x[i][j]);
                    
                }
            }
        }
    }

    cout << endl << endl << "Resultado: " << endl;
    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(5) << x[i][j] << " |";
		}

		cout << endl;
    }

    system("pause");
}