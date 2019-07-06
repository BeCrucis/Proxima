public class NaveCargaGrande extends NaveCarga{

    static private String modeloNave = "Nave de carga M3G4";

    NaveCargaGrande(String matricula, int maximaCarga) {

        super(matricula, maximaCarga);
        precioPorCarga = 40;
        modeloNave = "Nave de carga M3G4";
    }
    
    public double precioAlquiler(int dias) {
        return dias * precioPorCarga;
    }
}