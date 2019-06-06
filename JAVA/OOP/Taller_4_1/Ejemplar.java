class Ejemplar {

  int id;
  String editorial;
  String fechaEntrada;
  Prestamo prestamoActivo;

  public Ejemplar(int id, String editorial, String fechaEntrada){
    this.id = id;
    this.editorial = editorial;
    this.fechaEntrada = fechaEntrada;
  }

  public void prestarEjemplar(Lector lect){
    System.out.println("Ejemplar prestado a " + lect.getNombre());
    prestamoActivo = new Prestamo("22/01/19", "29/01/19");
  }

  public void devolverEjemplar(){
    System.out.println("Ejemplar devuelto!");
    prestamoActivo.cancelarPrestamo("25/01/19"); 
    prestamoActivo = null;
  }
}