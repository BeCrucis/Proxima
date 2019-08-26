import java.util.ArrayList;

public class MedioTransporte {
    
    public Conductor conductor;
    ArrayList<Pasajero> personas;
    ArrayList<Silla> sillas;

    public MedioTransporte(Conductor conductor, ArrayList<Pasajero> personas, ArrayList<Silla> sillas) {
        this.conductor = conductor;
        this.personas = personas;
        this.sillas = sillas;
    }

    public void addPasajero(Pasajero pasajero) {
        
        personas.add(pasajero);
        
    }

    public void addConductor(Conductor conductor) {
        this.conductor = conductor;
    }

    public Conductor getConductor() {
        return conductor;
    }

    public void setConductor(Conductor conductor) {
        this.conductor = conductor;
    }

    public void enviarViaje(Viaje viaje) throws NoConductorException, NoPassengersException {
        
        if (conductor == null) {
            throw new NoConductorException();
        } else if (personas == null || personas.isEmpty()){
            throw new NoPassengersException();
        } else {
            System.out.println("Viaje enviado!");
        }
    }
}