#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main(){
    int a[100], b[100], c[200], n, temp;
    bool ordena, ordenb;

    cout << "Bienvenido a su intercalador de vectores!"<< endl << endl
         << "Inserte la cantidad de valores de sus vectores: ";
    
    cin >> n;

    for(int i = 0; i < n; ++i){
        cout << "Inserte el valor " << i << " del vector a: ";
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        cout << "Inserte el valor " << i << " del vector b: ";
        cin >> b[i];
    }

    for (int i = 0; i < n - 1; ++i) {
			if (a[i] > a[i + 1]) {
				ordena = false;
                cout << "El conjunto a esta desordenado, ordenando . . ." << endl;
			}
		}

    if(ordena == false){

        do {
            ordena = true;
            for(int i = 0; i < n - 1; ++i){
                if(a[i] > a[ i + 1]){
                    temp = a[i + 1];
                    a[i + 1] = a[i];
                    a[i] = temp;

                }
            }

            for (int i = 0; i < n - 1; ++i) {
			if (a[i] > a[i + 1]) {
				ordena = false;
			}
		}

        } while(ordena == false);  
            
    }   

    for (int i = 0; i < n - 1; ++i) {
			if (b[i] > b[i + 1]) {
				ordenb = false;
                cout << "El conjunto b esta desordenado, ordenando . . ." << endl;
			}
		}

    if(ordenb == false){

        do {
            ordenb = true;
            for(int i = 0; i < n - 1; ++i){
                if(b[i] > b[ i + 1]){

                    temp = b[i + 1];
                    b[i + 1] = b[i];
                    b[i] = temp;

                }
            }

            for (int i = 0; i < n - 1; ++i) {
                if (b[i] > b[i + 1]) {

                    ordenb = false;

                }
		    }

        } while(ordenb == false);  
            
    }

    int k = 0;
    for(int i = 0; i < 2*n; ++i){

        c[k] = a[i];
        c[k+1] = b[i];
        k += 2;
    }

    cout << endl << "Su conjunto ordenado es: ";

	for (int d = 1; d <= 2*n; ++d) {

	cout << left << setw(3) << "" << c[d - 1];
	}
}