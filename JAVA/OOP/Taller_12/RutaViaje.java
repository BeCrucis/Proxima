public class RutaViaje {
    
    private Viaje viaje;
    private Ruta ruta;
    
    public RutaViaje(Viaje viaje, Ruta ruta) {
        this.viaje = viaje;
        this.ruta = ruta;
    }

    public Viaje getViaje() {
        return viaje;
    }

    public void setViaje(Viaje viaje) {
        this.viaje = viaje;
    }

    public Ruta getRuta() {
        return ruta;
    }

    public void setRuta(Ruta ruta) {
        this.ruta = ruta;
    }

}