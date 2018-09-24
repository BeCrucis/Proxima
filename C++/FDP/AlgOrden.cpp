#include <iostream> //8919109wpg
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

void inter(int x[], int len) {

	int temp, d;
	bool orden;

	do {
		orden = 1;
		for (d = 0; d < len - 1; ++d) {
			if (x[d] > x[d + 1]) {
				temp = x[d];
				x[d] = x[d + 1];
				x[d + 1] = temp;
				cout << x[d+1] << " Fue cambiado con " << x[d] << endl;
			}
		}


		for (d = 0; d < len - 1; ++d) {
			if (x[d] > x[d + 1]) {
				orden = 0;
			}
		}
	}
	while(orden == 0);

			cout << "Su conjunto ordenado es:";

			for (d = 1; d <= len; ++d) {

				cout << left << setw(3) << "" << x[d - 1];
			}

			cout << endl;

}

void menor(int x[], int len) {

	int d,i,p,menor, y[100];

	for (i = 0; i < len; ++i) {

		menor = 999;

		for (d = 0; d < len; ++d) {
			if (x[d] < menor) {
				p = d;
				menor = x[d];
			}
		}

		y[i] = menor;
		x[p] = 999;
	}

	cout << "Su conjunto ordenado es:";

	for (d = 1; d <= len; ++d) {

		cout << left << setw(3) << "" << y[d - 1];
	}

	cout << endl;

}

void binar(int x[], int len){
	int bc = 2, lenc = len;

	auto compare = [](int x[], int pos){ if(x[pos] < x[pos+1]){ return pos;}else{return pos+1;}};

	while(bc < len){
		bc = bc * 2;
	}

	while(bc > lenc){
		x[lenc] = 999;
		lenc += 1;
	}

	int y[lenc/2];
	int compos = 0;

	for(int i = 0;i < lenc/2; i +=1){
		y[i] = compare(x,compos);
		compos +=2;
	}

	cout << y[0] << " y " << y[1] << endl;
}

int recur(int x[], int lenc, int pos){

	auto compare = [](int x[], int pos){ if(x[pos] < x[pos+1]){ return pos;}else{return pos+1;}};
	int y[lenc];

	if(lenc <= 2){
		return compare(x, pos);
	}

}
int main() {

	int len, input, d;
	int x[100];

	cout << "Este programa ordenara tu secuencia de numeros!" << endl << endl;

	cout << "Inserte el largo de su conjunto: ";
	cin >> len;
	system("cls");

	for (d = 1; d <= len; ++d) {

		cout << "Inserte un numero: ";
		cin >> input;
		x[(d - 1)] = input;
		system("cls");


	}

	cout << "Su conjunto es: ";

	for (
		d = 1; d <= len; ++d) {

		cout << left << setw(3) << x[d - 1];
	}

	cout << endl;
	in:
	cout << "Elija un metodo de ordenado (1 : De menores, 2 : Intercambio, 3 : Binario): ";
	cin >> input;
	switch (input) {

	case 1: menor(x, len);
		break;
	case 2: inter(x, len);
		break;
	case 3: binar(x, len);
		break;

	default: goto in;
	}

	cout << endl;
	system("pause");
	return 0;

}
