#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo *nombre* de *usuario*
string getNombre(Usuario* usuario)
{
Usuario user=*usuario;
return user.nombre;


}

//Escribe todos los atributos de *usuario* en un archivo con con nombre *nombre_archivo*
void escribir(string nombre_archivo, Usuario* usuario)
{
    Usuario user=*usuario;

    ofstream out(nombre_archivo.c_str());
    out<<user.nombre<<endl;
    out<<user.edad<<endl;
    out.close();
}


//Lee los atributos de un *Usuario* desde un archivo con nombre *nombre_archivo* y luego lo devuelve
Usuario* leer(string nombre_archivo)
{
    Usuario* user2=new Usuario("",0);
    ifstream in (nombre_archivo.c_str());
    in>>user2->nombre;
    in>>user2->edad;
    in.close();
    return user2;
}

//Devuelve cuantas veces existe *numero* en *numeros*
int contar(vector<int> numeros, int numero)
{
int cont=0;
for(int i=0;i<numeros.size();i++)
{
    if(numero==numeros[i]){
        cont +=1;
    }
}
    return cont ;
}

//Devuelve *true* si existe al menos un valor repetido en *cadenas*
bool existeRepetida(list<string> cadenas)
{
cadenas.sort();
int cadena1=cadenas.size();
cadenas.unique();
int cadena2=cadenas.size();

if(cadena1==cadena2){

    return false;
}
    else{
        return true;
    }
    }




//Devuelve el contenido de *letras* invertido
vector<char> invertir(vector<char> letras)
{
    vector<char> respuesta;
for(char x=0;x>='a'&&x<='z';x)

    return letras;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//Lugar
//Lugar() Constructor vacio
//vendeComida() Funcion abstracta

//Restaurante
//Restaurante() Inicializa atributos
//vendeComida() Devuelve true

//Monumento
//Monumento() Inicializa atributos
//vendeComida() Devuelve false

void evaluar();
void evaluar2();
class Lugar
{
    public:
        string Nombre;
        double Latitud;
        double Longitud;
        Lugar(){
        }
       virtual bool vendeComida();

};

class Restaurante
{
    public:
    string horario;
    string nombre;
    double latitud;
    double longitud;
     Restaurante(string nombre,double latitud,double longitud,string horario)
    {
        this->horario = horario;
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre = nombre;
    }
    bool vendeComida()
    {
        return true;
    }
};
class Monumento
{
    public:
    string nombre;
    double latitud;
    double longitud;
    Monumento(string nombre,double latitud,double longitud)
    {
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre =nombre;
    }
    bool vendeComida()
    {
     return false;
    }

};





///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////


int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////


void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Restaurante**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Restaurante("Burger Queen",5.2,6.2,"24/7").nombre == "Burger Queen"
       && Restaurante("Burger Queen",6.1,6.2,"24/7").latitud == 6.1
       && Restaurante("Burger Queen",5.2,6.6,"24/7").longitud == 6.6
       && Restaurante("Burger Queen",5.2,6.2,"lunes a viernes").horario == "lunes a viernes"

       && Restaurante("Mc Ronald",5.2,6.2,"24/7").nombre == "Mc Ronald"
       && Restaurante("Mc Ronald",10.1,6.2,"24/7").latitud == 10.1
       && Restaurante("Mc Ronald",5.2,8.6,"24/7").longitud == 8.6
       && Restaurante("Mc Ronald",5.2,6.2,"siempre").horario == "siempre"
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(Restaurante("Burger Queen",5.2,6.2,"24/7").vendeComida()
       && Restaurante("Mc Ronalds",5.2,6.2,"24/7").vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Monumento**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Monumento("Burger Queen",5.2,6.2).nombre == "Burger Queen"
       && Monumento("Burger Queen",6.1,6.2).latitud == 6.1
       && Monumento("Burger Queen",5.2,6.6).longitud == 6.6

       && Monumento("Mc Ronald",5.2,6.2).nombre == "Mc Ronald"
       && Monumento("Mc Ronald",10.1,6.2).latitud == 10.1
       && Monumento("Mc Ronald",5.2,8.6).longitud == 8.6
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(!Monumento("Burger Queen",5.2,6.2).vendeComida()
       && !Monumento("Mc Ronalds",5.2,6.2).vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
