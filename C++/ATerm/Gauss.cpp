#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <quadmath.h>

#define __float128 long double //Arreglo para VSCode, quitar para mayor precision al compilar

using namespace std;


void mostrar(__float128 x[][10], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {

      long double temp = static_cast<long double>(x[i][j]);
      cout.precision(10);
			cout << right << setw(2) << "| "
			<< right << setw(10) << temp << " |";
		}

		cout <<  endl;
    }

    for (int n = 1; n <= cx; ++n) {

		cout << "---------";
		}
		cout << endl;

}
int main(){

  __float128 x[10][10], t[10];
  long double di, nm, temp; // Establece valores como numeros reales, el long double indica que deben ser de alta precision
  int lx, cx, cc; //Los enteros seran usados para contar filas y columnas
  bool found; //Y un booleano para verificar parametros en un futuro
  string stemp;

  cout << "Inserte la cantidad de filas de su matriz x: "; //Empezamos pidiendo parametros de la matriz
	cin >> lx;
	cout << "Inserte la cantidad de columnas de su matriz x: ";
	cin >> cx;

  cx = cx + 1; // Esto añade una columna, que sera la que almacena las constantes

	for (int i = 1; i <= lx; i++) { //Pide que se inserte la matriz

		for (int j = 1; j <= cx; j++) {

      if(j != cx){
        cout << "Inserte la variable en [" << i << "][" << j << "] : ";
        cin >> temp;
        x[i][j] = temp;
      }

      else{
        cout << "Inserte la solucion en la coordenada [" << i << "][" << j << "] : ";
        cin >> temp;
        x[i][j] = temp;
      }

		}
	}

	mostrar(x, cx , lx , "Su matriz es: "); // Muestra el sistema de ecuaciones insertado

    if(lx > cx){ //Verifica si hay mas variables que constantes, si es asi, la matriz tiene infinitas soluciones
        cout << "La matriz tiene soluciones infinitas" << endl;
        system("pause");
        return 0;
    }

    cc = 1; //Columna clave, columna en que debe aparecer un 1 en la matriz en funcion de la fila analizada, para crear una matriz identidad

    for(int i = 1; i <= lx;++i ){

        string paso = string("Paso numero ") + to_string(i);

        if(cc == i && x[i][cc] == 0){ //Trata de arreglar las cosas si la variable que debe ser 1 es 0

            found = false; //Establece en una variable que la fila actual tiene un 0 donde no deberia estar

            if(i < lx){ // Verifica si la fila con el 0 es la ultima, si no, busca filas para intercambiar y areglar el problema
                for( int j = i + 1; j <= lx; ++j){

                    if(x[j][cc] != 0){
                        for(int k = 1; k <= cx; ++k){

                            t[k] = x[i][k];
                            x[i][k] = x[j][k];
                            x[j][k] = t[k];
                        }
                    found = true; //Si logra arreglar el problema, establece en la variable "found" que puede continuar normalmente
                    }
                }
            }

            if(found == false){  //Si no encuentra una fila para intercambiar valida (sin un 0 en la columna clave), o no hay soluciones o hay infinitas
                cout << "Problema encontrado en la fila " << i << endl;
                cout << "La matriz o tiene soluciones infinitas, o no tiene, verificando . . ." << endl;

                if(x[lx][cx] != 0){ //Busca si existe una inconsistencia, si es asi, no existen soluciones
                    cout << "El sistema no tiene soluciones! " << endl;
                }

                else{ //De lo contrario, hay infinitas soluciones
                    cout << "El sistema tiene infinitas soluciones!" << endl;
                }
                system("pause");
                return 0;
            }
        }

        if(cc == i && x[i][cc] != 1){ // Verifico si la coordenada es 1, si no lo es, multiplico toda la fila por su inversa

            di = 1/x[i][cc]; //Inversa del punto de la matriz que debe convertirse en 1

            for(int j = 1; j <= cx; ++j){

                x[i][j] = x[i][j] * di; //Se multiplica toda la fila por esta inversa, de manera que ahora tenemos el 1 que necesitamos


            }

        }

        for (int n = 1;n <= lx; ++n ){ // Ahora reduzco el resto de elementos de la columna a 0 para obtener la forma escalonada completa

            if(n != i){
                nm = x[i][cc] * x[n][cc] * -1; //numero hecho para reducir el resto de elementos de la columna a 0

                for(int c = 1; c <= cx; ++c){
                    x[n][c] = (x[i][c] * nm) + x[n][c]; //nm veces la fila fi + la fila fn
                    if(x[n][c] < 1e-10 && x[n][c] > -1e-10){
                      x[n][c] = 0;
                    }
                }
                mostrar(x, cx, lx , paso);
            }
        }
    cc += 1; //Pasa a la siguiente columna clave, en resumen, hace que los 1 esten en diagonal,
             //creando una matriz identidad con las constantes a la derecha



    mostrar(x, cx, lx , paso);  //Muestra la matriz con la fila i despejada
    cout << endl;
    }


    mostrar(x, cx, lx); //Muestra la matriz resultado

    system("pause");
    return 0;
}
