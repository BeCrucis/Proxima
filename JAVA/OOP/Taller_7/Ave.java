public class Ave extends Animal{

    public Ave(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad, raza, nombre);
        
    }
    
    public void comer(){
        System.out.println("Las aves pueden ser carnivoras, herbivoras, omnivoras o insectivoras");
    }

    public void mover(){
        System.out.println("La mayoria de aves vuelan");
    }

    public void comunicarse(){
        System.out.println("Emiten sonidos haciendo circular el aire por la siringe");
    }

    public void completeInfo(){
        imprimirInfo();
        System.out.println("Cuerpo cubierto de plumas \nNacen de huevos \nSon vertebrados ");
    }

}