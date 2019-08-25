public class Pasajero extends Persona{
    
    private boolean tarjetaCliente;
    
    public Pasajero(int id, String nombre, String apellido, int edad, int documento, boolean tarjetaCliente) {
        super(id, nombre, apellido, edad, documento);
        this.tarjetaCliente = tarjetaCliente;
    }

}