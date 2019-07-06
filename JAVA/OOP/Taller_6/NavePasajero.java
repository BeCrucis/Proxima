public class NavePasajero extends Nave{

    public double precioDiaHangar;
    private String hangar;

    NavePasajero(String matricula, String hangar) {
        super(matricula);
        
        this.hangar = hangar;
    }

    public double precioAlquiler(int dias){

        return dias * (super.precioPorDia + 1.5 + precioDiaHangar);
    }

    public String getHangar() {
        return hangar;
    }

    public String toString() {
        return String.format("Modelo de nave: %s - Matricula: %s - Nombre hangar: %s", getModeloNave(), getMatricula(), getHangar());
    }
}