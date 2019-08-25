import java.util.ArrayList;

public class MedioTransporte {
    
    public Conductor conductor;
    ArrayList<Persona> personas;
    ArrayList<Silla> sillas;

    public MedioTransporte(Conductor conductor, ArrayList<Persona> personas, ArrayList<Silla> sillas) {
        this.conductor = conductor;
        this.personas = personas;
        this.sillas = sillas;
    }

    public void addPasajero(Persona pasajero) {
        if (pasajero.getEdad()>0 && pasajero.getEdad()<99 ){
            personas.add(pasajero);
        }
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

}