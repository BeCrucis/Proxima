import java.util.ArrayList;

public class MedioTransporte {
    
    public Conductor conductor;
    ArrayList<Persona> personas;
    ArrayList<Silla> sillas;

    public void addPasajero(Persona pasajero) {
        personas.add(pasajero);
    }

}