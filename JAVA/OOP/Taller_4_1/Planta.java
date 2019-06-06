class Planta{

  String nombre;
  int capacidad;
  Boolean estado;


  public Planta(String nombre, int capacidad, Boolean estado) {
    this.nombre = nombre;
    this.capacidad = capacidad;
    this.estado = estado;
  }


  public String getNombre() {
    return this.nombre;
  }

  public int getCapacidad() {
    return this.capacidad;
  }

  public void setCapacidad(int capacidad) {
    this.capacidad = capacidad;
  }

  public Boolean isOpen(){
    return this.estado;
  }

  public void setEstado(Boolean estado) {
    this.estado = estado;
  }
}
