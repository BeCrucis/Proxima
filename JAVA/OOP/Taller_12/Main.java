import java.io.IOException;
import java.util.*;

public class Main {

    private static Scanner sc = new Scanner(System.in).useDelimiter("\n");

    private static ArrayList<Pasajero> pasajeros = new ArrayList<>();
    private static Conductor conductor;
    private static ArrayList<Silla> sillas = new ArrayList<Silla>();

    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {
            sillas.add(new Silla(i));
        }

        while (true) {
            
            showMenu();

            System.out.print("Seleccion una opcion: ");
            String opt = sc.nextLine();
            
            if (opt.equals("1")){
                
                Persona personaBase = crearPersona();

                System.out.println("El pasajero tiene tarjeta de cliente? 1:SI ELSE:NO : ");
                String tarjeta = sc.nextLine();

                Pasajero temp;

                if(tarjeta.equals("1")){
                    temp = new Pasajero(personaBase, true);
                } else {
                    temp = new Pasajero(personaBase, false);
                }

                try {
                    addPassenger(temp);
                } catch (InvalidAgeException e) {
                    System.out.println("Edad de pasajero debe ser mayor a 0 y menor a 99, corregidlo!");
                    e.printStackTrace();
                    System.out.println();
                    System.out.println("Enter para continuar . . .");
                    sc.nextLine();
                    clearScreen();
                    continue;
                }
            }

            else if (opt.equals("2")){
                
                Persona personaBase = crearPersona();

                System.out.println("El conductor tiene pase? 1:SI ELSE:NO : ");
                String pase = sc.nextLine();

                Conductor temp;

                if(pase.equals("1")){
                    temp = new Conductor(personaBase, true);
                } else {
                    temp = new Conductor(personaBase, false);
                }

                try {
                    addDriver(temp);
                } catch (InvalidConductorException e) {
                    System.out.println("El conductor debe tener pase!");
                    e.printStackTrace();
                    System.out.println();
                    System.out.println("Enter para continuar . . .");
                    sc.nextLine();
                    clearScreen();
                    continue;

                }
            }

            else if (opt.equals("3")){
                
                MedioTransporte busesito = new MedioTransporte(conductor, pasajeros, sillas);

                Viaje viaje;

                try {
                    //La interfaz hace complicada la verificacion de ruta, lo hice lo mejor posible
                    viaje = new Viaje().crearViaje(null);
                } catch (InvalidRouteException e) {
                    System.out.println("Ruta invalida!");
                    e.printStackTrace();
                    System.out.println();
                    System.out.println("Enter para continuar . . .");
                    sc.nextLine();
                    clearScreen();
                    continue;
                }

                try {
                    busesito.enviarViaje(viaje);
                } catch (NoConductorException e) {
                    System.out.println("El viaje no tiene conductor!");
                    e.printStackTrace();
                    System.out.println();
                    System.out.println("Enter para continuar . . .");
                    sc.nextLine();
                    clearScreen();
                    continue;
                } catch (NoPassengersException e) {
                    System.out.println("El viaje no tiene pasajeros!");
                    e.printStackTrace();
                    System.out.println();
                    System.out.println("Enter para continuar . . .");
                    sc.nextLine();
                    clearScreen();
                    continue;
                }

                //Reinicia el viaje para el siguiente bus
                conductor = null;
                pasajeros  = new ArrayList<>();
                
            }

            else if (opt.equals("99")){
                System.exit(0);
            }

            System.out.println();
            System.out.println("Enter para continuar . . .");
            sc.nextLine();
            clearScreen();
        }
    }
    
    public static void showMenu(){

        System.out.println("Bienvenido al viajador!");
        System.out.println();
        System.out.println("Seleccione su opcion: ");
        System.out.println("1. Agregar pasajero al viaje");
        System.out.println("2. Agregar conductor al viaje");
        System.out.println("3. Crear viaje con las personas agregadas");
        System.out.println("99. Salir");
        System.out.println();

    }

    public static Persona crearPersona(){

        System.out.print("Inserte la ID de la persona: ");
        int id = Integer.parseInt(sc.nextLine());
        
        System.out.print("Inserte el nombre de la persona: ");
        String nombre = sc.nextLine();

        System.out.print("Inserte el apellido de la persona: ");
        String apellido = sc.nextLine();
        
        System.out.print("Inserte el nombre de la persona: ");
        int edad = Integer.parseInt(sc.nextLine());
        
        System.out.print("Inserte el documento de la persona: ");
        int documento = Integer.parseInt(sc.nextLine());
        
        Persona temp = new Persona(id, nombre, apellido, edad, documento);

        return temp;
    }

    public static void addPassenger(Pasajero pasajero) throws InvalidAgeException{

        int edadPasajero = pasajero.getEdad();
        
        if (edadPasajero < 1 || edadPasajero > 98){

            throw new InvalidAgeException();

        } else {
            pasajeros.add(pasajero);
        }
    }

    public static void addDriver(Conductor conductor) throws InvalidConductorException{

        if (conductor.hasPase() == false){

            throw new InvalidConductorException();

        } else {
            Main.conductor = conductor;
        }
    }

    public static void enviarViaje(){

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