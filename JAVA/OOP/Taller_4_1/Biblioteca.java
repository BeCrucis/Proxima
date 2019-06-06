public class Biblioteca {
  
  public String nombre;
  public String direccion;
  public String telefono;
  public int empleados;
  public String fecha;

  public Biblioteca(String n, String d, String tel, int empleados, String f){
    this.nombre = n;
    this.direccion = d;
    this.telefono = tel;
    this.empleados = empleados;
    this.fecha = f;
  }


  public int getEmpleados() {
    return this.empleados;
  }

  public void modifyPlantas(){
    System.out.println("De alguna manera las plantas han sido modificadas");
  }
  
}

