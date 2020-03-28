class Integral{

    int limiteA;
    int limiteB;

    public:

        Integral(int a, int b){
            limiteA = a;
            limiteB = b;
        }

    // No tengo manera de calcularla, pues no se que tipo de f(x) tengo
};

class IntegralPolinomica:public Integral{

    // Intregral con la funcion de la forma ax^2+bx+c

    int a;
    int b;
    int c; 
    // Coeficientes del polinomio dentro de la integral

    public:

        IntegralPolinomica(int a, int b, int coeficienteA, int coeficienteB, int coeficienteC):Integral(a,b){

            a = coeficienteA;
            b = coeficienteB;
            c = coeficienteC;

        }

        float calcularAreaBajoCurva(){
            // Ahora se que f(x) tengo y puedo calcular el area bajo la curva de esta integral polinomica
        }

};

class IntegralSeno:public Integral{

    // Integral con la funcion de la forma a*sin(bx)

    int a;
    int b;

    public:

        IntegralSeno(int a, int b, int coeficienteA, int coeficienteB):Integral(a,b){

            a = coeficienteA;
            b = coeficienteB;

        }

        float calcularAreaBajoCurva(){
            // Ahora se que f(x) tengo y puedo calcular el area bajo la curva de esta integral con un seno
        }
};