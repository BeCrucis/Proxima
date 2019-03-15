#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
void titulo()
{
    string titulo = R"( _______  _______  _______  _______  _______ 
|  _    ||       ||       ||       ||       |
| |_|   ||    ___||    ___||    _  ||  _____|
|       ||   |___ |   |___ |   |_| || |_____ 
|  _   | |    ___||    ___||    ___||_____  |
| |_|   ||   |___ |   |___ |   |     _____| |
|_______||_______||_______||___|    |_______|)";
    cout << titulo << endl
         << endl;
    system("@echo off & for /l %x in (1, 1, 9) do color 0%x & ping 127.0.0.1 -n 1 > nul");
}
void cls()
{
    system("cls");
    system("color 02"); //letra Verde
    titulo();
}
void mostraropciones()
{
    cout << "[Opciones]" << endl
         << endl;
    cout << "1 >> Mario Bros" << endl
         << "2 >> Fur Elise" << endl
         << "3 >> Mario World (Largo)" << endl
         << "4 >> Pitido personalizado" << endl
         << "9 >> Salir" << endl
         << endl
         << endl
         << ">> ";
}
void mariobros()
{
    string mario = R"(                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ......................
                 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'               ........,.............
          ;;'';'';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'''''''''''';;;;;;;;,..............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;...............
          ;;;;;;;;;;;;;;;;;;;;;;;'''''''''''''';;;;;;;;''''''''''''';;;;;;;;;...............
          ;'''''''''''''''''''''...............';;''';'.......`       '''''''';'''''''''''''
          ;'''''''''''''''''''''...............''''''''.....,.        ;'';''';;;;;;;;;;;;;;;
          ;'''''''''''''''''''';...............';;;;;;'.......        ;';;;''';'''''''''''''
          ;''';'''''''''''''''''...............''''''''.......        ;'''';;'''''''''''''''
          ;';;;'''';'''';;''''''...............'';'';''......,        ;'''''''''''''''''''''
          ''''';;;'''''''';;;;;'...............'';'';''.......        ;''';;''''''''''''''''
          ;';;;'';''''''''''''''...............'';'';''.......        ;'';'''';'''''''''''''
  '''''''+.......;''';;;'......................'';'';''.....,................;;'''''''''''''
  ';''';;'.......'''';;'+.......,..............'';'';''...............,......'''''''''''''''
  ';''';''.......';'';'''......................';;';'''......................'';;;;;''''''''
  ';''';''.......';'';'''......................'';'''''......................';'''''''''''''
  ';''';''.......';'';'''......................''''''''......................';'''''''''''''
  ';''';''.......';'';'''......................';;;;;;'......................'';;;;;;;''''''
  ';''';''.......';'';'''......................';''';'+......................''''''''';'''''
  ';''';''.......';'';'''......................+''''''+......................+''''''';'';'''
  ';''';''.......';''''';';;;;;;.......................';''';'..............,........';';'''
  ';''';''.......';''''';;;;;;;'.,.....................;;''';'................,......''';'''
  ';''';''.......';'''''''''''''.......................';''';'.......................;;';'''
  ';''';''.......';'''''''''''''.......................';''';'.......................;;';'''
  ';''';''.......';'''''''''''''.......................';''';'.......................;;';'''
  ';''';;'.,...,.'''''''''''''''.....................,.;;;';''.......................';'';''
  ';''';;'.......';;;;;;;;;;;;;;.....................,.';'';''.......................;''''''
  ';''';'''''''''..............................''''''';;;'';';''''''''''''''''''''''+       
  ';'''''';;;;;''..............................'';;;;'';;'''''';;;;;;;;;;;;;;;;;;;;;+       
  ';'''''''''''''..............................'';'';'';'';'''''''''''''''''''''''''+       
  ';'''''''''''''..............................'';'';;';;';;;;;'''''''''';;'''''''''+       
  ';;;;;;;;;;;;''..............................''''''''''''''''''''''''';;''''';;;;;+       
  ';'''''''''''''..............................';;'''''''';';';''''';;;;''';;'''''''+       
  ';';;;;;;;;;;;'..............................'''';;''''';;;;;''''''';;''';'';;;;;;+       
  +'+++++++++++++,.............................'''''''''''''''''''''''';'';';'+++++++       
                 .....................................................;;'''';               
                 .....................................................;'''';'                        
 )";
    cout << mario << endl;
    Beep(330, 100);
    Beep(330, 300);
    Beep(330, 300);
    Beep(262, 100);
    Beep(330, 300);
    Beep(392, 700);
    Beep(196, 700);
}
void elise()
{
    //1
    Beep(659, 200); //E5
    Beep(622, 200); //Eb5
    //2
    Beep(659, 200); //E5
    Beep(622, 200); //Eb5
    Beep(659, 200); //E5
    Beep(493, 200); //B4
    Beep(587, 200); //D5
    Beep(523, 200); //C5
    //3
    Beep(440, 400); //A4
    Beep(110, 200); //A2
    Beep(164, 200); //E3
    Beep(220, 200); //A3
    Beep(261, 200); //C4
    Beep(329, 200); //E4
    Beep(440, 200); //A4
    //4
    Beep(493, 400); //B4
    Beep(82, 200);  //E2
    Beep(164, 200); //E3
    Beep(207, 200); //Ab3
    Beep(329, 200); //E4
    Beep(415, 200); //Ab4
    Beep(493, 200); //B4
    //5
    Beep(523, 400); //C5
    Beep(110, 200); //A2
    Beep(164, 200); //E3
    Beep(220, 200); //A3
    Beep(329, 200); //E4
    Beep(659, 200); //E5
    Beep(622, 200); //Eb5
    //6
    Beep(659, 200); //E5
    Beep(622, 200); //Eb5
    Beep(659, 200); //E5
    Beep(493, 200); //B4
    Beep(587, 200); //D5
    Beep(523, 200); //C5
    //7
    Beep(440, 400); //A4
    Beep(110, 200); //A2
    Beep(164, 200); //E3
    Beep(220, 200); //A3
    Beep(261, 200); //C4
    Beep(329, 200); //E4
    Beep(440, 200); //A4
    //8
    Beep(493, 400); //B4
    Beep(82, 200);  //E2
    Beep(164, 200); //E3
    Beep(207, 200); //Ab3
    Beep(329, 200); //E4
    Beep(523, 200); //C5
    Beep(493, 200); //B4
    //9
    Beep(440, 900); //A4
}
void mario2()
{
    Beep(480, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(369.99, 200);
    Beep(392, 200);
    Beep(369.99, 200);
    Beep(392, 200);
    Beep(392, 400);
    Beep(196, 400);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(83.99, 200);
    Beep(880, 200);
    Beep(830.61, 200);
    Beep(880, 200);
    Beep(987.77, 400);
    Beep(880, 200);
    Beep(783.99, 200);
    Beep(698.46, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(880, 200);
    Beep(830.61, 200);
    Beep(880, 200);
    Beep(987.77, 400);
    Sleep(200);
    Beep(1108, 10);
    Beep(1174.7, 200);
    Beep(1480, 10);
    Beep(1568, 200);
    Sleep(200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(783.99, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(880, 200);
    Beep(830.61, 200);
    Beep(880, 200);
    Beep(987.77, 400);
    Beep(880, 200);
    Beep(783.99, 200);
    Beep(698.46, 200);
    Beep(659.25, 200);
    Beep(698.46, 200);
    Beep(784, 200);
    Beep(880, 400);
    Beep(784, 200);
    Beep(698.46, 200);
    Beep(659.25, 200);
    Beep(587.33, 200);
    Beep(659.25, 200);
    Beep(698.46, 200);
    Beep(784, 400);
    Beep(698.46, 200);
    Beep(659.25, 200);
    Beep(587.33, 200);
    Beep(523.25, 200);
    Beep(587.33, 200);
    Beep(659.25, 200);
    Beep(698.46, 400);
    Beep(659.25, 200);
    Beep(587.33, 200);
    Beep(493.88, 200);
    Beep(523.25, 200);
    Sleep(400);
    Beep(349.23, 400);
    Beep(392, 200);
    Beep(329.63, 200);
    Beep(523.25, 200);
    Beep(493.88, 200);
    Beep(466.16, 200);
    Beep(440, 200);
    Beep(493.88, 200);
    Beep(523.25, 200);
    Beep(880, 200);
    Beep(493.88, 200);
    Beep(880, 200);
    Beep(1760, 200);
    Beep(440, 200);
    Beep(392, 200);
    Beep(440, 200);
    Beep(493.88, 200);
    Beep(783.99, 200);
    Beep(440, 200);
    Beep(783.99, 200);
    Beep(1568, 200);
    Beep(392, 200);
    Beep(349.23, 200);
    Beep(392, 200);
    Beep(440, 200);
    Beep(698.46, 200);
    Beep(415.2, 200);
    Beep(698.46, 200);
    Beep(1396.92, 200);
    Beep(349.23, 200);
    Beep(329.63, 200);
    Beep(311.13, 200);
    Beep(329.63, 200);
    Beep(659.25, 200);
    Beep(698.46, 400);
    Beep(783.99, 400);
    Beep(440, 200);
    Beep(493.88, 200);
    Beep(523.25, 200);
    Beep(880, 200);
    Beep(493.88, 200);
    Beep(880, 200);
    Beep(1760, 200);
    Beep(440, 200);
    Beep(392, 200);
    Beep(440, 200);
    Beep(493.88, 200);
    Beep(783.99, 200);
    Beep(440, 200);
    Beep(783.99, 200);
    Beep(1568, 200);
    Beep(392, 200);
    Beep(349.23, 200);
    Beep(392, 200);
    Beep(440, 00);
    Beep(698.46, 200);
    Beep(659.25, 200);
    Beep(698.46, 200);
    Beep(739.99, 200);
    Beep(783.99, 200);
    Beep(392, 200);
    Beep(392, 200);
    Beep(392, 200);
    Beep(392, 200);
    Beep(196, 200);
    Beep(196, 200);
    Beep(196, 200);
    Beep(185, 200);
    Beep(196, 200);
    Beep(185, 200);
    Beep(196, 200);
    Beep(207.65, 200);
    Beep(220, 200);
    Beep(233.08, 200);
}

void custom(){
    int frec, ms;
    cout << "Inserte la frecuencia: ";
    cin >> frec;

    cout << "Inserte los milisegundos de sonido: ";
    cin >> ms;

    cout << endl << "Enter para ejecutar el sonido ";
    getch();

    Beep(frec, ms);
}

void test(){
    cout << "Espacio de prueba" << endl;

}

void megalovania(){
    cout << "BAD TIME"<<endl;
    Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(261,100);
Beep(261,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(246,100);
Beep(246,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(233,100);
Beep(233,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(261,100);
Beep(261,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(246,100);
Beep(246,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(233,100);
Beep(233,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(261,100);
Beep(261,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Sleep(1);
Beep(349,100);
Sleep(1);
Beep(392,100);
Sleep(1);
Beep(246,100);
Sleep(1);
Beep(246,100);
Sleep(1);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(233,100);
Beep(233,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(261,100);
Beep(261,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(200);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(246,100);
Beep(246,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(233,100);
Beep(233,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(349,100);
Sleep(100);
Beep(349,100);
Beep(349,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Beep(349,100);
Beep(349,100);
Beep(349,100);
Beep(349,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(349,100);
Beep(349,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(587,100);
Sleep(100);
Beep(587,100);
Sleep(100);
Beep(587,100);
Beep(440,100);
Beep(587,100);
Beep(523,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(440,100);
Beep(440,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(440,100);
Beep(440,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Beep(392,100);
Sleep(100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Sleep(100);
Beep(329,100);
Beep(349,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(440,100);
Beep(523,100);
Sleep(100);
Beep(440,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(329,100);
Beep(349,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Sleep(100);
Beep(554,100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(174,100);
Sleep(100);
Beep(196,100);
Sleep(100);
Beep(220,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Beep(415,100);
Beep(392,100);
Beep(369,100);
Beep(349,100);
Beep(329,100);
Beep(311,100);
Beep(293,100);
Beep(277,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(311,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(329,100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Beep(440,100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(293,100);
Beep(329,100);
Beep(349,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Beep(523,100);
Sleep(100);
Beep(554,100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(415,100);
Beep(392,100);
Beep(349,100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(174,100);
Sleep(100);
Beep(196,100);
Sleep(100);
Beep(220,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(392,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(440,100);
Beep(415,100);
Beep(392,100);
Beep(369,100);
Beep(349,100);
Beep(329,100);
Beep(311,100);
Beep(293,100);
Beep(277,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(311,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(246,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(246,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(246,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(246,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(349,100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(329,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Sleep(100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(277,100);
Beep(277,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(261,100);
Beep(261,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(293,100);
Beep(293,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);
Sleep(100);
Beep(415,100);
Sleep(100);
Beep(392,100);
Sleep(100);
Beep(349,100);
Sleep(100);
Beep(293,100);
Beep(349,100);
Beep(392,100);
Beep(277,100);
Beep(277,100);
Beep(587,100);
Sleep(100);
Beep(440,100);
Sleep(100);


}
int main()
{
    int op;
    titulo();
    do
    {
        mostraropciones();
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cls();
            mariobros();
            break;
        }
        case 2:
        {
            cls();
            elise();          
            break;
        }
        case 3:
        {
            cls();
            mario2();          
            break;
        }
        case 4:
        {
            cls();
            custom();
            break;
        }
        case 98:
        {
            cls();
            megalovania();
        }
        case 99:
        {
            cls();
            test();
        }
            // espacios para mas FUNCIONES
        }

        cls();
    } while (op != 9); // opcion = 9 Terminar
    system("pause");
}