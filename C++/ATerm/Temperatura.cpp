#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){

    int dia = 0;

    while(true){

        int hora = 0;
        float sumatemperaturas = 0;
        float mediatemperatura = 0;
        float temperatura;
        float tempmin;
        float tempmax;

        cout << "Bienvenido al promediador de temperatura!: DIA [ " << dia <<" ]"<< endl;

        for(int i = 0; i < 6; i++){

            hora = hora + 4;

            cout << "Inserte la Temperatura en Celsius (Esta en la hora [" << hora << "]) del dia [" << dia << "]: ";
            cin >> temperatura;

            if ((temperatura < tempmin || hora == 4)){

                tempmin = temperatura;
            } 

            if ((temperatura > tempmax) || hora == 4){

                tempmax = temperatura;
            } 

            sumatemperaturas = sumatemperaturas + temperatura;

            mediatemperatura = sumatemperaturas / (hora / 4);

            cout << "El promedio actual es de [ " << mediatemperatura << " ] Grados Celsius" << endl << endl;

            Sleep(200); //Asuma que se pausa por 4 horas :P
        }

        dia = dia + 1;

        cout << "En el dia [" << dia << "] La mayor temperatura fue de : [" << tempmax << "]" << endl;
        cout << "En el dia [" << dia << "] La menor temperatura fue de : [" << tempmin << "]" << endl;

        system("pause");
        system("cls");

    }

}