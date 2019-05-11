import java.util.Scanner;

/*
  Se necesita saber el promedio de un alumno en una materia en la 
  que se califican tres cosas: 
  2. Examen escrito. 
  1. Entrega de proyecto. 
  2. talleres en clase. 
  2 quiz. 
  Se debe pedir el valor correspondiente a cada calificación y dar 
  salida el promedio de estas Calificaciones. Tomen los porcentajes 
  de notas de clase
  */

class Taller_1_1{
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);

    System.out.println("Bienvenido al calificador de porodo!");
    System.out.println();

    System.out.printf("Inserte el Examen escrito 1: ");
    double examen1 = sc.nextDouble();

    System.out.printf("Inserte el Examen escrito 2: ");
    double examen2 = sc.nextDouble();

    System.out.printf("Inserte el Proyecto: ");
    double proyecto1 = sc.nextDouble();

    System.out.printf("Inserte el Taller 1: ");
    double taller1 = sc.nextDouble();

    System.out.printf("Inserte el Taller 2: ");
    double taller2 = sc.nextDouble();

    System.out.printf("Inserte el Quiz 1: ");
    double quiz1 = sc.nextDouble();

    System.out.printf("Inserte el Quiz 2: ");
    double quiz2 = sc.nextDouble();

    //Porcentajes de cada tipo de calificacion en forma decimal
    double porcentajeExamen = 0.4;
    double porcentajeProyecto = 0.3;
    double porcentajeTaller = 0.2;
    double porcentajeQuiz = 0.1;

    //Promedios de cada tipo de calificacion para luego aplicar los porcentajes
    double promedioExamen = (examen1 + examen2)/2;
    double promedioTaller = (taller1 + taller2)/2;
    double promedioQuiz = (quiz1 + quiz2)/2;

    //Obtencion de notas con porcentaje para sumar en la nota final
    double notaExamen = promedioExamen * porcentajeExamen;
    double notaProyecto = proyecto1 * porcentajeProyecto;
    double notaTaller = promedioTaller * porcentajeTaller;
    double notaQuiz = promedioQuiz * porcentajeQuiz;

    double notaFinal = notaExamen + notaProyecto + notaTaller + notaQuiz;

    System.out.println("Su nota final es: " + notaFinal);

  }
}