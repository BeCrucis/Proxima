import java.io.IOException;
import java.util.*;

public class Main {

    private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        Scanner sc = SCANNER.useDelimiter("\\n");
        ArrayList<String> tiposEmpleado = new ArrayList<>(List.of(
            "Docente medio tiempo", "Docente tiempo completo", "Docente catedra", 
            "Administrativo planta auxiliar", "Administrativo planta tecnico", "Administrativo planta profesional",
            "OPS"));

        ArrayList<Empleado> empleados = new ArrayList<>();
        ArrayList<Empleado> empleadosActivos = new ArrayList<>();
        ArrayList<Empleado> empleadosInactivos = new ArrayList<>();

        Empleado demo = new Empleado("Juan jose","100232", "EmpleadoDemo", 900000, 2);
        empleados.add(demo);
        empleadosActivos.add(demo);

        Nodo rectoria = new Nodo("Rectoria");
        Nodo profesores = new Nodo(rectoria, "Profesorado");

        while (true) {

            coolIntro();
            System.out.println("1. Agregar un empleado");
            System.out.println("2. Retirar un empleado");
            System.out.println("3. Activar un empleado");
            System.out.println("4. Eliminar un empleado");
            System.out.println("5. Ver informacion de empleado");
            System.out.println("6. Realizar nomina");
            System.out.println("7. Realizar pagos parafiscales"); 
            System.out.println("8. Realizar pagos de salud");
            System.out.println("9. Realizar pagos de pension");
            System.out.println("10. Cambiar empleado de dependencia"); //TODO
            System.out.println("11. Nomina por dependencia");
            System.out.println("99. Salir del programa");
            System.out.println();
            System.out.print("Inserte su opcion: ");
            String opt = sc.nextLine();

            clearScreen();

            if (opt.equals("1")) {

                System.out.println("Ha seleccionado crear un nuevo empleado:");
                System.out.println();

                System.out.print("Inserte el nombre del empleado: ");
                String nombre = sc.nextLine();

                System.out.print("Inserte el documento del empleado: ");
                String documentoId = sc.nextLine();

                System.out.print("Inserte el sueldo del empleado: ");
                double sueldoBase = Double.parseDouble(sc.nextLine());

                System.out.println("Inserte que tipo de empleado es:");
                String tipoEmpleado = selectFromArrayList(tiposEmpleado);

                int nivelARL = 0;

                if (!tipoEmpleado.equals("OPS")) {
                    nivelARL = 1;
                } else {
                    System.out.print("Inserte el nivel ARL del empleado: ");
                    nivelARL = Integer.parseInt(sc.nextLine());
                }

                if (sueldoBase < Empleado.getSueldominimo()) {
                    System.out.println("ERROR: El empleado no debe morir de hambre, inserte un sueldo mayor a "
                                    + Empleado.getSueldominimo() + " Pesos");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }

                if (nivelARL < 1 || nivelARL > 5) {
                    System.out.println("ERROR: Nivel ARL invalido");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }

                Empleado tempEmpleado = new Empleado(nombre, documentoId, tipoEmpleado, sueldoBase, nivelARL);
                empleados.add(tempEmpleado);
                empleadosActivos.add(tempEmpleado);

            }

            if (opt.equals("2")) {
                
                if (!empleadosActivos.isEmpty()) {
                    
                    System.out.println("Ha seleccionado convertir a empleado en no empleado!: ");
                    Empleado empleadoSeleccionado = selectFromArrayList(empleadosActivos);

                    empleadoSeleccionado.retirarEmpleado();
                    empleadosActivos.remove(empleadoSeleccionado);
                    empleadosInactivos.add(empleadoSeleccionado);

                    System.out.println("Empleado retirado, empleado ahora es no empleado!");
                    System.out.println("Presione enter para continuar. . .");
                    sc.nextLine();   
                } else { 
                    
                    System.out.println("No hay empleados a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();   
                }
            }

            if (opt.equals("3")) {
                
                if (!empleadosInactivos.isEmpty()) {
                    
                    System.out.println("Ha seleccionado convertir a no empleado en empleado!: ");
                    Empleado empleadoSeleccionado = selectFromArrayList(empleadosInactivos);

                    empleadoSeleccionado.activarEmpleado();
                    empleadosInactivos.remove(empleadoSeleccionado);
                    empleadosActivos.add(empleadoSeleccionado);

                    System.out.println("No Empleado activado, no empleado ahora es empleado!");
                    System.out.println("Presione enter para continuar. . .");
                    sc.nextLine();   
                } else { 
                    
                    System.out.println("No hay empleados a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();   
                }
            }

            if (opt.equals("4")) {
                
                if (!empleados.isEmpty()) {
                    
                    System.out.println("Ha seleccionado convertir a empleado en nopersona!: ");
                    Empleado empleadoSeleccionado = selectFromArrayList(empleados);

                    empleados.remove(empleadoSeleccionado);
                    if(empleadoSeleccionado.isActivo){
                        empleadosActivos.remove(empleadoSeleccionado);
                    } else { empleadosInactivos.remove(empleadoSeleccionado);}

                    System.out.println("Empleado borrado, empleado ahora es nopersona!");
                    System.out.println("Plusempujar enter para continuar. . .");
                    sc.nextLine();   
                } else { 
                    
                    System.out.println("No hay empleados a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();   
                }
            }

            if(opt.equals("5")){

                if (!empleados.isEmpty()) {
                    
                    System.out.println("Ha seleccionado ver informacion de un empleado: ");
                    Empleado empleadoSeleccionado = selectFromArrayList(empleados);
                    
                    clearScreen();

                    System.out.println(empleadoSeleccionado.infoPagosTotales()); 
                    
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();   
                } else { 
                    
                    System.out.println("No hay empleados a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();   
                }

            }

            if (opt.equals("6")) {

                System.out.println("Imprimiendo detalles individuales: ");
                System.out.println();
                double nominaTotal = 0;
                double costoEmpleados = 0;
                double pagoSueldoEmpleados = 0;
                double pagoEmpleadorSalud = 0;
                double pagoEmpleadorPension = 0;
                double pagoEmpleadorSENA = 0;
                double pagoEmpleadorCajaCompensacion = 0;
                double pagoEmpleadorICBF = 0;
                double pagoEmpleadorARL = 0;
                double pagoEmpleadorTotal = 0;

                for (Empleado empleado : empleadosActivos) {
                    costoEmpleados += empleado.getSueldoBase();
                    pagoSueldoEmpleados += empleado.getSueldoFinalEmpleado();
                    pagoEmpleadorSalud += empleado.getSaludEmpleador();
                    pagoEmpleadorPension += empleado.getPensionEmpleador();
                    pagoEmpleadorSENA += empleado.getSENAEmpleador();
                    pagoEmpleadorCajaCompensacion += empleado.getCajaCompensacionEmpleador();
                    pagoEmpleadorICBF += empleado.getICBFEmpleador();
                    pagoEmpleadorARL += empleado.getARLEmpleador();
                    pagoEmpleadorTotal += empleado.getPagosEmpleador();
                    
                    System.out.println(empleado.infoPagosTotales());
                }

                nominaTotal = costoEmpleados + pagoEmpleadorTotal;
                
                System.out.println();
                System.out.printf("La nomina total es de : %f Pesos\n", nominaTotal);
                System.out.printf("El costo por empleados total es de : %f Pesos\n", costoEmpleados);
                System.out.printf("El pago a empleados total es de : %f Pesos\n", pagoSueldoEmpleados);
                System.out.printf("Pagos totales por parte de empleador:\n");
                System.out.printf("Salud: %f\n", pagoEmpleadorSalud);
                System.out.printf("Pension: %f\n", pagoEmpleadorPension);
                System.out.printf("SENA: %f\n", pagoEmpleadorSENA);
                System.out.printf("Caja de compensacion: %f\n", pagoEmpleadorCajaCompensacion);
                System.out.printf("ICBF: %f\n", pagoEmpleadorICBF);
                System.out.printf("ARL: %f\n", pagoEmpleadorARL);

                System.out.printf("El Pago a administradoras y fondos por parte del empleador total es de: %f Pesos\n", pagoEmpleadorTotal);
                
                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();
            }

            if (opt.equals("7")) {

                System.out.println("Ha seleccionado hacer pagos parafiscales");
                System.out.println();

                System.out.println("Imprimiendo detalles individuales: ");
                System.out.println();

                double pagoTotal = 0;
                double pagoSENATotal = 0;
                double pagoCajaCompensacionTotal = 0;
                double pagoICBFTotal = 0;
                
                
                for (Empleado empleado : empleadosActivos) {
                    
                    pagoSENATotal += empleado.getSENAEmpleador();
                    pagoCajaCompensacionTotal += empleado.getCajaCompensacionEmpleador();
                    pagoICBFTotal += empleado.getICBFEmpleador();

                    System.out.println(empleado.toString());
                    System.out.println("Pago de SENA: " + empleado.getSENAEmpleador() + " Pesos");
                    System.out.println("Pago de caja de compensacion: " + empleado.getCajaCompensacionEmpleador() + " Pesos");
                    System.out.println("Pago de ICFB: " + empleado.getICBFEmpleador() + " Pesos");
                    System.out.println();
                }

                pagoTotal = pagoSENATotal + pagoCajaCompensacionTotal + pagoICBFTotal;

                System.out.println("Pagos de SENA totales: " + pagoSENATotal + " Pesos");
                System.out.println("Pagos de caja de compensacion totales: " + pagoCajaCompensacionTotal + " Pesos");
                System.out.println("Pagos de ICFB totales: " + pagoICBFTotal + " Pesos");
                System.out.println();
                System.out.println("Pagos parafiscales totales: " + pagoTotal + " Pesos");

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }

            if (opt.equals("8")) {

                System.out.println("Ha seleccionado hacer pagos de salud");
                System.out.println();

                System.out.println("Imprimiendo detalles individuales: ");
                System.out.println();

                double saludTotal = 0;
                double saludEmpleados = 0;
                double saludEmpleador = 0;
                
                for (Empleado empleado : empleadosActivos) {
                    
                    saludEmpleados += empleado.getSaludEmpleado();
                    saludEmpleador += empleado.getSaludEmpleador();

                    System.out.println(empleado.toString());
                    System.out.println("Pago de salud por parte de empleado: " + empleado.getSaludEmpleado() + " Pesos");
                    System.out.println("Pago de salud por parte de empleador: " + empleado.getSaludEmpleador() + " Pesos");
                    System.out.println();
                }

                saludTotal = saludEmpleados + saludEmpleador;

                System.out.println("Pagos de salud totales por parte de empleados: " + saludEmpleados + " Pesos");
                System.out.println("Pagos de salud totales por parte de empleador: " + saludEmpleador + " Pesos");
                System.out.println("Pagos de salud totales: " + saludTotal + " Pesos");

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }

            if (opt.equals("9")) {

                System.out.println("Ha seleccionado hacer pagos de pension");
                System.out.println();

                System.out.println("Imprimiendo detalles individuales: ");
                System.out.println();

                double pensionTotal = 0;
                double pensionEmpleados = 0;
                double pensionEmpleador = 0;
                
                for (Empleado empleado : empleadosActivos) {
                    
                    pensionEmpleados += empleado.getPensionEmpleado();
                    pensionEmpleador += empleado.getPensionEmpleador();

                    System.out.println(empleado.toString());
                    System.out.println("Pago de pension por parte de empleado: " + empleado.getPensionEmpleado() + " Pesos");
                    System.out.println("Pago de pension por parte de empleador: " + empleado.getPensionEmpleador() + " Pesos");
                    System.out.println();
                }

                pensionTotal = pensionEmpleados + pensionEmpleador;

                System.out.println();
                System.out.println("Pagos de pension totales por parte de empleados: " + pensionEmpleados + " Pesos");
                System.out.println("Pagos de pension totales por parte de empleador: " + pensionEmpleador + " Pesos");
                System.out.println("Pagos de pension totales: " + pensionTotal + " Pesos");

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }

            if (opt.equals("99")) {
                System.exit(0);
            }

            clearScreen();

        }

    }

    public static void coolIntro() {
        System.out.println("  ________   __   _______  ____   ___   ___  ____  ___ ");
        System.out.println(" / ___/ _ | / /  / ___/ / / / /  / _ | / _ \\/ __ \\/ _ \\");
        System.out.println("/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ // / /_/ / , _/");
        System.out.println("\\___/_/ |_/____/\\___/\\____/____/_/_|_/____/\\____/_/|_| ");
        System.out.println("  / _ \\/ __/          / |/ / __ \\/  |/  /  _/ |/ / _ | ");
        System.out.println(" / // / _/           /    / /_/ / /|_/ // //    / __ | ");
        System.out.println("/____/___/          /_/|_/\\____/_/  /_/___/_/|_/_/ |_| ");
        System.out.println("                                                       ");

    }

    public static <Obj> Obj selectFromArrayList(ArrayList<Obj> list) {

        if (list.isEmpty()) {
            System.out.println("Lista vacia, saliendo . . .");
            return null;
        }

        Scanner tmpsc = SCANNER;

        for (Obj var : list) {
            System.out.println((list.indexOf(var) + 1) + ". " + var.toString());
        }

        System.out.println();
        System.out.print("Inserte su opcion: ");
        int opt = Integer.parseInt(tmpsc.nextLine());

        return list.get(opt - 1);
    }

    public static void clearScreen() throws IOException {
    
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (InterruptedException ex) {
        }
    }

}