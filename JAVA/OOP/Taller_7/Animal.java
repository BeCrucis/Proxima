public class Animal {
    String tamanio;
    int ojos;
    int edad;
    String raza;

    public void comer(){
        System.out.println("El animal come comida");
    }

    public void mover(){
        System.out.println("Se desplaza de diversas formas");
    }

    public void comunicarse(){
        System.out.println("Emiten un sonido caracteristico");
    }

    public Animal(String tamanio, int ojos, int edad, String raza) {
        this.tamanio = tamanio;
        this.ojos = ojos;
        this.edad = edad;
        this.raza = raza;
    }
    
}