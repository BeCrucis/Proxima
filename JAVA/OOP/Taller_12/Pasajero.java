public class Pasajero extends Persona{
    
    private boolean tarjetaCliente;
    
    public Pasajero(int id, String nombre, String apellido, int edad, int documento, boolean tarjetaCliente) {
        super(id, nombre, apellido, edad, documento);
        this.tarjetaCliente = tarjetaCliente;
    }

    public Pasajero(Persona persona, boolean tarjetaCliente){
        this(persona.getId(), persona.getNombre(), persona.getApellido(), persona.getEdad(), persona.getDocumento(), tarjetaCliente);
    }

    public boolean isTarjetaCliente() {
        return tarjetaCliente;
    }
}