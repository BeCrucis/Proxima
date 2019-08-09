public abstract class Persona implements Heroe {

    private String nombre;
    private String apellido;
    private int id;

    public Persona(String nombre, String apellido, int id) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.id = id;
    }

    @Override
    public void poderes() {
        System.out.println("El poder de no poder hacer nada!");
    }

    @Override
    public void villanos(String nombreVillano) {
        System.out.println(nombreVillano + " Es villano de " + getNombre());
    }

    public boolean caminar(int kmsCaminados) {
        if (kmsCaminados < 1 || kmsCaminados > 10) {
            System.out.println("No puedo caminar esa distancia");
            return false;
        }

        for (int i = 1 ; i <= kmsCaminados ; i += 1){
            System.out.println("He caminado " + i + "Kilometros!");

            if (i % 2 == 0) {
                System.out.println("Debo descansar");
            }
            
        }

        return true;
    }

    public boolean correr(int kmsCorridos) {
        if (kmsCorridos < 1 || kmsCorridos > 5) {
            System.out.println("No puedo correr esa distancia");
            return false;
        }

        for (int i = 1 ; i <= kmsCorridos ; i += 1){
            System.out.println("He corrido " + i + "Kilometros!");
            System.out.println("Debo descansar");
        }

        return true;
    }

    public void hablar() {
        System.out.println("Ed dice Bla bla bla!");
    }
    

    public String getNombre() {
        return this.nombre;
    }

    public String getApellido() {
        return this.apellido;
    }

    public int getId() {
        return this.id;
    }

}