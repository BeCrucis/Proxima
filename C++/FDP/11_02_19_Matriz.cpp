#include <iostream> //dc124a28bb7194a05002cf4a307ab2b9b3ecde74
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std; 

void mostrar(int x[][20], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int n = 1; n <= cx; ++n) {

		cout << "-------";
		}
	cout << endl;

    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
			<< right << setw(3) << x[i][j] << " |";
		}

        cout << endl;
        for (int n = 1; n <= cx; ++n) {

		    cout << "-------";
		}

		cout << endl;
    }
	cout << endl;

}

int main(){

    int n, m[20][20], dato, j, i, cp;
    string ba;
    int fac;
    int a = 100;

    cout << "Inserte la cantidad de datos que va a insertar: ";
    cin >> n;

    if(n > 20){
        cout << "No se puede crear la matriz" << endl;
        system("pause");
        return 1;
    }

    ba = to_string(a);

    for(i = 1; i <= n; i++){

        cout << "Inserte el dato numero [" <<i<< "]: ";
        cin >> dato;
        m[i][1] = dato;

        fac = 1;
        for(j = 2; j <= dato; j++){
            fac = fac * j;
        }

        cout << fac << endl;
        m[i][2] = fac;

        cp = 0;
        for(j = 4; (cp < 18); j+= 2){

            if(j <= dato){
                m[i][cp + 3] = j;
            }
            
            else{
                m[i][cp + 3] = 0;
            }
            cp += 1;
        }
    }

    mostrar(m, 20, n, "El resultado es: ");
    system("pause");
}

