import java.io.IOException;
import java.util.Scanner;

public class Main {

    private static int option;

	public static void main(String[] args) throws IOException{

        int clockYear = 2015, clockMonth = 19, clockDay = 120, clockHour = 20, clockMinute = 1, clockSecond = 1; //Valores de prueba
        int choice = 0;

        System.out.println("Bienvenido a don reloj!");
        System.out.println();
        Scanner sc = new Scanner(System.in);

        Boolean relojExists = true; //En caso de no querer colocar un reloj nuevo cada rato, colocar esto en true

        while (!relojExists) {

            System.out.print("No hay reloj creado, desea crear uno? (S:1/N:2): ");

            try {

                choice = Integer.parseInt(sc.nextLine());

            } catch (Exception e) {

                System.out.println("Opcion no valida, presione Enter para continuar . . .");
                sc.nextLine();
                clearScreen();
                continue;
            }

            System.out.println(choice);

            if (choice == 1) {

                System.out.printf("Inserte el año del nuevo reloj: ");
                clockYear = Integer.parseInt(sc.nextLine());

                System.out.printf("Inserte el dia del nuevo reloj: ");
                clockDay = Integer.parseInt(sc.nextLine());

                System.out.printf("Inserte el mes del nuevo reloj: ");
                clockMonth = Integer.parseInt(sc.nextLine());

                System.out.printf("Inserte el hora del nuevo reloj: ");
                clockHour = Integer.parseInt(sc.nextLine());

                System.out.printf("Inserte el minuto del nuevo reloj: ");
                clockMinute = Integer.parseInt(sc.nextLine());

                System.out.printf("Inserte el segundo del nuevo reloj: ");
                clockSecond = Integer.parseInt(sc.nextLine());

                relojExists = true;

            } else {
                continue;
            }
        }

        Clock reloj = new Clock(clockYear, clockMonth, clockDay, clockHour, clockMinute, clockSecond);
        ClockUpdater updater = new ClockUpdater(reloj); // Se crea un hilo separado encargado de aumentar el tiempo del
                                                        // reloj
        updater.start();

        int option;

        while (true) {

            System.out.println("Bienvenido al reloj!");
            System.out.println();
            System.out.println("Opciones:");
            System.out.println("1: Ver la hora");
            System.out.println("2: Cronometro");
            System.out.println("3: Alarma");
            System.out.println("4: Fecha");

            System.out.print("Elija una opcion: ");

            try{
                option = Integer.parseInt(sc.nextLine());
            } catch(Exception ex){
                option = 0;
                clearScreen();
                continue;
            }
            

            if (option == 1) {

                System.out.println(reloj.getFormattedTime());
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();
            }

            else if (option == 2) {

                clearScreen();
                Clock.cronometro();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();
            }

            else if (option == 3) {

                reloj.alarma();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();
            }

            else if (option == 4) {

                System.out.println(reloj.getFormattedDate());
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();
            }

            else {
                System.out.println("Opcion no valida, presione Enter para continuar . . .");
                sc.nextLine();
            }

            clearScreen();
        }

    }

    public static void clearScreen() {
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (Exception ex) {
        }
    }


}