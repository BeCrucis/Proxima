#include <iostream>
#include <math.h>
using namespace std;
///////////////////////////////////////// CLASE PADRE
class funciones
{
    public:
    float c1,c2,c3;
    funciones(float _a,float _b,float _c)
    {
        c1=_a;
        c2=_b;
        c3=_c;
    }

    funciones()= default;
};

///////////////////////////////////////////////////////////////////////////////77 Clase Hija 1
class polinomio2:public funciones
{   
    protected:
        float x2=0,x3=0,x4=0,area=0;
    public:
        polinomio2(float _x0,float _x1)
        {
            x3=_x0;
            x4=_x1;
        }
        float integral();
        float derivada();
};
    

    float polinomio2::derivada()
    {
        x2=2*c1;
        return x2;
    }


    float polinomio2::integral()
    {

        area=(c1/3)*pow(x3,3)+(c2/2)*pow(x3,2)+c3*x3-((c1/3)*pow(x4,3)+(c2/2)*pow(x4,2)+c3*x4);
        if(x3<x4)
            area=-1*area;
        return area;
        
    }


/////////////////////////////////////////////////////////////////////////////////////7 Clase HIJA 2
class polinomio1:public funciones
{
    protected:
    float x5=0,x6=0,x7=0,area2=0;
    public:
    polinomio1(float _x0, float _x1)
    {
        x6=_x0;
        x7=_x1;
    }
    float integral();
    float derivada();
};


    float polinomio1::derivada()
    {
        x5=-c1/c2;
        return x5;
    }

    
    float polinomio1::integral()
    {
        area2=(c3/c2)*x6-(c1/(2*c2))*pow(x6,2)-((c3/c2)*x7-(c1/(2*c2))*pow(x7,2));
        if(x6<x7)
            area2=-1*area2;
        return area2;
    }



int main()
{
    float a=0,b=0,c=0,x0=0,x1=0;
    short res=0,opc=0;
    do{
        cout<<"1. polinomio de grado 1"<<"   Opcion 1"<<endl;
        cout<<"2. polinomio de grado 2"<<"   Opcion 2"<<endl;
        cout<<" "<<endl;
        cout<<"Digite una de las opciones presentadas para continuar"<<endl;
        cin>>res;
    }while(res!=1 && res!=2);
   
   if(fmod(res,2)==0)
   {
       
        cout<<"La ecuacion de la funcion es: "<<" ax^2 + bx + c"<<endl;
        cout<<"Digite los coeficientes de la ecuacion"<<endl;
        cin>>a>>b>>c;
        funciones nodo = funciones(a,b,c);
        cout<<"Digite el intervalo donde quiera calcular la integral "<<endl;
        cin>>x0>>x1;
        polinomio2 nodo2 =polinomio2 (x0,x1);
        cout<<"Menu2:"<<endl;
        do{
            cout<<"Seleccione alguna de las siguientes opciones:"<<endl;
            cout<<"Opcion 1. Derivar"<<endl;
            cout<<"Opcion 2. integrar"<<endl;
            cin>>opc;
        }while(opc!=1 && opc!=2);
        
        if(opc==1)
        {
            cout<<"La derivada es: "<<nodo2.derivada()<<"x + "<<b;
        }
        else
        {
            cout<<"El integral desde "<<x0<<" a "<<x1<<" es: "<<nodo2.integral()<<endl;
        }
   }
   else
   {
        cout<<"La ecuaciÃ³n de la funciÃ³n es: "<<"ax + by = c"<<endl;
        cout<<"Digite los coeficientes de la ecuaciÃ³n"<<endl;
        cin>>a>>b>>c;
        funciones nodo = funciones(a,b,c);
        cout<<"Digite el intervalo donde quiera calcular la integral "<<endl;
        cin>>x0>>x1;
        polinomio1 nodo3 = polinomio1(x0,x1);
        cout<<"MenÃº:"<<endl;
        do{
            cout<<"Seleccione alguna de las siguientes opciones:"<<endl;
            cout<<"Opcion 1. Derivar"<<endl;
            cout<<"Opcion 2. integrar"<<endl;
            cin>>opc;
        }while(opc==1 || opc==2);
        
        if(opc==1)
        {
            cout<<"La derivada es: "<<nodo3.derivada();
        }
        else
        {
            cout<<"El integral desde "<<x0<<" a "<<x1<<" es: "<<nodo3.integral()<<endl;
        }
   }


}