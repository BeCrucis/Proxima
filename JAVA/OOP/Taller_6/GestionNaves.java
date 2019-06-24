import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class GestionNaves {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        ArrayList<Nave> naves = new ArrayList<Nave>();
      
        while(true){

            System.out.println("Bienvenido al gestionador de naves!");
            System.out.println();
            System.out.println("Lista de opciones: ");
            System.out.println("1. Agregar nave");
            System.out.println("2. Obtener precio de nave");
            System.out.println("3. Mostrar todos los precios");
            System.out.println("99. Salir del programa");
            System.out.println();
            System.out.println("Inserte su opcion: ");

            String op = sc.nextLine();

            if (op.equals("1")) {

                clearScreen();
            
                System.out.println("Ha seleccionado: Agregar nave");
                System.out.println();
                System.out.println("Lista de naves: ");
                System.out.println("1. Nave de carreras Kestrel");
                System.out.println("2. Nave de transporte de pasajeros TransLinea");
                System.out.println("3. Nave de carga M1N1");
                System.out.println("4. Nave de carga M3G4");
                System.out.println();
                System.out.println("Inserte su opcion: ");

                String naveSeleccionada = sc.nextLine();

                Nave naveCreada = crearNaveSeleccionada(Integer.parseInt(naveSeleccionada));

                naves.add(naveCreada);

            }

            if (op.equals("99")) {
                System.exit(0);
            }

            clearScreen();
        }
    
    }

    public static Nave crearNaveSeleccionada(int naveSeleccionada){

        clearScreen();

        if (naveSeleccionada == 1) {
            
            System.out.println("Ha seleccionado: Nave de carreras Kestrel");
            System.out.println();

            System.out.print("Inserte la matricula de la nave: ");
            String matriculaNave = sc.nextLine();
            
            System.out.print("Inserte el nombre del hangar de la nave: ");
            String hangarNave = sc.nextLine();
            
            Nave naveCreada = new NaveCarreras(matriculaNave, hangarNave);

            return naveCreada;
        }

        else if (naveSeleccionada == 2) {
            
            System.out.println("Ha seleccionado: Nave de transporte de pasajeros TransLinea");
            System.out.println();

            System.out.print("Inserte la matricula de la nave: ");
            String matriculaNave = sc.nextLine();
            
            System.out.print("Inserte el nombre del hangar de la nave: ");
            String hangarNave = sc.nextLine();
            
            Nave naveCreada = new NaveTransportePasajero(matriculaNave, hangarNave);

            return naveCreada;
        }

        else if (naveSeleccionada == 3) {
            
            System.out.println("Ha seleccionado: Nave de carga M1N1");
            System.out.println();

            System.out.print("Inserte la matricula de la nave: ");
            String matriculaNave = sc.nextLine();
            
            System.out.print("Inserte la capacidad maxima de la nave (En toneladas): ");
            int maximaCarga = Integer.parseInt(sc.nextLine());
            
            Nave naveCreada = new NaveCargaPequena(matriculaNave, maximaCarga);

            return naveCreada;
        }

        else if (naveSeleccionada == 4) {
            
            System.out.println("Ha seleccionado: Nave de carga M3G4");
            System.out.println();

            System.out.print("Inserte la matricula de la nave: ");
            String matriculaNave = sc.nextLine();
            
            System.out.print("Inserte la capacidad maxima de la nave (En toneladas): ");
            int maximaCarga = Integer.parseInt(sc.nextLine());
            
            Nave naveCreada = new NaveCargaGrande(matriculaNave, maximaCarga);

            return naveCreada;
        }

        else{
            System.out.println("Opcion no valida, Enter para continuar . . .");
            sc.nextLine();

            return null;       
        }
        
    }

    public static void clearScreen(){

        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (IOException | InterruptedException ex) {}
    }
}