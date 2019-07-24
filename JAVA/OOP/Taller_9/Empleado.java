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
    protected boolean isActivo = true;

    protected double sueldoBase;
    protected int nivelARL;

    protected String tipoEmpleado;

    public Empleado(String nombre, String documentoId, String tipoEmpleado, double sueldoBase, int nivelARL){
        super(nombre, documentoId);

        this.tipoEmpleado = tipoEmpleado;
        this.sueldoBase = sueldoBase;
        this.nivelARL = nivelARL;

    }

    public static double getSueldominimo(){
        return sueldoMinimo;
    }

    private double getAuxiliaturas(){
        if(tieneAuxilio){
            return auxilioTransporte;
        } else return 0;
    }

    public double getSueldoBase(){
        return sueldoBase;
    }

    public String getTipoEmpleado() {
        return tipoEmpleado;
    }

    public void retirarEmpleado(){
        isActivo = false;
    }

    public void activarEmpleado(){
        isActivo = true;
    }

    public boolean isActivo(){
        return isActivo;
    }
    
    public double getSaludEmpleado(){


        return sueldoBase*porcentajeSaludEmpleado;
    }

    public double getSaludEmpleador(){

        return sueldoBase*porcentajeSaludEmpleador;
    }

    public double getPensionEmpleado(){
        return sueldoBase*porcentajePensionEmpleado;
    }

    public double getPensionEmpleador(){
        return sueldoBase*porcentajePensionEmpleador;
    }

    public double getSENAEmpleador(){
        return sueldoBase*porcentajeSENAEmpleador;
    }

    public double getCajaCompensacionEmpleador(){
        return sueldoBase*porcentajeCajaCompensacionEmpleador;
    }

    public double getICBFEmpleador(){
        return sueldoBase*porcentajeICBFEmpleador;
    }

    public double getARLEmpleador(){

        if(nivelARL == 1) return sueldoBase*porcentajeARLtipo1Empleador;

        else if (nivelARL == 2) return sueldoBase*porcentajeARLtipo2Empleador;

        else if (nivelARL == 3) return sueldoBase*porcentajeARLtipo3Empleador;

        else if (nivelARL == 4) return sueldoBase*porcentajeARLtipo4Empleador;

        else if (nivelARL == 5) return sueldoBase*porcentajeARLtipo5Empleador;

        else {
            System.out.println("Nivel ARL no valido");
            return 0;
        }

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
        String infoEmpleado = String.format("Empleado : %s, Tipo: %s, ID: %d", getNombre(), getTipoEmpleado(), getID());

        String infoSueldo = String.format("Sueldo base: %f\nPagos de salud por empleado: %f\nPagos de pension por empleado: %f\nAuxiliaturas al empleado: %f\nSueldo final: %f ", sueldoBase, getSaludEmpleado(), getPensionEmpleado(), getAuxiliaturas(), getSueldoFinalEmpleado());

        String infoEmpleador = String.format("Pagos de empleador: \nSalud: %f\nPension: %f\nSENA: %f\nCaja de compensacion: %f\nICBF: %f\nARL: %f\nPago a administradoras y fondos por parte del empleador total: %f", getSaludEmpleador(), getPensionEmpleador(), getSENAEmpleador(), getCajaCompensacionEmpleador(), getICBFEmpleador(), getARLEmpleador(), getPagosEmpleador());

        String infoTotal = String.format("%s \n%s \n%s \n", infoEmpleado, infoSueldo, infoEmpleador);

        return infoTotal;
    }

    @Override
    public String toString() {
        String formattedInfo = String.format("Empleado : %s, Tipo: %s, ID: %d", getNombre(), getTipoEmpleado(), getID());
        return formattedInfo;
    }
}