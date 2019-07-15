public class Persona {
    
    private static int idCounter = 0; //Permite la asignacion automatica de ID

    private int id;
    private String nombre;

    public Persona(String nombre){

        this.id = idCounter;
        idCounter += 1;
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public int getID() {
        return id;
    }
}