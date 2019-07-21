public class OPS extends Empleado{

    public OPS(String nombre, String documentoId, double sueldoBase, int nivelARL) {
        super(nombre, documentoId, "OPS", sueldoBase, nivelARL);

        this.nivelARL = 0;
    }

    public double getSaludEmpleado(){
        return 0;
    }

    public double getSaludEmpleador(){
        return 0;
    }

    public double getPensionEmpleado(){
        return 0;
    }

    public double getPensionEmpleador(){
        return 0;    
    }

    public double getSENAEmpleador(){
        return 0;    
    }

    public double getCajaCompensacionEmpleador(){
        return 0;    
    }

    public double getICBFEmpleador(){
        return 0;    
    }

    public double getARLEmpleador(){
        return 0;
    }

    public double getPagosEmpleador() {
        return 0;
    }
    
    public double getSueldoFinalEmpleado() {
        return sueldoBase;
    }
}