#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    int filas = 21;
    int columnas = 21;

    // Inicializa la matriz con todos sus valores en 0
    int matriz[22][22] = {0};

    // Este for navega por las filas de la matriz
    for(int i = 0; i < filas; i++){

        // Este for navega por las columnas de la matriz
        for(int j = 0; j < columnas; j++){
            
            // Hace la parte superior
            if(i <= filas/2){

                // Parte superior izquierda
                if(j <= (columnas/2)){
                    if(i + j >= (columnas/2)){
                    matriz[i][j] = 1;
                    }

                } else {
                    // Parte superior derecha
                    if(j <= i + (columnas/2)){
                        matriz[i][j] = 1;
                    }
                }
    
            } else {
                // Hace la parte inferior

                // Parte inferior izquierda
                if(j <= (columnas/2)){

                    if(j >= i - (filas/2)){
                        matriz[i][j] = 1;
                    }
                } else {
                    // Parte inferior derecha

                    if(i + j < filas + (columnas/2)){
                        matriz[i][j] = 1;
                    }
                }
            }
        }
    }

    // Imprime la matriz

    // Este for navega por las filas de la matriz
    for(int i = 0; i < filas; i++){

        // Este for navega por las columnas de la matriz
        for(int j = 0; j < columnas; j++){
            
            if(matriz[i][j] > 0){
                cout << matriz[i][j] << " ";
            } else {
                cout << "  ";
            } 
        }
        cout << endl;
        
    }
}