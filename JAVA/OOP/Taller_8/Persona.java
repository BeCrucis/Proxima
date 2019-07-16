public class Persona {
    
    private static int idCounter = 0; //Permite la asignacion automatica de ID

    private int id;
    private String nombre;
    private String documentoId;

    public Persona(String nombre, String documentoId){

        this.id = idCounter;
        idCounter += 1;
        this.nombre = nombre;
        this.documentoId = documentoId;
    }

    public String getNombre() {
        return nombre;
    }

    public int getID() {
        return id;
    }

    @Override
    public String toString() {
        String formattedInfo = String.format("Nombre: %s, ID: %d, Documento: %s", nombre, id, documentoId);
        return formattedInfo;
    }
}