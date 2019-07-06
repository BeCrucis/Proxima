public class NaveCarga extends Nave {

    public int precioPorCarga;
    private int maximaCarga;

    NaveCarga(String matricula, int maximaCarga) {
        super(matricula);
        this.maximaCarga = maximaCarga;
    }

    public double precioAlquiler(int dias) {

        return dias * (super.precioPorDia + precioPorCarga * maximaCarga);
    }

    public int getMaximaCarga(){
        return maximaCarga;
    }
    
    public String toString() {
        return String.format("Modelo de nave: %s - Matricula: %s - Carga maxima: %s", getModeloNave(), getMatricula(), getMaximaCarga());
    }
}