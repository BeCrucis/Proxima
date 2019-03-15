/*Ejercicio de matrices solucion 1: 
Insertar n numeros, dividir en vector de pares e impares y luego insertarlos en una matriz correspondiente de 5x5,
los espacios sobrantes en la matriz par seran iguales a 2, los sobrantes en la matriz impar iguales a 3

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

void mostrar(int x[][5], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

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

    int vp[25], vi[25];
    int mp[5][5], mi[5][5];
    int input, i, j, n, ip, ii, imp, imi;

    ip = 1;
    ii = 1;

    cout << "Inserte la cantidad de numeros que va a insertar: ";
    cin >> n;

    for(i = 1; i <= n; i++){
        
        cout << "Inserte un numero: ";
        cin >> input;

        if((input % 2) == 0){

            cout << "El numero insertado es par!" << endl;

            if(ip <= 25){
                vp[ip] = input;
                ip++;
            }
            
        }

        else{

            cout << "El numero insertado es impar!" << endl;

            if(ii <= 25){
                vi[ii] = input;
                ii++;
            }
            
        }
    }

    //Creo las matrices

    imp = 1;
    imi = 1;

    for(i = 1; i <= 5; i++){
        for(j = 1; j <= 5; j++){

            if(imp < ip){

                mp[i][j] = vp[imp];
                imp++;

            }

            else{
                mp[i][j] = 2;
            }
            
            if(imi < ii){

                mi[i][j] = vi[imi];
                imi++;

            }

            else{
                mi[i][j] = 3;
            }
        }
    }

    mostrar(mp, 5, 5, "Matriz de pares: ");
    mostrar(mi, 5, 5, "Matriz de impares: ");

    system("pause");
}