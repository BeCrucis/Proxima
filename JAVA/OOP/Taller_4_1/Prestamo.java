class Prestamo{

  String fechaPrestamo;
  String fechaEntrega;
  String fechaEntregaReal;


  public Prestamo(String fechaPrestamo, String fechaEntrega) {
    this.fechaPrestamo = fechaPrestamo;
    this.fechaEntrega = fechaEntrega;
  }

  public void cancelarPrestamo(String fecha){
    this.fechaEntregaReal = fecha;
    System.out.println("Prestamo cancelado el " + fecha);
  }

}