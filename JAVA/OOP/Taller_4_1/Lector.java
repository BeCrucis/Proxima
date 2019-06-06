class Lector extends Persona{

  int id;
  Boolean estado;
  int deuda;

  public Lector(int id, int identificacion, String nombre, String telefono, String direccion, Boolean genero) {
    super(id, identificacion, nombre, telefono, direccion, genero);
    this.id = id;
  }

  public String getNombre(){
    return this.nombre;
  }
  
  public Boolean getEstado(){
    return this.estado;
  }
  
  public int getDeuda(){
    return this.deuda;
  }

  public void setDeuda(int deuda){
    this.deuda = deuda;
  }
}