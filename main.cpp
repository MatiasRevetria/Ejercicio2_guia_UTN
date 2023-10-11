#include "header.h"
#include <string>
#include <list>
#include <stdlib.h>

void Raton::setNombre(string nombre){
    this->nombre = nombre;
}

void Raton::setPeso(float peso){
    this->peso = peso;
}

float Raton::ConsultaPeso()
{
    return peso;
}

string Raton::getNombre(){
    return nombre;
}

void Gato::ComerRaton(Raton &A)
{
    energia+=12+A.ConsultaPeso();
    A.~Raton();
}

void Gato::Correr(float seg)
{
    float velocidad=ConsultaVelocidad();
    float consumo=0.5*velocidad*seg;
    if(energia>=consumo){
        energia-=consumo;
        cout<<"El Gato corrio "<<velocidad*seg<<" mts"<<endl;
    }else{
        cout<<"El Gato no tiene la energia suficiente para correr tanto tiempo"<<endl;
    }
}

float Gato::ConsultaEnergia(){
    return energia;
}

float Gato::ConsultaVelocidad(){
    return 5.0 + energia/10.0;
}

bool Gato::meConvieneComerRatonA(Raton &A, float mts)
{
    float consumo=0.5*mts;
    float e=12+A.ConsultaPeso();
    if(e>consumo){
        return true;
    }
    return false;
}

void Gato::seNombre(string nombre){
    this->nombre = nombre;
}

 string Gato::consultarNombre(){
    return nombre;
}

void Gato::setEnergia(float energia){
    this->energia = energia;
}

void Menu::menu() {
    int entrada;
    int cont = 0;
    Gato toga;
    list<Raton> ratones;
    // Mensaje de inicio
    do{
    cout << "------------------------------------------" << endl;
    cout << "|            Seleccione una opcion       |" << endl;
    cout << "|            1. Iniciar Gato             |" << endl;
    cout << "|            2. Iniciar Ratones          |" << endl;
    cout << "|            3. Mostrar info             |" << endl;
    cout << "|            4. Cazar Ratones            |" << endl;
    cout << "------------------------------------------" << endl;

    cin >> entrada;
    if (entrada == 1) {
        if(cont == 1){
            cout<<"Ya esta iniciado el gato elija otra opcion..."<<endl;
        }else {
            cout <<"Introduzca el nombre del gato: "<<endl;
            string nombreGato;
            cin >> nombreGato;
            toga.seNombre(nombreGato);

            // Solicitar la energía
            float energia;
            cout <<"Introduzca la energia del gato: "<<endl;
            cin >> energia;
            toga.setEnergia(energia);
            cont++;
        }
        // Mostrar los datos ingresados
    } else if (entrada == 2) {
        cout << "Ingrese la cantidad de ratones..." << endl;
        int cant;
        cin >> cant;

        for (int i = 0; i < cant; i++) {
            Raton raton;
            // Solicitar el nombre del raton
            cout << "Introduzca el nombre del raton: "<< i+1 <<endl;
            string nombreRaton;
            cin >> nombreRaton;
            raton.setNombre(nombreRaton);
            // Solicitar Peso
            float peso;
            cout << "Introduzca el peso del raton: " << raton.getNombre() << endl;
            cin >> peso;
            raton.setPeso(peso);

            ratones.push_back(raton);
        };
    } else if (entrada == 3) {
        // Mostrar los datos ingresados
        cout << "------------------------------------------" << endl;
        cout << "Datos ingresados:" << endl;
        cout << "Nombre del gato: " << toga.consultarNombre() << endl;
        cout << "Energia del gato: " << toga.ConsultaEnergia() << endl;
        cout << "------------------------------------------" << endl;
        // Mostrar los datos ingresados
        for (Raton &raton: ratones) {
            cout << "------------------------------------------" << endl;
            cout << "Datos ingresados de " << raton.getNombre() << endl;
            cout << "Nombre del raton: " << raton.getNombre() << endl;
            cout << "Peso del raton: " << raton.ConsultaPeso() << endl;
        }
    }
}while(entrada != 4);

    for( Raton &raton: ratones){
        raton.distancia = rand() % 100;
    }
    cout << "------------------------------------------" << endl;
    for( Raton &raton: ratones){
        cout<<raton.getNombre()<<" "<<raton.distancia<< endl;
    }
    cout << "------------------------------------------" << endl;
    Raton ratonMasCerca;
    float distanciaMinima = 100;
    for(Raton &raton: ratones){
        if(raton.distancia < distanciaMinima){
            distanciaMinima = raton.distancia;
            ratonMasCerca = raton;
        }
    }
    cout << "------------------------------------------" << endl;
    cout << "El gato analiza comer a "<< ratonMasCerca.getNombre()<<" ya que es el mas cerca..."<<endl;
    // If conviene...
    if(toga.meConvieneComerRatonA(ratonMasCerca,distanciaMinima)){
        cout<<"me conviene comer raton "<<endl;
        toga.Correr(50);
        toga.ComerRaton(ratonMasCerca);
        cout << "Energia del gato despues de comer " << toga.ConsultaEnergia() << endl;
        cout << "------------------------------------------" << endl;
    }else{
        cout<<"no me conviene comer el raton"<<endl;
    }
};


int main (){

    Menu iniciar;
    iniciar.menu();

return 0;
}