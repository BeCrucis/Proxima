public class NaveCarga extends Nave {

    int precioPorCarga;
    private int maximaCarga;

    NaveCarga(String matricula, int maximaCarga) {
        super(matricula);
        this.maximaCarga = maximaCarga;
    }

    int precioAlquiler(int dias) {

        return dias * (super.precioPorDia + precioPorCarga * maximaCarga);
    }
    
}