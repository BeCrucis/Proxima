#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>

using namespace std;

struct Tablero{

    string posiciones[8][8];
    string turno;

    Tablero(string archivo){
        // Posicion del archivo fen
        string posicion = archivo;

        // Importa el archivo y lo inserta en la variable posiciones_fen
        string textoFen = leerFEN(posicion);

        // cout << textoFen << endl;

        // Delimita el archivo de texto en relacion al separador /
        vector<string> elementos = delimitar(textoFen, "/");

        // Toma solo las posiciones y las procesa para eliminar la informacion sobrante
        vector<string> posicionesFen = elementos;

        // Usa como delimitador el espacio para tomar la posicion de la fila 1
        string temp = posicionesFen.back();

        // Toma solo las posiciones y no la informacion de la partida
        string temp1 = delimitar(temp, " ").at(0);
        
        turno = delimitar(temp, " ").at(1);

        // Reemplaza el ultimo elemento por uno con solo posiciones
        posicionesFen.back() = temp1;

        std::reverse(posicionesFen.begin(), posicionesFen.end());

        // Inicia las posiciones como espacios
        for (int i = 0; i <= 7; i++){
            for (int j = 0; j <= 7; j++){  
                posiciones[i][j] = " ";
            }
        }

        for(int i = 7; i >= 0; i--){

            int posicion_lectura = 0;

            for(int j = 0; j <= 7; j++ ){

                char ficha = posicionesFen.at(i).at(posicion_lectura);

                if(isdigit(ficha)){
                    int espacios = ficha - '0';
                    j = j + espacios - 1;
                } else { 
                    string ficha_string(1, ficha);
                    posiciones[i][j] = ficha_string;
                }

                posicion_lectura++;
            }
        }
    }

    string to_string2(int n){

    ostringstream ss;
    ss << n;
    return ss.str();
    }

    boolean verificarCelda(int fila, int columna){

        if(fila < 1 || fila > 8){
            return false;
        }

        if(columna < 1 || columna > 8){
            return false;
        }

        return true;
    }

    vector<int> letrasACoordenadas(string posicion){

        int fila;
        int columna;
        vector<int> vector_posiciones;
        vector<int> nullVector;

        char charColumna = posicion.at(0);
        // Pasa la columna a mayuscula
        charColumna = toupper(charColumna);

        string letraColumna(1, charColumna);    

        if(letraColumna == "A"){
            columna = 1;
        } else if (letraColumna == "B"){
            columna = 2;
        } else if (letraColumna == "C"){
            columna = 3;    
        } else if (letraColumna == "D"){
            columna = 4;
        } else if (letraColumna == "E"){
            columna = 5;
        } else if (letraColumna == "F"){
            columna = 6;
        } else if (letraColumna == "G"){
            columna = 7;
        } else if (letraColumna == "H"){
            columna = 8;
        } else {
            cout << "Posicion de letra invalida!" << endl;
            return nullVector;
        }

        fila = posicion.at(1) - '0';

        if(verificarCelda(fila, 1) == false){
            cout << "Posicion de letra invalida!" << endl;
            return nullVector;
        }

        vector_posiciones.push_back(fila);
        vector_posiciones.push_back(columna);

        return vector_posiciones;

    }

    string coordenadasALetras(int fila, int columna){

        string letras = "";  
        string letraColumna;

        if (columna == 1){
            letraColumna = "A";
        } else if (columna == 2){
            letraColumna = "B";
        } else if (columna == 3){
            letraColumna = "C";    
        } else if (columna == 4){
            letraColumna = "D";
        } else if (columna == 5){
            letraColumna = "E";
        } else if (columna == 6){
            letraColumna = "F";
        } else if (columna == 7){
            letraColumna = "G";
        } else if (columna == 8){
            letraColumna = "H";
        } else {
            cout << "Posicion invalida!" << endl;
            return NULL;
        }

        if(verificarCelda(fila, 1) == false){
            cout << "Posicion invalida!" << endl;
            return NULL;
        }

        letras = letras + letraColumna + to_string2(fila);
        return letras;
    }

    string leerFEN(string posicion){

        string texto;

        // Extrae el texto del archivo
        ifstream input;
        input.open(posicion, ios::in);
        getline(input, texto);

        return texto;
    }

    void imprimirTablero(){

        // Crea una matriz tablero mas grande con espacio para letras y numeros
        string tablero[10][10];

        // Inicializa el tablero con espacios vacios
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){  
                tablero[i][j] = "| |";
            }
        }

        tablero[0][0] = "   ";
        tablero[9][0] = "   ";

        // Coloca los numeros
        for (int i = 1; i <= 8; i++){
            tablero[i][0] = to_string2(i) + " |";
            tablero[i][9] = "| " + to_string2(i);
        }

        // Coloca las letras
        tablero[0][1] = " A ";
        tablero[0][2] = " B ";
        tablero[0][3] = " C ";
        tablero[0][4] = " D ";
        tablero[0][5] = " E ";
        tablero[0][6] = " F ";
        tablero[0][7] = " G ";
        tablero[0][8] = " H ";

        tablero[9][1] = " A ";
        tablero[9][2] = " B ";
        tablero[9][3] = " C ";
        tablero[9][4] = " D ";
        tablero[9][5] = " E ";
        tablero[9][6] = " F ";
        tablero[9][7] = " G ";
        tablero[9][8] = " H ";

        // Coloca las posiciones en el tablero
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){  
                tablero[i][j] = "|" + posiciones[i-1][j-1] + "|";
            }
        }

        // Imprime el tablero

        for (int i = 9; i >= 1; i--){

            for (int j = 0; j <= 9; j++){      
                cout << tablero[i][j];    
            }
            cout << endl << "------------------------------" << endl;         
        }

        for (int j = 0; j <= 9; j++){
            cout << tablero[0][j];       
        }
        cout << endl;

    }

    void guardarPosicion(){

        string nombreArchivo = "posiciones_fen.fen";
        ofstream archivo;
        archivo.open(nombreArchivo);

        for(int i = 7; i >= 0; i--){

            string posicionesFila = "";

            for(int j = 0; j <= 7; j++){
                
                string ficha = posiciones[i][j];

                if(ficha != " "){
                    posicionesFila = posicionesFila + ficha;
                } else {
                    
                    int espacios = 0;
                    while(posiciones[i][j] == " " && j <= 7){
                        espacios++;
                        j++;
                    }

                    j--;
                    posicionesFila = posicionesFila + to_string2(espacios);
                }
            }

            if( i != 0){
                archivo << posicionesFila + "/";
            } else {
                archivo << posicionesFila;
            }
            
        }

        archivo << " b KQkq e3 0 1";
        archivo.close();
    }

    boolean verificarMovimiento(string pieza, string posicionInicial, string posicionFinal){
        
        vector<int> coordenadasIniciales = letrasACoordenadas(posicionInicial);
        int filaInicial = coordenadasIniciales.at(0);
        int columnaInicial = coordenadasIniciales.at(1);

        vector<int> coordenadasFinales = letrasACoordenadas(posicionFinal);
        int filaFinal = coordenadasFinales.at(0);
        int columnaFinal = coordenadasFinales.at(1);

        int movimientoHorizontal = columnaFinal-columnaInicial;
        int movimientoVertical = filaFinal-filaInicial;

        // Obtiene la pieza en la posicion a moverse
        char piezaPosicionInicial = pieza.at(0);
        char piezaPosicionFinal = posiciones[filaFinal-1][columnaFinal-1].at(0);

        // Reglas generales
        if(verificarCelda(filaFinal, columnaFinal) == false){
            // Debe quedar dentro del tablero
            return false;
        }

        if(piezaPosicionFinal != ' '){
            
            if(isupper(piezaPosicionInicial) == isupper(piezaPosicionFinal)){
                // No puede colocarse sobre una ficha aliada
                return false;
            }
        }

        if(pieza == "p"){
            // Verifica un peon negro

            int movHorizontalMax = 0;
            int movVerticalMax = -1;
            boolean movimientoDiagonal = false;

            if(abs(movimientoHorizontal) == abs(movimientoVertical)){
                // Verifica movimiento diagonal para ver si el peon busca capturar una ficha
                movimientoDiagonal = true;
                movHorizontalMax = 1;
            }

            if(filaInicial == 7){
                // Verifica que el peon pueda hacer doble avance
                movVerticalMax = -2;
            }

            if(movimientoVertical >= 0){
                // Un peon negro solo puede bajar de fila, no subir
                return false;
            }

            if(abs(movimientoVertical) > abs(movVerticalMax)){
                // Un peon negro tiene un maximo de movimiento vertical
                return false;
            }

            if(abs(movimientoHorizontal) > movHorizontalMax){
                // Un peon negro tiene un maximo de movimiento horizontal
                return false;
            }

            if(movimientoDiagonal == true && abs(movimientoVertical) > 1){
                // El movimiento diagonal no se puede hacer al mismo tiempo que el doble avance
                return false;
            }

            if(abs(movVerticalMax) == 2 && abs(movimientoVertical) == 2){

                char fichaPosicionActual = posiciones[filaInicial-2][columnaFinal-1].at(0);
                if(fichaPosicionActual != ' '){
                    // El peon no puede atravesar otra ficha
                    return false;
                }
            }

            if (movimientoHorizontal == 0 && piezaPosicionFinal != ' '){
                // Indica movimiento en linea recta, si la posicion esta ocupada, no puede moverse
                return false;
            }
            
            if(movimientoDiagonal && piezaPosicionFinal == ' '){
                // Si hay movimiento diagonal pero no hay ficha enemiga
                return false;
            }

            return true;

        }

        if(pieza == "P"){
            // Verifica un peon blanco

            int movHorizontalMax = 0;
            int movVerticalMax = 1;
            boolean movimientoDiagonal = false;

            if(abs(movimientoHorizontal) == abs(movimientoVertical)){
                // Verifica movimiento diagonal para ver si el peon busca capturar una ficha
                movimientoDiagonal = true;
                movHorizontalMax = 1;
            }

            if(filaInicial == 2){
                // Verifica que el peon pueda hacer doble avance
                movVerticalMax = 2;
            }

            if(movimientoVertical <= 0){
                // Un peon blanco solo puede subir de fila, no bajar
                return false;
            }

            if(abs(movimientoVertical) > abs(movVerticalMax)){
                // Un peon blanco tiene un maximo de movimiento vertical
                return false;
            }

            if(abs(movimientoHorizontal) > movHorizontalMax){
                // Un peon blanco tiene un maximo de movimiento horizontal
                return false;
            }

            if(movimientoDiagonal == true && abs(movimientoVertical) > 1){
                // El movimiento diagonal no se puede hacer al mismo tiempo que el doble avance
                return false;
            }

            if(abs(movVerticalMax) == 2 && abs(movimientoVertical) == 2){

                char fichaPosicionActual = posiciones[filaInicial][columnaFinal-1].at(0);
                if(fichaPosicionActual != ' '){
                    // El peon no puede atravesar otra ficha
                    return false;
                }
            }

            if (movimientoHorizontal == 0 && piezaPosicionFinal != ' '){
                // Indica movimiento en linea recta, si la posicion esta ocupada, no puede moverse
                return false;
            } 
            
            if (movimientoDiagonal && piezaPosicionFinal == ' '){
                // Si hay movimiento diagonal pero no hay ficha enemiga
                return false;
            }

            return true;

        }

        if (pieza == "n" || pieza == "N"){
            // Verifica un caballo negro o blanco

            // El movimiento del caballo debe ser en forma de L

            // Si va 2 casillas a un lado, debe subir o bajar una y viceversa

            if(abs(movimientoHorizontal) == 2 and abs(movimientoVertical) == 1){
                return true;
            } else if(abs(movimientoHorizontal) == 1 and abs(movimientoVertical) == 2){
                return true;
            } else {
                return false;
            }

        }

        if (pieza == "b" || pieza == "B"){
            // Verifica un alfil negro o blanco

            int pasoVertical;
            int pasoHorizontal;

            if(abs(movimientoHorizontal) != abs(movimientoVertical)){
                // Un alfil solo se mueve en diagonal
                return false;
            }

            // Verifica el movimiento diagonal hacia arriba
            
            if(movimientoVertical < 0){
                // El alfin se intenta mover hacia abajo
                pasoVertical = -1;
            } else {
                pasoVertical = 1;
            }

            if(movimientoHorizontal < 0){
                // El alfin se intenta mover hacia la izquierda
                pasoHorizontal = -1;
            } else {
                pasoHorizontal = 1;
            }

            int filaActual = filaInicial + pasoVertical;
            int columnaActual = columnaInicial + pasoHorizontal;

            while(abs(filaActual) < abs(filaFinal)){
                // Verifica que no hayan colisiones de por medio en el paso del alfil a su posicion deseada

                char piezaPosicionActual = posiciones[filaActual-1][columnaActual-1].at(0);

                if(piezaPosicionActual != ' '){
                    // Si la celda no esta vacia
                    return false;
                }

                filaActual = filaActual + pasoVertical;
                columnaActual = columnaActual + pasoHorizontal;
            }

            return true;
        }

        if (pieza == "r" || pieza == "R"){
            // Verifica una torre negra o blanca

            int pasoVertical;
            int pasoHorizontal;

            // Verifica el movimiento diagonal hacia arriba
            
            if(movimientoVertical < 0){
                // La torre se intenta mover hacia abajo
                pasoVertical = -1;
            } else  if (movimientoVertical > 0){
                // La torre se intenta mover hacia arriba
                pasoVertical = 1;
            } else {
                // La torre no se mueve ni arriba ni abajo
                pasoVertical = 0;
            }

            if(movimientoHorizontal < 0){
                // La torre se intenta mover hacia la izquierda
                pasoHorizontal = -1;
            } else  if (movimientoHorizontal > 0){
                // La torre se intenta mover hacia la derecha
                pasoHorizontal = 1;
            } else {
                // La torre no se mueve ni a la derecha ni a la izquierda
                pasoHorizontal = 0;
            }

            if(abs(pasoHorizontal) == 1 && abs(pasoVertical) == 1){
                // Una torre solo se mueve en linea recta, no diagonalmente
                return false;
            }

            int filaActual = filaInicial + pasoVertical;
            int columnaActual = columnaInicial + pasoHorizontal;

            if(abs(pasoVertical) == 1){

                while(abs(filaActual) < abs(filaFinal)){
                    // Verifica que no hayan colisiones de por medio en el paso de la torre a su posicion deseada

                    char piezaPosicionActual = posiciones[filaActual-1][columnaActual-1].at(0);

                    if(piezaPosicionActual != ' '){
                        // Si la celda no esta vacia
                        return false;
                    }

                    filaActual = filaActual + pasoVertical;
                    columnaActual = columnaActual + pasoHorizontal;
                }

            } else if (abs(pasoHorizontal) == 1){

                while(abs(columnaActual) < abs(columnaFinal)){
                    // Verifica que no hayan colisiones de por medio en el paso de la torre a su posicion deseada

                    char piezaPosicionActual = posiciones[filaActual-1][columnaActual-1].at(0);

                    if(piezaPosicionActual != ' '){
                        // Si la celda no esta vacia
                        return false;
                    }

                    filaActual = filaActual + pasoVertical;
                    columnaActual = columnaActual + pasoHorizontal;
                }

            }
            
            return true;

        }

        if (pieza == "q" || pieza == "Q"){
            // Verifica una dama negra o blanca

            // Se puede hacer asumiendo que la dama es como una torre y un alfil en 1 pieza

            char piezaActual = pieza.at(0);

            string piezaTorre;
            string piezaAlfil;

            if(isupper(piezaActual)){
                // Si la reina es blanca, se asume como un alfil y torre blancas
                piezaTorre = "R";
                piezaAlfil = "B";

            } else {
                // Si la reina es negra, se asume como un alfil y torre negras
                piezaTorre = "r";
                piezaAlfil = "b";
            }

            boolean movimientoTorre = verificarMovimiento(piezaTorre, posicionInicial, posicionFinal);
            boolean movimientoAlfil = verificarMovimiento(piezaAlfil, posicionInicial, posicionFinal);

            return (movimientoTorre || movimientoAlfil);

        }

        if (pieza == "k" || pieza == "K"){
            // Verifica un rey negro o blanco

            if(abs(movimientoHorizontal) > 1){
                // El rey no puede moverse mas alla de una casilla horizontal
                return false;
            }

            if(abs(movimientoVertical) > 1){
                // El rey no puede moverse mas alla de una casilla vertical
                return false;
            }

            return true;
        }

        cout << "Pieza invalida" << endl;
        return false;
        
    }

    boolean verificarMovimientoAlgebraico(string posicionAlgInicial, string posicionAlgFinal){

        string piezaInicial = " ";
        string piezaFinal = " ";
        string posicionInicial;
        string posicionFinal;

        if(posicionAlgInicial.size() < 3){
            // Por notacion algebraica, si solo se incluyen las coordenadas, se asume que es un peon
            posicionInicial = posicionAlgInicial;
        } else {
            posicionInicial = posicionAlgInicial.substr(1,3);
            string pieza(1, posicionAlgInicial.at(0));
            piezaInicial = pieza;
        }

        if(posicionAlgFinal.size() < 3){
            // Por notacion algebraica, si solo se incluyen las coordenadas, se asume que es un peon
            posicionFinal = posicionAlgFinal;
        } else {
            posicionFinal = posicionAlgFinal.substr(1,3);
            string pieza(1, posicionAlgFinal.at(0));
            piezaFinal = pieza;
        }

        vector<int> coordenadasIniciales = letrasACoordenadas(posicionInicial);
        int filaInicial = coordenadasIniciales.at(0);
        int columnaInicial = coordenadasIniciales.at(1);

        vector<int> coordenadasFinales = letrasACoordenadas(posicionFinal);
        int filaFinal = coordenadasFinales.at(0);
        int columnaFinal = coordenadasFinales.at(1);

        string piezaPosicionInicial (1, posiciones[filaInicial-1][columnaInicial-1].at(0));
        string piezaPosicionFinal(1, posiciones[filaFinal-1][columnaFinal-1].at(0));

        if(piezaInicial == " "){
            if(piezaPosicionInicial == "p" || piezaPosicionInicial == "P"){
                piezaInicial = piezaPosicionInicial;
            } else {
                cout << "Pieza invalida!" << endl;
                return false;
            }
        }

        if(piezaFinal == " "){
            if(piezaPosicionFinal == "p" || piezaPosicionFinal == "P" || piezaPosicionFinal == " "){
                piezaFinal = piezaPosicionFinal;
            } else {
                cout << "Pieza invalida!" << endl;
                return false;
            }
        }

        // if(piezaInicial != piezaPosicionInicial || piezaFinal != piezaPosicionFinal){
        //     cout << "La pieza insertada no concuerda con la que esta en el tablero!" << endl;
        //     return false;
        // }


        return verificarMovimiento(piezaInicial, posicionInicial, posicionFinal);
    }

    void calcularMovimiento(string pieza){

        // Busca las piezas a mover
        vector<vector<int>> posicion_piezas;

        for (int i = 0; i <= 7; i++){
            for (int j = 0; j <= 7; j++){  
                
                if (posiciones[i][j] == pieza){

                    posicion_piezas.push_back({i+1, j+1});
                
                }
            }
        }

        string colorPieza;
        char piezaChar = pieza.at(0);

        if (isupper(piezaChar)){
            colorPieza = "Blancas";
        } else {
            colorPieza = "Negras";
        }

        piezaChar = tolower(piezaChar);

        string tipoPieza(1, piezaChar);
        string nombrePieza;
        string piezaAlgebraica;
        piezaAlgebraica = pieza;

        if(tipoPieza == "p"){
            nombrePieza = "Peones";
            piezaAlgebraica = "";
        } else if (tipoPieza == "h"){
            nombrePieza = "Caballos";
        } else if (tipoPieza == "b"){
            nombrePieza = "Alfiles";
        } else if (tipoPieza == "r"){
            nombrePieza = "Torres";
        } else if (tipoPieza == "q"){
            nombrePieza = "Reinas";
        } else if (tipoPieza == "k"){
            nombrePieza = "Rey";
        } else {
            cout << "Pieza invalida!" << endl;
            return;
        }

        cout << "Calculando movimientos para piezas" << endl;
        cout << "Color: " << colorPieza << endl;
        cout << "Tipo: " << nombrePieza << endl << endl;
        
        for(int i = 0; i < posicion_piezas.size(); i++){

                vector<int> posicion_pieza = posicion_piezas.at(i);
                int fila_pieza = posicion_pieza.at(0);
                int columna_pieza = posicion_pieza.at(1);

                for(int i = 1; i <= 8; i++){
                    for(int j = 1; j <= 8; j++){
                        
                        string posicionInicial = coordenadasALetras(fila_pieza, columna_pieza);
                        string posicionFinal = coordenadasALetras(i, j);

                        if(verificarMovimiento(pieza, posicionInicial, posicionFinal)){

                            string piezaDestino = posiciones[i-1][j-1];
                            if(piezaDestino == "p" || piezaDestino == "P"){
                                piezaDestino = " ";
                            }
                            
                            cout << piezaAlgebraica << posicionInicial <<" -> "<< piezaDestino << posicionFinal << endl;
                
                        }
                    }
                }
            }
    }

    void realizarMovimiento(string posicionAlgInicial, string posicionAlgFinal){

        if(verificarMovimientoAlgebraico(posicionAlgInicial, posicionAlgFinal)){

            string piezaInicial = " ";
            string piezaFinal = " ";
            string posicionInicial;
            string posicionFinal;

            if(posicionAlgInicial.size() < 3){
                // Por notacion algebraica, si solo se incluyen las coordenadas, se asume que es un peon
                posicionInicial = posicionAlgInicial;
            } else {
                posicionInicial = posicionAlgInicial.substr(1,3);
                string pieza(1, posicionAlgInicial.at(0));
                piezaInicial = pieza;
            }

            if(posicionAlgFinal.size() < 3){
                // Por notacion algebraica, si solo se incluyen las coordenadas, se asume que es un peon
                posicionFinal = posicionAlgFinal;
            } else {
                posicionFinal = posicionAlgFinal.substr(1,3);
                string pieza(1, posicionAlgFinal.at(0));
                piezaFinal = pieza;
            }

            vector<int> coordenadasIniciales = letrasACoordenadas(posicionInicial);
            int filaInicial = coordenadasIniciales.at(0);
            int columnaInicial = coordenadasIniciales.at(1);

            vector<int> coordenadasFinales = letrasACoordenadas(posicionFinal);
            int filaFinal = coordenadasFinales.at(0);
            int columnaFinal = coordenadasFinales.at(1);

            string piezaPosicionInicial (1, posiciones[filaInicial-1][columnaInicial-1].at(0));
            string piezaPosicionFinal(1, posiciones[filaFinal-1][columnaFinal-1].at(0));

            posiciones[filaFinal-1][columnaFinal-1] = piezaPosicionInicial;
            posiciones[filaInicial-1][columnaInicial-1] = " ";
        } else {
            cout << "Movimiento invalido!" << endl;
        }
    }

    vector<string> delimitar(string texto, string delimitador){

        int pos = 0;
        vector<string> elementos;

        std::string temp;

        while ((pos = texto.find(delimitador)) != string::npos) {
            
            temp = texto.substr(0, pos);
            elementos.push_back(temp);
            texto.erase(0, pos + delimitador.length());

        }
        
        elementos.push_back(texto);

        return elementos;
    }

};

int main(){

    Tablero ajedrez = Tablero("fen_ejemplo.fen");

    ajedrez.imprimirTablero();
    ajedrez.guardarPosicion();
    // Calcula el movimiento de los peones blancos
    ajedrez.calcularMovimiento("P");
    ajedrez.imprimirTablero();
    // El movimiento debe hacerse en notacion algebraica
    ajedrez.realizarMovimiento("b6", "c7");
    ajedrez.imprimirTablero();

    ajedrez.guardarPosicion();
}