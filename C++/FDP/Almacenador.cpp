
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	while(true){

		int N, co, cif,i, cont = 0, divi = 0;
		cout << "Digite un numero: ";
		cin >> N;

		if(N < 0){
			return;
		}
		while (N > 0)
		{
			co = N / 10;
			cif = N - 10 * co;
			N = co;
			cont = cont + cif;
		}
		cout << cont << endl;

		for (i=1; i<=cont; i++)
		{
			if (cont %i == 0)
			{
				divi = divi + 1;
			}
		
		}
		if (divi==2)
		{
			cout << "es primo" << endl;

		}
		else
		{
			cout << "No es primo" << endl;
		}

		system("pause");
		system("cls");
	}

}
