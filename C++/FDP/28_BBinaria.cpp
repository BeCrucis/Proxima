#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int v[100], n, y, i, vi, vf, vm, l;
	cout << "Introduzca el valor de N: ";
	cin >> n;
	cout << "Introduzca el valor de Y: ";
	cin >> y;
	for (i = 1; i <= n; i++) {
		cout << "Inserte el valor de V en la posicion " << i << ": ";
		cin >> v[i];

	}

	vi = 1;
	vf = n;
	l = 0;

	while (l < 3) {

		vm = (vi + vf) / 2;

		if (v[vm] == y) {
			cout << "He encontrado Y en la posicion: " << vm << endl;
			system("pause");
			return 0;
		}

		else if (v[vm + 1] == y) {
			cout << "He encontrado Y en la posicion: " << vm + 1 << endl;
			system("pause");
			return 0;
		}

		else if (v[vm - 1] == y) {
			cout << "He encontrado Y en la posicion: " << vm - 1 << endl;
			system("pause");
			return 0;
		}

		else if (y < v[vm]) {
			vf = vm;
		}

		else {
			vi = vm;
		}

		if ((vf - vi) < 2) {
			l += 1;
		}

	}

	cout << "valor Y no encontrado" << endl;
	system("pause");
	return 0;
}
