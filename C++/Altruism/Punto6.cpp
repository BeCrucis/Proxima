#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    // Inicializa la matriz con todos sus valores en 0
    int matriz[20][10] = {0};

    // Este for navega por las filas de la matriz
    for(int i = 0; i < 20; i++){

        // Este for navega por las columnas de la matriz
        for(int j = 0; j < 10; j++){
            
            // Hace la parte superior
            if(i <= 9 && j <= i){
                matriz[i][j] = j;
            // Hace la parte inferior
            } else if (i >= 9 && i+j <= 18){
                matriz[i][j] = j;
            }
        }
    }

    // Imprime la matriz

    // Este for navega por las filas de la matriz
    for(int i = 0; i < 20; i++){

        // Este for navega por las columnas de la matriz
        for(int j = 0; j < 10; j++){
            
            if(matriz[i][j] > 0){
                cout << matriz[i][j] << " ";
            } else {
                cout << "  ";
            } 
        }
        cout << endl;
        
    }
}