#ifndef EJERCICIO2_H
#define EJERCICIO2_H
#include <iostream>
#include <string>

using namespace std;

class Raton{
public:
    void setPeso(float peso);
    void setNombre(string nombre);
    string getNombre();
    float ConsultaPeso();
public:
    float distancia;
private:
    float peso;
    string nombre;
};

class Gato {
public:
    void setEnergia(float energia);
    void seNombre(string nombre);
    void ComerRaton(Raton &A); 
    void Correr(float seg);
    float ConsultaEnergia();
    float ConsultaVelocidad();
    string consultarNombre();
    bool meConvieneComerRatonA(Raton &A, float mts);
private:
    float energia;
    string nombre;
};

class Menu{
public:
    void menu();
};

#endif
