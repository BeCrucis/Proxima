/*Ejercicio de matrices solucion 1: 
Insertar n numeros, crear una matrix 5x5 de pares con un 2 en cada fila y columna, y crear una de impares con un 3 en cada fila y columna,
los numeros insertados luego son colocados en su matriz correspondiente en funcion de que sean pares o impares

HECHO POR:

Edward Javier Parada Silva - 2182070
Juan Sebastian Vanegas Rico - 2182071
Dubian Palacios - 2182063
Mauricio Alejandro Romero - 2182049

*/
#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void mostrar(int x[][6], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int n = 1; n <= cx; ++n) {

		cout << "--------------";
		}
		cout << endl;

    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
			<< right << setw(10) << x[i][j] << " |";
		}

        cout << endl;
        for (int n = 1; n <= cx; ++n) {

		cout << "--------------";
		}

		cout << endl;
    }
		cout << endl;

}

int main(){

    int mp[6][6], mi[6][6];
    int input, i, j, n, ip, ii, lmp, cmp, lmi, cmi;

    lmp = 1;
    cmp = 1;

    lmi = 1;
    cmi = 1;

    ip = 1;
    ii = 1;

    cout << "Inserte la cantidad de numeros que va a insertar: ";
    cin >> n;

    //Creacion de matrices
    for(i = 1; i <= 5; i++){
        for(j = 1; j <= 5; j++){
            mp[i][j] = 2;
            mi[i][j] = 3;
        }
    }

    for(i = 1; i <= n; i++){
        
        cout << "Inserte un numero: ";
        cin >> input;

        if((input % 2) == 0){

            cout << "El numero insertado es par!" << endl;

            if(ip <= 25){

                if(cmp > 5){
                    cmp = 1;
                    lmp += 1;
                }
                
                mp[lmp][cmp] = input;
                ip += 1;
                cmp += 1;

            }
            
        }

        else{

            cout << "El numero insertado es impar!" << endl;

            if(ii <= 25){

                if(cmi > 5){
                    cmi = 1;
                    lmi += 1;
                }
                
                mi[lmi][cmi] = input;
                ii += 1;
                cmi += 1;

            }
            
        }
    }

    mostrar(mp, 5, 5, "Matriz de pares: ");
    mostrar(mi, 5, 5, "Matriz de impares: ");

    system("pause");
}