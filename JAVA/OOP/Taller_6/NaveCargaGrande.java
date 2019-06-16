public class NaveCargaGrande extends NaveCarga{

    NaveCargaGrande(String matricula, int maximaCarga) {

        super(matricula, maximaCarga);
        precioPorCarga = 40;
    }
    
    int precioAlquiler(int dias) {
        return dias * precioPorCarga;
    }
}