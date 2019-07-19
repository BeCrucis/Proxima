public class OPS extends Empleado{

    public OPS(String nombre, String documentoId, double sueldoBase, int nivelARL) {
        super(nombre, documentoId, sueldoBase, nivelARL);

        this.nivelARL = 0;
    }

    @Override
    public double getPagosEmpleador() {
        return 0;
    }
    
    @Override
    public double getSueldoFinalEmpleado() {
        return sueldoBase;
    }
}