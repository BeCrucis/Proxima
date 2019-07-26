public class OPS extends Empleado {

    public OPS(String nombre, String documentoId, String tipo, double sueldoBase, int nivelARL,
            Nodo dependencia) {
        super(nombre, documentoId, tipo, sueldoBase, nivelARL, dependencia);

    }

    public double getSaludEmpleado() {
        return 0;
    }

    public double getSaludEmpleador() {
        return 0;
    }

    public double getPensionEmpleado() {
        return 0;
    }

    public double getPensionEmpleador() {
        return 0;
    }

    public double getSENAEmpleador() {
        return 0;
    }

    public double getCajaCompensacionEmpleador() {
        return 0;
    }

    public double getICBFEmpleador() {
        return 0;
    }

    public double getARLEmpleador() {
        return 0;
    }

    public double getPagosEmpleador() {
        return 0;
    }

    public double getSueldoFinalEmpleado() {
        return sueldoBase;
    }
}
