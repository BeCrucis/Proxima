#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main(){

    int v[100], n, y, i, vi, vf, vm, l;
	cout << "Introduzca la cantidad de elementos del vector: ";
	cin >> n;
	cout << "Introduzca el valor a buscar: ";
	cin >> y;
	for (i = 1; i <= n; i++) {
		cout << "Inserte el valor de v en la posicion " << i << ": ";
		cin >> v[i];

	}

    for(int i = 1; i<=n; ++i){
        if(v[i] == y){
            cout << "He encontrado Y en la posicion "<< i << endl;
            system("pause");
            return 0;
        }
    }

    cout << "El valor Y no ha sido encontrado"<< endl;
    system("pause");
    return 0;
}