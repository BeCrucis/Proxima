class Persona{

  int id;
  int identificacion;
  String nombre;
  String telefono;
  String direccion;
  Boolean genero;


  public Persona(int id, int identificacion, String nombre, String telefono, String direccion, Boolean genero) {
    this.id = id;
    this.identificacion = identificacion;
    this.nombre = nombre;
    this.telefono = telefono;
    this.direccion = direccion;
    this.genero = genero;
  }


  public int getId() {
    return this.id;
  }

  public String getNombre() {
    return this.nombre;
  }

  public String getTelefono() {
    return this.telefono;
  }

  public String getDireccion() {
    return this.direccion;
  }

	public void setTelefono(String telefono) {
    this.telefono = telefono;
  }
  public void setDireccion(String direccion) {
    this.direccion = direccion;
  }
  
}
