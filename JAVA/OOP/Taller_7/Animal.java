public class Animal {
    String tamanio;
    int ojos;
    int edad;
    String raza;
    String nombre;

    public void comer(){
        System.out.println("El animal come comida");
    }

    public void mover(){
        System.out.println("Se desplaza de diversas formas");
    }

    public void comunicarse(){
        System.out.println("Emiten un sonido caracteristico");
    }

    public Animal(String tamanio, int ojos, int edad, String raza, String nombre) {
        this.tamanio = tamanio;
        this.ojos = ojos;
        this.edad = edad;
        this.raza = raza;
        this.nombre = nombre;
    }

    @Override
    public String toString() {
        String animalInfo = String.format("Nombre: %s, Tipo: %s, Raza: %s", nombre, getClass(), raza);
        return animalInfo;
    }

}