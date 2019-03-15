#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int linea, op;

void fijo()
{

    string titulo = R"(UUUUUUUU     UUUUUUUUIIIIIIIIII   SSSSSSSSSSSSSSS 
U::::::U     U::::::UI::::::::I SS:::::::::::::::S
U::::::U     U::::::UI::::::::IS:::::SSSSSS::::::S
UU:::::U     U:::::UUII::::::IIS:::::S     SSSSSSS
 U:::::U     U:::::U   I::::I  S:::::S            
 U:::::D     D:::::U   I::::I  S:::::S            
 U:::::D     D:::::U   I::::I   S::::SSSS         
 U:::::D     D:::::U   I::::I    SS::::::SSSSS    
 U:::::D     D:::::U   I::::I      SSS::::::::SS  
 U:::::D     D:::::U   I::::I         SSSSSS::::S 
 U:::::D     D:::::U   I::::I              S:::::S
 U::::::U   U::::::U   I::::I              S:::::S
 U:::::::UUU:::::::U II::::::IISSSSSSS     S:::::S
  UU:::::::::::::UU  I::::::::IS::::::SSSSSS:::::S
    UU:::::::::UU    I::::::::IS:::::::::::::::SS 
      UUUUUUUUU      IIIIIIIIII SSSSSSSSSSSSSSS   
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

    cout << endl << ("APLICACIONES INGENIERIA ");
    cout << endl << ("1. BIBLIOTECA  UIS ");
    cout << endl << ("2. POLITICA NOTICIAS ");
    cout << endl << ("3. ING MECANICA");
    cout << endl << ("4. ING INDUSTRIA");
    cout << endl << ("5. ING SISTEMAS");
    cout << endl << ("... otras FUNCIONES");
    cout << endl << ("9. para TERMINAR ");
    cout << "\n\n   Digite opcion ";
    cin >> op;
    limpiaopciones();
}

void bibliotecauis()
{

    cout << endl << ("Hola a todos VOY A BIBLIOTECA UIS === >  presione Intro y espere ");

    getch();
    system("start chrome http://tangara.uis.edu.co/");
    cout << endl << ("...     Enter para salir ");
    getch();
}

void politica()
{

    cout << endl << (" NOTICIAS POLITICA === >  presione Intro y espere ");

    getch();
    system("start chrome http://goo.gl/BqaqT");
    getch();
    cout << endl << ("Regrese de POLITICA ");
    cout << endl << (" Intro pata terminar y/o salirr ");

    cout << endl << ("...    Enter para salir ");
    getch();
}
void ingmecanica()
{

    cout << endl << (" VOY A INGENIERIA MECANICA ");

    cout << endl << ("CONSULTA INGENIERIA MECANICA");
    cout << endl << (" Conectar APLICACIÓN === >  presione Intro y espere");
    getch();
    system("start chrome https://bit.ly/2tvECI3");
    getch();
    cout << endl << (" Ir a problemas Ingenieria Mecanica === >  presione Intro y espere ");
    getch();
    system("start chrome https://tinyurl.com/y5wv85yf");
    getch();
    cout << endl << ("...    Enter para salir ");
    getch();
}


void ingindustrial()
{

    cout << endl << ("                                ");
    //

    cout << endl << ("=====================================================");
    cout << endl << ("     UIS  APLICACIÓNES INGENIERIA INDUSTRIAL ");
    cout << endl << ("        Estudiantes UIS ing - industrial ");
    cout << endl << ("========================================================================");
    cout << endl << (" inicia dispositivo(start chrome google) y ruta donde estan las aplicaciones");
    cout << endl << ("========================================================================");
    cout << endl << ("   Conectar APLICACIÓN === >  presione Intro y espere ");
    getch();
    system("start chrome https://tinyurl.com/yyax4q6z");
    linea = 11;

    cout << endl << ("                                                         ");
    getch();

    cout << endl << ("    Ir a PROBLEMAS Ingenieria Industrial === >  presione Intro y espere");
    getch();
    system("start chrome https://tinyurl.com/y3275xnp");
    linea = 12;

    cout << endl << ("                                                                          ");
    cout << endl << ("...    intro para salir ");
    getch();
}

void ingsistemas()
{

    cout << endl << (" VOY A INGENIERIA DE SISTEMAS ");

    cout << endl << ("CONSULTA INGENIERIA DE SISTEMAS");
    cout << endl << (" Conectar APLICACIÓN === >  presione Intro y espere");
    getch();
    system("start chrome http://cormoran.uis.edu.co");
    getch();
    cout << endl << (" Ir a problemas Ingenieria DE SISTEMAS === >  presione Intro y espere ");
    getch();
    system("start chrome https://es.wikipedia.org/wiki/Ingenier%C3%ADa_de_sistemas");
    getch();
    cout << endl << ("...    Enter para salir ");
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
            bibliotecauis();
            limpiaopciones();
            break;
        }
        case 2:
        {
            politica();
            limpiaopciones();
            break;
        }
        case 3:
        {
            ingmecanica();
            limpiaopciones();
            break;
        }
        case 4:
        {
            ingindustrial();
            limpiaopciones();
            break;
        }
        case 5:
        {
            ingsistemas();
            limpiaopciones();
            break;
        }
            // espacios para mas FUNCIONES
        }
    } while (op != 9); // opcion = 9 Terminar
    cout << endl << ("Termina sistema ");
    getch();
}
