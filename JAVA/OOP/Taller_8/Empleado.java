public class Empleado extends Persona{

    static private final double sueldoMinimo = 828116;
    static private final double auxilioTransporte = 97032;

    static private final double porcentajeSaludEmpleado = 0.04;
    static private final double porcentajeSaludEmpleador = 0.085;
    static private final double porcentajePensionEmpleado = 0.04;
    static private final double porcentajePensionEmpleador = 0.16;
    static private final double porcentajeSENAEmpleador = 0.02;
    static private final double porcentajeCajaCompensacionEmpleador = 0.04;
    static private final double porcentajeICBFEmpleador = 0.03;
    static private final double porcentajeARLtipo1Empleador = 0.00348;
    static private final double porcentajeARLtipo2Empleador = 0.00435;
    static private final double porcentajeARLtipo3Empleador = 0.00783;
    static private final double porcentajeARLtipo4Empleador = 0.01740;
    static private final double porcentajeARLtipo5Empleador = 0.03219;

    protected boolean tieneAuxilio = true;

    private double sueldoBase;
    private double sueldoFinal;
    private int nivelARL;

    public Empleado(String nombre, double sueldoBase, int nivelARL) {
        super(nombre);

        this.sueldoBase = sueldoBase;
        this.nivelARL = nivelARL;
        this.sueldoFinal = getSueldoFinalEmpleado();

    }
    
    private double getSaludEmpleado(){


        return sueldoBase*porcentajeSaludEmpleado;
    }

    private double getSaludEmpleador(){

        return sueldoBase*porcentajeSaludEmpleador;
    }

    private double getPensionEmpleado(){
        return sueldoBase*porcentajePensionEmpleado;
    }

    private double getPensionEmpleador(){
        return sueldoBase*porcentajePensionEmpleador;
    }

    private double getSENAEmpleador(){
        return sueldoBase*porcentajeSENAEmpleador;
    }

    private double getCajaCompensacionEmpleador(){
        return sueldoBase*porcentajeCajaCompensacionEmpleador;
    }

    private double getICBFEmpleador(){
        return sueldoBase*porcentajeICBFEmpleador;
    }

    private double getARLEmpleador(){

        if(nivelARL == 1) return sueldoBase*porcentajeARLtipo1Empleador;

        else if (nivelARL == 2) return sueldoBase*porcentajeARLtipo2Empleador;

        else if (nivelARL == 3) return sueldoBase*porcentajeARLtipo3Empleador;

        else if (nivelARL == 4) return sueldoBase*porcentajeARLtipo4Empleador;

        else return sueldoBase*porcentajeARLtipo5Empleador;

    }

    public double getSueldoFinalEmpleado(){

        double costoSalud = getSaludEmpleado();
        double costoPension = getPensionEmpleado();
        double ingresoExtra = 0;

        if(tieneAuxilio){

            ingresoExtra = auxilioTransporte;
        }
        
        double sueldoFinal = sueldoBase - costoSalud - costoPension + ingresoExtra;

        return sueldoFinal;
    }

    public double getPagosEmpleador(){

        double costoSalud = getSaludEmpleador();
        double costoPension = getPensionEmpleador();
        double costoSENA = getSENAEmpleador();
        double costoCajaCompensacion = getCajaCompensacionEmpleador();
        double costoICBF = getICBFEmpleador();
        double costoARL = getARLEmpleador();

        return costoSalud + costoPension + costoSENA + costoCajaCompensacion + costoICBF + costoARL;
    }

    public String infoPagosTotales() {
        String infoEmpleado = String.format("Empleado : %s, ID: %d", getNombre(), getID());
        String infoSueldo = String.format("Sueldo base: %s, Sueldo real: %s", sueldoBase, sueldoFinal);
        String infoEmpleador = String.format("Pago a administradoras y fondos por parte del empleador: %s", getPagosEmpleador());

        String infoTotal = String.format("%s \n $s \n %s \n", infoEmpleado, infoSueldo, infoEmpleador);

        return infoTotal;
    }
}