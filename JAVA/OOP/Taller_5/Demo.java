class Demo {
  public static void main(String[] args) {
    
    CasaPublicacion bdv = new CasaPublicacion("Barco de vapor", "A", "123", "www.a.com");
    Autor yuri = new Autor("Yuri M", "Yurmel1701@gmail.com", "www.yuri.com");

    Libro magnumOpus = new Libro("Las aventuras de yuri", "000-1", 1000, 2019, 2, yuri, bdv);

    Capitulo cap1 = new Capitulo("A", 1, 10, 1);
    Capitulo cap2 = new Capitulo("B", 11, 20, 2);

    magnumOpus.addCapitulo(cap1);
    magnumOpus.addCapitulo(cap2);

   
    yuri.addLibro(magnumOpus);

    Libro alfa = new Libro("Las aventuras de yuri II: El regreso de Paez", "000-2", 1000, 2019, 2, yuri, bdv);
    
    alfa.addCapitulo(cap1);
    alfa.addCapitulo(cap2);
    alfa.addCapitulo(cap2);

    yuri.addLibro(alfa);

    yuri.ImprimirLibros();

  }
}