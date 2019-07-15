public class Reptil extends Animal {

    public Reptil(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad,raza, nombre);
    }

    public void comer(){
        System.out.println("Pueden ser carnivoros u omnivoros");
    }

    public void mover(){
        System.out.println("Se desplazan andando o nadando");
    }

    public void comunicarse(){
        System.out.println("Grunen");
    }

}