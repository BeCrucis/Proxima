public class Conductor extends Persona{
    
    private boolean pase;
    
    public Conductor(int id, String nombre, String apellido, int edad, int documento, boolean pase) {
        super(id, nombre, apellido, edad, documento);
        this.pase = pase;
    }

    public Conductor(Persona persona, boolean pase){
        this(persona.getId(), persona.getNombre(), persona.getApellido(), persona.getEdad(), persona.getDocumento(), pase);
    }

    public boolean hasPase(){
        return pase;
    }

}