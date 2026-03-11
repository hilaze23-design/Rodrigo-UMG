#include <iostream>
#include <string> 
#include <cstdlib> // Ayuda a que system("pause") funcione sin problemas
using namespace std;

int main(){
    int n1=0, n2=0, n3=0, promedio=0;
    
    cout<<"Ingrese Nota 1:";
    cin>>n1;
    cout<<"Ingrese Nota 2:";
    cin>>n2;
    cout<<"Ingrese Nota 3:";
    cin>>n3;
    
    promedio = (n1+n2+n3) / 3;
    
    string mensaje="";
    // Operador ternario: (Condicion) ? Verdadero : Falso
    mensaje = promedio>=61 ? "Aprobado" : "Reprobado";
    cout<<"Su promedio es de "<<promedio<<" Por lo tanto "<<mensaje<<endl;
    
    // Evaluacion de rangos con el operador logico && (AND)
    if(promedio>=0 && promedio<61){
        cout<<"Mala nota"<<endl;
    }
    if(promedio>=61 && promedio<81){
        cout<<"Buena nota"<<endl;
    }
    if(promedio>=81){
        cout<<"Excelente nota"<<endl;
    }
    
    system("pause"); 
    return 0;
}