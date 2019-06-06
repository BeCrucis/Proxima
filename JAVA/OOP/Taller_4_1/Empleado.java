class Empleado extends Persona {

  int idEmpleado;
  String area;
  String profesion;

  public Empleado(int id, int identificacion, String nombre, String telefono, String direccion, Boolean genero,
      int idEmpleado, String area, String profesion) {
    super(id, identificacion, nombre, telefono, direccion, genero);

    this.idEmpleado = idEmpleado;
    this.area = area;
    this.profesion = profesion;
  }

  public void setArea(String area){
    this.area = area;
  }

}