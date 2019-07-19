public class Pez extends Animal{
    public Pez(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad, raza, nombre);
    }

    boolean escamas;

    public void comer(){
        System.out.println("Se alimentan de otros peces o insectos marinos");
    }

    public void mover(){
        System.out.println("Se desplazan nadando");
    }

    public void comunicarse(){
        System.out.println("Emiten sonidos con la vejiga natatoria");
    }

    public void completeInfo(){
        imprimirInfo();
        System.out.println("Cuerpo cubierto de escamas \nNacen de huevos \nTienen aletas para nadar \nViven y respiran dentro del agua \nSon vertebrados ");
    }
    
}