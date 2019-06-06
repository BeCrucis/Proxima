import java.util.ArrayList;

class Libro {

  String ISBN;
  String titulo;
  String fechaPublicacion;
  String idioma;
  ArrayList<Ejemplar> ejemplares;

  public Libro(String ISBN, String titulo, String fechaPublicacion, String idioma) {
    this.ISBN = ISBN;
    this.titulo = titulo;
    this.fechaPublicacion = fechaPublicacion;
    this.idioma = idioma;
  }

  public String getTitulo(){
    return this.titulo;
  }

  public void addEjemplar(String fecha){
    ejemplares.add(new Ejemplar(1, "Norma", fecha));
    System.out.println("Ejemplar añadido!");
  }
  
}