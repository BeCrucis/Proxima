import java.util.Scanner;

/*
 En un casa de apuestas los jugadores tienen acciones las cuales 
 pueden apostar, cada acción se cotiza en $10,000, en una jornada 
 participan 5 jugadores, cada uno de ellos puede apostar una 
 determinada cantidad de acciones, al finalizar la jornada se debe 
 saber quien apostó mas y quien apostó menos. Como dato de entrada 
 se pide el número de acciones que apuesta cada jugador
 */

class Taller_1_2{
  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    System.out.println("Bienvenido al capitalismo de porodo!");

    long max = 0;
    int maxPlayer = 0;

    long min = 0;
    int minPlayer= 0;
    Boolean minCreated = false;

    for(int i = 1; i <= 5; i++){

      System.out.printf("Inserte las acciones apostadas por el jugador " + i + " : ");
      long apuesta = sc.nextInt() * 10000;

      if(!minCreated || apuesta < min){

        min = apuesta;
        minPlayer = i;
        minCreated = true;
      }

      if(apuesta > max){

        max = apuesta;
        maxPlayer = i;

      }
    }

    System.out.println("La menor apuesta fue por el jugador " + minPlayer + " Con una apuesta de $" + min);
    System.out.println("La mayor apuesta fue por el jugador " + maxPlayer + " Con una apuesta de $" + max);

    sc.close();
  }
}