//EJERCICIO NRO 3
/* = = = = = = = = = = = = = = = = = = = = = = = == = = = = = = = =
 Ejercicios interactivos- multimedia – dispositivos-google
Para trabajo de laboratorio     Leonel Parra Pinilla     UIS
= = = = = = = = = = = = = = = = = = = = = = = = = ==
 Ejercicio nro 3 :  generar menu interactivo de  opciones con funciones
==================================================
Ejecutar en laboratorios con Visual Studio c++
*/
// Multimedia.cpp: archivo de proyecto principal.

#include <iostream>
#include <conio.h>

int op;

using namespace std;

void fijo()
{

    string titulo = R"(*                                                     
 (  `          (     )                   (               
 )\))(     (   )\ ( /( (      )      (   )\ )  (      )  
((_)()\   ))\ ((_))\()))\    (      ))\ (()/(  )\  ( /(  
(_()((_) /((_) _ (_))/((_)   )\  ' /((_) ((_))((_) )(_)) 
|  \/  |(_))( | || |_  (_) _((_)) (_))   _| |  (_)((_)_  
| |\/| || || || ||  _| | || '  \()/ -_)/ _` |  | |/ _` | 
|_|  |_| \_,_||_| \__| |_||_|_|_| \___|\__,_|  |_|\__,_| 
                                                         )";

    cout << titulo << endl << endl;
}

void limpiaopciones()
{
    system("cls");
    system("color 0f"); //letra Blanca
    fijo();
}

void opciones()
{
    system("color 02"); //letra Verde

    cout << ("Reproducir . . .") << endl;
    cout << ("1. MUSICA") << endl;
    cout << ("2. VIDEO") << endl;
    cout << ("3. IMAGEN") << endl;
    cout << ("4. MUSICA USB") << endl;
    
    cout << endl << endl << "Digite opcion:  ";
    cin >> op;
    limpiaopciones();
}

void musica(){
    cout << "Hola a todos" << endl;
    cout << "Sonando Cumbion . . ." << endl;
    system("start wmplayer \"C:\\Users\\Estudiante\\Downloads\\Trance - 009 Sound System Dreamscape (HD).mp3\"");
    cout << "Enter para salir . . .";
    getch();
}

void video(){
    cout << "Hola a todos" << endl;
    cout << "Siendo rickrolleado . . ." << endl;
    system("start wmplayer \"C:/Users/Estudiante/Downloads/Rick Astley - Never Gonna Give You Up (Official Music Video).mp4\"");
    cout << "Enter para salir . . .";
    getch();
}

void imagen(){
    cout << "Hola a todos" << endl;
    cout << "Viendo imagenes" << endl;
    system("start wmplayer \"C:\\Users\\Estudiante\\Pictures\\Feedback\\{7DCFA8AD-C774-4F2D-BF22-CD7415EAEED0}\\Capture001.png\"");
    cout << "Enter para salir . . .";
    getch();
}

void musicausb(){
    cout << "Hola a todos" << endl;
    cout << "Escuchando musica . . ." << endl;
    system("start wmplayer \"C:\\Users\\Estudiante\\Downloads\\Trance - 009 Sound System Dreamscape (HD).mp3\"");
    cout << "Enter para salir . . .";
    getch();

}

int main()
{
    fijo();
    do
    {
        opciones();
        switch (op)
        {
        case 1:
        {
            musica();
            limpiaopciones();
            break;
        }
        case 2:
        {
            video();
            limpiaopciones();
            break;
        }
        case 3:
        {
            imagen();
            limpiaopciones();
            break;
        }
        case 4:
        {
            musicausb();
            limpiaopciones();
            break;
        }
            // espacios para mas FUNCIONES
        }
    } while (op != 9); // opcion = 9 Terminar
    cout << ("Termina sistema ");
    getch();
}
