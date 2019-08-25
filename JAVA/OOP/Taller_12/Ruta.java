import java.util.ArrayList;

public class Ruta {

    private Estacion estacion;
    ArrayList<Estacion> estaciones;

    public Ruta(Estacion estacion, ArrayList<Estacion> estaciones) {
        this.estacion = estacion;
        this.estaciones = estaciones;
    }
    
    public Estacion getEstacion() {
        return estacion;
    }

    public void setEstacion(Estacion estacion) {
        this.estacion = estacion;
    }
}