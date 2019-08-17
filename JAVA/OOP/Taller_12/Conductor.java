public class Conductor extends Persona{
    
    public Conductor(int id, String nombre, String apellido, int edad, int documento, boolean pase) {
        super(id, nombre, apellido, edad, documento);
        this.pase = pase;
    }

    private boolean pase;

}