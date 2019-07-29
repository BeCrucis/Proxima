import java.io.IOException;
import java.util.*;

public class Main {

    private static final Scanner SCANNER = new Scanner(System.in);

    static ArrayList<Empleado> empleados = new ArrayList<>();
    static ArrayList<Empleado> empleadosActivos = new ArrayList<>();
    static ArrayList<Empleado> empleadosInactivos = new ArrayList<>();

    static ArrayList<Nodo> dependencias = new ArrayList<>();

    static ArrayList<Carrera> programas = new ArrayList<>();

    static ArrayList<Estudiante> estudiantes = new ArrayList<>();
    static ArrayList<Estudiante> estudiantesActivos = new ArrayList<>();
    static ArrayList<Estudiante> estudiantesInactivos = new ArrayList<>();

    static ArrayList<Carrera> programasPregrado = new ArrayList<>();
    static ArrayList<Carrera> programasMaestria = new ArrayList<>();
    static ArrayList<Carrera> programasDoctorado = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        Scanner sc = SCANNER.useDelimiter("\\n");

        ArrayList<String> tiposEmpleado = new ArrayList<>(List.of("Docente medio tiempo",
                "Docente tiempo completo", "Docente catedra", "Administrativo planta auxiliar",
                "Administrativo planta tecnico", "Administrativo planta profesional", "OPS"));

        ArrayList<String> tiposEstudiante = new ArrayList<>(List.of("Estudiante pregrado", "Estudiante maestria", "Estudiante doctorado"));


        crearDependencias(); // Crea dependencias basicas
        crearPersonasDemo(); // Crea empleados base

        while (true) {

            coolIntro();
            System.out.println("1. Agregar un empleado");
            System.out.println("2. Retirar un empleado");
            System.out.println("3. Activar un empleado");
            System.out.println("4. Eliminar un empleado");
            System.out.println("5. Liquidar empleado");
            System.out.println("6. Realizar nomina");
            System.out.println("7. Realizar pagos parafiscales");
            System.out.println("8. Realizar pagos de salud");
            System.out.println("9. Realizar pagos de pension");
            System.out.println("10. Cambiar empleado de dependencia");
            System.out.println("11. Nomina por dependencia");
            System.out.println("12. Agregar un estudiante");
            System.out.println("13. Retirar estudiante");
            System.out.println("14. Reactivar estudiante");
            System.out.println("15. Eliminar estudiante");
            System.out.println("16. Matricular estudiante en programa");
            System.out.println("17. Matricular estudiante en curso de asignatura"); // TODO
            System.out.println("18. Asignar horario a curso de asignatura");
            System.out.println("19. Asignar profesor a materia");
            System.out.println("20. Subir notas finales de estudiante");
            System.out.println("21. Promedio arimetico de estudiante arimetico y ponderado");
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

                System.out.print("Inserte el nivel ARL del empleado: ");
                int nivelARL = Integer.parseInt(sc.nextLine());

                System.out.println("Inserte la dependencia del empleado: ");
                Nodo dependenciaEmpleado = selectFromArrayList(dependencias);

                if (sueldoBase < Empleado.getSueldominimo()) {
                    System.out.println(
                            "ERROR: El empleado no debe morir de hambre, inserte un sueldo mayor a "
                                    + Empleado.getSueldominimo() + " Pesos");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }

                if (nivelARL < 1 || nivelARL > 5) {
                    System.out.println("ERROR: Nivel ARL invalido");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }

                Empleado tempEmpleado = null;

                if (tipoEmpleado.equals("OPS")) {
                    tempEmpleado = new OPS(nombre, documentoId, tipoEmpleado, sueldoBase, nivelARL,
                            dependenciaEmpleado);
                } else if (tipoEmpleado.equals("OPS")){
                    tempEmpleado = new Empleado(nombre, documentoId, tipoEmpleado, sueldoBase,
                            nivelARL, dependenciaEmpleado);
                } else {
                    tempEmpleado = new Docente(nombre, documentoId, tipoEmpleado, sueldoBase,
                            nivelARL, dependenciaEmpleado);
                }

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
                    if (empleadoSeleccionado.isActivo) {
                        empleadosActivos.remove(empleadoSeleccionado);
                    } else {
                        empleadosInactivos.remove(empleadoSeleccionado);
                    }

                    System.out.println("Empleado borrado, empleado ahora es nopersona!");
                    System.out.println("Plusempujar enter para continuar. . .");
                    sc.nextLine();
                } else {

                    System.out.println("No hay empleados a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }
            }

            if (opt.equals("5")) {

                if (!empleados.isEmpty()) {

                    System.out.println("Ha seleccionado liquidar un empleado: ");
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

                hacerNomina(empleadosActivos);

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
                    System.out.println("Pago de caja de compensacion: "
                            + empleado.getCajaCompensacionEmpleador() + " Pesos");
                    System.out.println("Pago de ICFB: " + empleado.getICBFEmpleador() + " Pesos");
                    System.out.println();
                }

                pagoTotal = pagoSENATotal + pagoCajaCompensacionTotal + pagoICBFTotal;

                System.out.println("Pagos de SENA totales: " + pagoSENATotal + " Pesos");
                System.out.println("Pagos de caja de compensacion totales: "
                        + pagoCajaCompensacionTotal + " Pesos");
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
                    System.out.println("Pago de salud por parte de empleado: "
                            + empleado.getSaludEmpleado() + " Pesos");
                    System.out.println("Pago de salud por parte de empleador: "
                            + empleado.getSaludEmpleador() + " Pesos");
                    System.out.println();
                }

                saludTotal = saludEmpleados + saludEmpleador;

                System.out.println("Pagos de salud totales por parte de empleados: "
                        + saludEmpleados + " Pesos");
                System.out.println("Pagos de salud totales por parte de empleador: "
                        + saludEmpleador + " Pesos");
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
                    System.out.println("Pago de pension por parte de empleado: "
                            + empleado.getPensionEmpleado() + " Pesos");
                    System.out.println("Pago de pension por parte de empleador: "
                            + empleado.getPensionEmpleador() + " Pesos");
                    System.out.println();
                }

                pensionTotal = pensionEmpleados + pensionEmpleador;

                System.out.println();
                System.out.println("Pagos de pension totales por parte de empleados: "
                        + pensionEmpleados + " Pesos");
                System.out.println("Pagos de pension totales por parte de empleador: "
                        + pensionEmpleador + " Pesos");
                System.out.println("Pagos de pension totales: " + pensionTotal + " Pesos");

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }

            if (opt.equals("10")) {

                System.out.println("Ha seleccionado cambiar a un empleado de dependencia");

                System.out.println("Seleccione un empleado: ");
                Empleado empleadoSeleccionado = selectFromArrayList(empleados);

                System.out.println(
                        "Seleccione la dependencia a la cual cambiar el siguiente empleado:");
                System.out.println(empleadoSeleccionado.toString());
                Nodo dependenciaSeleccionada = selectFromArrayList(dependencias);

                empleadoSeleccionado.setDependencia(dependenciaSeleccionada);

                System.out.println("Dependencia cambiada a " + dependenciaSeleccionada.toString());

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }
            if (opt.equals("11")) {

                System.out.println("Ha seleccionado hacer nomina por dependencia");
                Nodo dependenciaSeleccionada = selectFromArrayList(dependencias);

                ArrayList<Empleado> empleadosObtenidos = dependenciaSeleccionada.getEmpleados();

                clearScreen();

                System.out.println("Haciendo nomina de la siguiente dependencia: ");
                System.out.println(dependenciaSeleccionada.toString());

                hacerNomina(empleadosObtenidos);

                System.out.println();
                System.out.println("Presione Enter para continuar . . .");
                sc.nextLine();

            }

            if (opt.equals("12")) {

                System.out.println("Ha seleccionado crear un nuevo estudiante:");
                System.out.println();

                System.out.print("Inserte el nombre del estudiante: ");
                String nombre = sc.nextLine();

                System.out.print("Inserte el documento del estudiante: ");
                String documentoId = sc.nextLine();

                System.out.println("Inserte que tipo de estudiante es:");
                String tipoEstudiante = selectFromArrayList(tiposEstudiante);

                Estudiante tempEstudiante = new Estudiante(nombre, documentoId, tipoEstudiante);

                estudiantes.add(tempEstudiante);
                estudiantesActivos.add(tempEstudiante);

            }

            if (opt.equals("13")) {

                if (!estudiantesActivos.isEmpty()) {

                    System.out
                            .println("Ha seleccionado convertir a estudiante en no estudiante!: ");
                    Estudiante estudianteSeleccionado = selectFromArrayList(estudiantesActivos);

                    estudianteSeleccionado.retirarEstudiante();
                    estudiantesActivos.remove(estudianteSeleccionado);
                    estudiantesInactivos.add(estudianteSeleccionado);

                    System.out.println("Estudiante retirado, estudiante ahora es no estudiante!");
                    System.out.println("Presione enter para continuar. . .");
                    sc.nextLine();
                } else {

                    System.out.println("No hay estudiantes a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }
            }

            if (opt.equals("14")) {

                if (!estudiantesInactivos.isEmpty()) {

                    System.out
                            .println("Ha seleccionado convertir a no estudiante en estudiante!: ");
                    Estudiante estudianteSeleccionado = selectFromArrayList(estudiantesInactivos);

                    estudianteSeleccionado.activarEstudiante();
                    estudiantesInactivos.remove(estudianteSeleccionado);
                    estudiantesActivos.add(estudianteSeleccionado);

                    System.out
                            .println("No Estudiante activado, no estudiante ahora es estudiante!");
                    System.out.println("Presione enter para continuar. . .");
                    sc.nextLine();
                } else {

                    System.out.println("No hay estudiantes a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }
            }

            if (opt.equals("15")) {

                if (!estudiantes.isEmpty()) {

                    System.out.println("Ha seleccionado convertir a estudiante en nopersona!: ");
                    Estudiante estudianteSeleccionado = selectFromArrayList(estudiantes);

                    estudiantes.remove(estudianteSeleccionado);
                    if (estudianteSeleccionado.isActivo) {
                        estudiantesActivos.remove(estudianteSeleccionado);
                    } else {
                        estudiantesInactivos.remove(estudianteSeleccionado);
                    }

                    System.out.println("Estudiante borrado, estudiante ahora es nopersona!");
                    System.out.println("Plusempujar enter para continuar. . .");
                    sc.nextLine();
                } else {

                    System.out.println("No hay estudiantes a seleccionar!");
                    System.out.println("Presione enter para continuar . . .");
                    sc.nextLine();
                }
            }

            if (opt.equals("16")) {

                System.out.println("Ha seleccionado matricular a un estudiante a un programa");

                System.out.println("Seleccione un estudiante: ");
                Estudiante estudianteSeleccionado = selectFromArrayList(estudiantes);

                System.out.println("Seleccione el programa a matricular al estudiante:");
                System.out.println(estudianteSeleccionado.toString());

                Carrera programaSeleccionado = null;

                if (estudianteSeleccionado.getTipoEstudiante().toUpperCase().contains("PREGRADO")) {
                    programaSeleccionado = selectFromArrayList(programasPregrado);
                } else if (estudianteSeleccionado.getTipoEstudiante().toUpperCase()
                        .contains("MAESTRIA")) {
                    programaSeleccionado = selectFromArrayList(programasMaestria);
                } else if (estudianteSeleccionado.getTipoEstudiante().toUpperCase()
                        .contains("DOCTORADO")) {
                    programaSeleccionado = selectFromArrayList(programasDoctorado);
                } else {
                    System.out.println("Error: Tipo de estudiante invalido");
                    System.out.println();
                    System.out.println("Presione Enter para continuar . . .");
                    sc.nextLine();
                    continue;
                }

                programaSeleccionado.addEstudiante(estudianteSeleccionado);

                System.out
                        .println("Estudiante " + estudianteSeleccionado.toString() + "Agregado a:");
                System.out.println(programaSeleccionado.toString());

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

    public static void crearDependencias() {

        ArrayList<Nodo> nodos = new ArrayList<>();

        Nodo rectoria = new Nodo("Rectoria");
        Nodo vrInvestigacion = new Nodo(rectoria, "Vicerrectoria de Investigacion");
        Nodo vrAcademica = new Nodo(rectoria, "Vicerrectoria Academica");
        Nodo profesores = new Nodo(rectoria, "Vicerrectoria Administrativa");
        Nodo facultades = new Nodo(rectoria, "Decanato de facultad");
        Nodo fisicoMecanicas = new Nodo(facultades, "Facultad de ingenierias Fisicomecanicas");
        Nodo escSistemas = new Nodo(fisicoMecanicas, "Escuela de Ingenieria de sistemas");
        //Nodo maestriaSistemas = new Nodo(escSistemas, "Maestria en Ingenieria de Sistemas");
        Nodo escCivil = new Nodo(fisicoMecanicas, "Escuela de Ingenieria Civil");
        Nodo escMecanica = new Nodo(fisicoMecanicas, "Escuela de Ingenieria Mecanica");
        Nodo fisicoQuimicas = new Nodo(facultades, "Facultad de Ingenierias Fisicoquimicas");
        Nodo escPetroleos = new Nodo(fisicoQuimicas, "Escuela de Ingenieria de Petroleos");
        Nodo escIngQuimica = new Nodo(fisicoQuimicas, "Escuela de Ingenieria Quimica");
        Nodo ciencias = new Nodo(facultades, "Facultad de Ciencias");
        Nodo escFisica = new Nodo(ciencias, "Escuela de Fisica");
        Nodo escMatematicas = new Nodo(ciencias, "Escuela de Matematicas");
        Nodo cienciasHumanas = new Nodo(facultades, "Facultad de Ciencias Humanas");
        Nodo escFilosofia = new Nodo(cienciasHumanas, "Escuela de Filosofia");
        Nodo escTrabajoSocial = new Nodo(cienciasHumanas, "Escuela de Trabajo Social");
        Nodo salud = new Nodo(facultades, "Facultad de Salud");
        Nodo escMedicina = new Nodo(salud, "Escuela de Medicina");

        dependencias.add(rectoria);
        dependencias.addAll(rectoria.getRecursiveHijos());
    }

    public static void crearCarrerasDemo() {

        Carrera programa1 = new Carrera("Ing Sistemas", dependencias.get(10));
        Carrera programa2 = new Carrera("Maestria Sistemas", dependencias.get(10));
        Carrera programa3 = new Carrera("Doctorado Sistemas", dependencias.get(10)); 
        programasPregrado.add(programa1);
        programasPregrado.add(programa2);
        programasPregrado.add(programa3);

        Asignatura asignatura1 = new Asignatura("Calculo I", "0001", 4);
        Asignatura asignatura2 = new Asignatura("Calculo II", "0002", 4);
        Asignatura asignatura3 = new Asignatura("Calculo III", "0003", 4);
        Asignatura asignatura4 = new Asignatura("PIVU", "0004", 1);
        Asignatura asignatura5 = new Asignatura("Fiestologia", "0005", 2);
        Asignatura asignatura6 = new Asignatura("Trabajo de grado I", "0006", 10);
        Asignatura asignatura7 = new Asignatura("Bailoterapia", "0006", 3);

        programa1.addToPensun(asignatura1);
        programa1.addToPensun(asignatura2);
        programa1.addToPensun(asignatura4);
        programa1.addToPensun(asignatura6);

        programa2.addToPensun(asignatura3);
        programa2.addToPensun(asignatura5);
        programa2.addToPensun(asignatura6);

        programa3.addToPensun(asignatura7);
        programa3.addToPensun(asignatura6);

        Curso calculo1J2 = new Curso("2192J2", asignatura1, empleados.get(2), 30);
        Curso calculo1J3 = new Curso("2192J3", asignatura1, empleados.get(1), 30);
        Curso calculo2J4 = new Curso("2192J4", asignatura2, empleados.get(1), 30);
        Curso calculo2J5 = new Curso("2192AA1", asignatura2, empleados.get(2), 30);
        Curso calculo3J6 = new Curso("2192BO2", asignatura3, empleados.get(1), 30);
        Curso PIVUA1 = new Curso("2192A1", asignatura4, empleados.get(2), 30);
        Curso FiestologiaF3 = new Curso("2192F3", asignatura5, empleados.get(1), 30);
        Curso TrabajoGradoG6 = new Curso("2192G6", asignatura6, empleados.get(2), 30);
        Curso BailoterapiaF2 = new Curso("2192F2", asignatura7, empleados.get(1), 30);
        
    }

    public static void crearPersonasDemo() {

        Empleado demo1 = new Empleado("Juan J", "100232", "Demo", 900000, 2, dependencias.get(0));
        Empleado profe1 = new Empleado("Henry Ford", "100232", "Docente coche", 900000, 2, dependencias.get(10));
        Empleado profe2 = new Empleado("Jack el destripador", "100232", "Docente cuchilla", 900000, 2, dependencias.get(10));
        empleados.add(demo1);
        empleados.add(profe1);
        empleados.add(profe2);
        empleadosActivos.add(demo1);
        empleadosActivos.add(profe1);
        empleadosActivos.add(profe2);

        Estudiante demo2 = new Estudiante("Bolsa McBolsaface", "10020", "Estudiante Pregrado");
        Estudiante demo3 = new Estudiante("Lobito", "10020", "Estudiante Maestria");
        Estudiante demo4 = new Estudiante("Dr Strange", "10020", "Estudiante Doctorado");
        estudiantes.add(demo2);
        estudiantes.add(demo3);
        estudiantes.add(demo4);
        estudiantesActivos.add(demo2);
        estudiantesActivos.add(demo3);
        estudiantesActivos.add(demo4);
    }

    public static void hacerNomina(ArrayList<Empleado> empleados) {

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

        for (Empleado empleado : empleados) {
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

        System.out.printf(
                "El Pago a administradoras y fondos por parte del empleador total es de: %f Pesos\n",
                pagoEmpleadorTotal);

    }

    //Funcion generica que devuelte un objeto seleccionado de un ArrayList
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
