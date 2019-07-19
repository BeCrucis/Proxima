public class Reptil extends Animal {

    public Reptil(String tamanio, int ojos, int edad, String raza, String nombre) {
        super(tamanio, ojos, edad,raza, nombre);
    }

    public void comer(){
        System.out.println("Pueden ser carnivoros u omnivoros");
    }

    public void mover(){
        System.out.println("Para desplazarse unos se arrastran, otros nadan, y otros andan y nadan");
    }

    public void comunicarse(){
        System.out.println("Producen sonido expulsando aire de los pulmones a traves de la glotis");
    }

    public void completeInfo(){
        imprimirInfo();
        System.out.println("Cuerpo cuierto de escamas \nAlgunos poseen caparazon con placas \nNacen de huevos \nSon vertebrados ");
    }

}