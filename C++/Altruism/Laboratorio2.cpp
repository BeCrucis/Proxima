#include <iostream>
#include <math.h>
using namespace std;

class mcd
{
	int mayor, c, n3, n4;

public:
	int divisores(int c){
		short con = 1, j = 0, i;
		for (i = 1; i < c; i++)
		{
			if (n3 % i == 0)
				con++;
		}
		int div[con];
		for (i = 1; i < c; i++)
		{
			if (n3 % i == 0)
			{
				i = div[j];
				j++;
			}
		}
		con = 0;
		for (i = 0; i < j; i++)
		{
			if (n4 % div[i] == 0)
				con++;
		}
		int inter[con];
		con = 0;
		for (i = 0; i < j; i++)
		{
			if (n4 % div[i] == 0)
			{
				div[i] = inter[con];
				con++;
			}
		}
		mayor = inter[0];
		for (i = 1; i < con; i++)
		{
			if (inter[i] > mayor)
				mayor = inter[i];
		}
		return mayor;
	}
};

int main()

{
	int n1, n2, n3, n4, cop1, cop2, c;
	setlocale(LC_ALL, "spanish");

	cout << "Digite el par de numero el cual quiere conocer su maximo comun divisor"; //Mensaje de inicio
	cin >> n1 >> n2;
	cop1 = n1;
	cop2 = n2;
	n1 = abs(n1);
	n2 = abs(n2);
	if (n1 = n2) {
		cout << "El maximo coman divisor entre: " << cop1 << " y " << cop2 << " es: " << n1;
	} else {
		if (n1 > n2)
		{
			c = n1;
			n3 = n1;
			n4 = n2;
		}
		else
		{
			c = n2;
			n3 = n2;
			n4 = n1;
		}
		cout << "El mayor divisor entre " << cop1 << " y " << cop2 << " es: " << divisores(c);
	}
}
