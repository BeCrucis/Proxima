#include <iostream>
#include <iomanip>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {
	int x[10][10], y[10][10], z[10][10], lx, cx, ly, cy, lz, cz, vc;

	//Esto es un cambio4

	cout << "Inserte la cantidad de filas de su matriz x: ";
	cin >> lx;
	cout << "Inserte la cantidad de columnas de su matriz x: ";
	cin >> cx;

	for (int i = 1; i <= lx; i++) {
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

		for (int n = 1; n <= cx; ++n) {

			cout << "---------";
		}
		cout << endl;
	}

	cout << "Inserte la cantidad de filas de su matriz y: ";
	cin >> ly;
	cout << "Inserte la cantidad de columnas de su matriz y: ";
	cin >> cy;

	if (cx != ly) {
		cout << "Matrices incompatibles, saliendo . . ." << endl;
		system("pause");
		return 1;
	}


	for (int i = 1; i <= ly; i++) {
		for (int j = 1; j <= cy; j++) {
			cout << "Inserte la coordenada [" << i << "][" << j << "] : ";
			cin >> y[i][j];
		}
	}

	cout << "Su matriz es: " << endl;
	for (int i = 1; i <= ly; ++i) {
		for (int j = 1; j <= cy; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(5)<< y[i][j] << " |";
		}

		cout << endl;

		for (int n = 1; n <= cy; ++n) {

			cout << "---------";
		}
		cout << endl;
	}

	//Ahora multiplicamos

	lz = lx;
	cz = cy;

	for (int i = 1; i <= lz; i++) {

		for (int j = 1; j <= cz; j++) {
			int vx = 0;
			for (int m = 1; m <= cx; m++) {
				vc = x[i][m] * y[m][j];
				vx = vx + vc;
			}

			z[i][j] = vx;
		}
	}

	//Ahora sacamos la matriz

	cout << endl << endl << endl;

	cout << "Su matriz resultado es: " << endl;
	for (int i = 1; i <= lz; ++i) {
		for (int j = 1; j <= cz; ++j) {
			cout << right << setw(2) << "| "
				<< right << setw(5) << z[i][j] << " |";
		}

		cout << endl;

		for (int n = 1; n <= cz; ++n) {

			cout << "---------";
		}
		cout << endl;

	}

	system("pause");
}
