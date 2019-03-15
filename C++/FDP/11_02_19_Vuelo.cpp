#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void mostrar(int x[][4], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int n = 1; n <= cx; ++n) {

		cout << "-------";
		}
		cout << endl;

    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
			<< right << setw(5) << x[i][j] << " |";
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

    int v[100][4], aviones[10][4], ciudades[20][4];
    int i, j, n, vuelo, ciudad, pasajeros, max, comp, cmax, amax;
    double prom;

    cout << "Inserte la cantidad de vuelos que va a analizar: ";
    cin >> n;

    //Crear una matriz con informacion de cada avion
    for(i = 1; i <= 10; i++){

        aviones[i][1] = i; //Codigo de avion
        aviones[i][2] = 0; //Cantidad de vuelos
        aviones[i][3] = 0; //Cantidad de pasajeros totales
    }

    //Crear una matriz con informacion de cada ciudad
    for(i = 1; i <= 20; i++){

        ciudades[i][1] = i; //Codigo de ciudad
        ciudades[i][2] = 0; //Cantidad de vuelos
        ciudades[i][3] = 0; //Cantidad de pasajeros totales
    }

    //Llenar la matriz de viajes
    for(i = 1; i <= n; i++){

        cout << "["<<i<<"] Inserte el codigo de avion: ";
        cin >> vuelo;

        if(vuelo > 10){
            cout << "Numero de avion invalido" << endl;
            system("pause");
            continue;
        }

        v[n][1] = vuelo;
        aviones[vuelo][2] += 1; 

        cout << "["<<i<<"] Inserte el codigo de ciudad: ";
        cin >> ciudad;

        if(vuelo > 20){
            cout << "Numero de ciudad invalida" << endl;
            system("pause");
            continue;
        }

        v[n][2] = ciudad;
        ciudades[ciudad][2] += 1;

        cout << "["<<i<<"] Inserte la cantidad de pasajeros: ";
        cin >> pasajeros;

        v[n][3] = pasajeros;
        aviones[vuelo][3] += pasajeros;
        ciudades[ciudad][3] += pasajeros;
         
        cout << endl;
    }

    //Ciudad con mas pasajeros
    max = 0;
    for(i = 1; i <= 20; i++){

        comp = ciudades[i][3];

        if(comp > max){
            max = comp;
            cmax = ciudades[i][1];
        }
    }
    cout << "La ciudad con mas pasajeros fue la numero ["<<cmax<<"], con un total de: " << max << endl;

    //Avion con mas viajes

    max = 0;
    for(i = 1; i <= 10; i++){

        comp = aviones[i][2];

        if(comp > max){
            max = comp;
            amax = aviones[i][1];
        }
    }
    cout << "El avion con mas viajes fue el numero ["<<amax<<"], con un total de: " << max << endl << endl;

    //Promedio de pasajeros por avion

    for(i = 1; i <= 10; i++){

        if(aviones[i][2] == 0){
            prom = 0;
        }

        else {
            prom =  aviones[i][3] / float(aviones[i][2]);
        }
        cout << "El avion numero ["<<i<<"] tuvo un promedio de: " << prom << endl;
    }

    system("pause");
}