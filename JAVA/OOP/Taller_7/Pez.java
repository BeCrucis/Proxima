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
        System.out.println("Emiten sonidos para comunicarse");
    }
    
}