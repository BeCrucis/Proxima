public class NaveCargaGrande extends NaveCarga{

    NaveCargaGrande(String matricula, int maximaCarga) {

        super(matricula, maximaCarga);
        precioPorCarga = 40;
        modeloNave = "Nave de carga M3G4";
    }
    
    public double precioAlquiler(int dias) {
        return dias * precioPorCarga;
    }
}