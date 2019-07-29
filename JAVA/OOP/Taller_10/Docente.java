public class Docente extends Empleado{

    public Docente(String nombre, String documentoId, String tipoEmpleado, double sueldoBase,
            int nivelARL, Nodo dependencia) {
        super(nombre, documentoId, tipoEmpleado, sueldoBase, nivelARL, dependencia);

    }

    public void hacerCosa(){
        System.out.println("Cosa de docente");
    }
    
}