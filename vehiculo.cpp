#include<iostream>
#include<string>
using namespace std;



class Vehiculo{
    private:
        string numeroPlaca;
        string color;
        string marca;
        int velocimetro;
    public:
    Vehiculo(string, string, string, int);
    void mostrarDatos();
    void cambiarVelocidad(int);
};


Vehiculo :: Vehiculo(string np, string c, string m, int v){
    numeroPlaca = np;
    color = c;
    marca = m;
    velocimetro = v;
}


void Vehiculo :: mostrarDatos(){
    cout<<numeroPlaca<<" es un vehiculo de color "<<color<<" y marca "<<marca;
    cout<<" que tiene una velocidad de "<<velocimetro<<" km/h ";
}

void Vehiculo :: cambiarVelocidad(int nuevaVelocidad){
    velocimetro = nuevaVelocidad;
}

class Automovil : public Vehiculo{
    private:
        int cantidaddepuertas;
        int cantidaddeasientos;
    public:
        Automovil(string, string, string, int, int, int);
        void mostrarAutomovil();
        void subirpasajeros(int);
        void bajarpasajeros(int);
};


Automovil :: Automovil(string np, string c, string m, int v, int cp, int ca) : Vehiculo(np, c, m, v){
    cantidaddepuertas = cp;
    cantidaddeasientos = ca;
}

void Automovil :: mostrarAutomovil(){
    mostrarDatos();
    cout<<"es un automovil con "<<cantidaddepuertas<<" puertas y "<<cantidaddeasientos<<" asientos."<<endl;
}

void Automovil :: subirpasajeros(int pasajeros){
    cantidaddeasientos += pasajeros;
}

void Automovil :: bajarpasajeros(int pasajeros){
    cantidaddeasientos -= pasajeros;
}


class Camion : public Vehiculo{
    private:
        int carga;
    public:
        Camion(string, string, string, int, int);
        void mostrarCamion();
        void cambiarCarga(int);
};


Camion :: Camion(string np, string c, string m, int v, int cl) : Vehiculo(np, c, m, v){
    carga = cl;
}

void Camion :: mostrarCamion(){
    mostrarDatos();
    cout<<"es un camion con una carga de "<<carga<<" kg."<<endl;
}

void Camion :: cambiarCarga(int nuevaCarga){
    carga = nuevaCarga;
}



int main(){
    string placa,color, marca; 
    int velocidad, cantidaddepuertas, cantidaddeasientos;
    string placaCamion, colorCamion, marcaCamion;
    int velocidadCamion, cargaCamion,opcion;
    Automovil v1("ABC123", "Rojo", "Toyota", 120, 4, 5);
    v1.mostrarAutomovil();
    cout << "ingrese la nueva placa: ";
    cin >> placa;
    cout << "ingrese el nuevo color: ";
    cin >> color;   
    cout << "ingrese la nueva marca: ";
    cin >> marca;   
    cout << "ingrese la nueva velocidad: ";
    cin >> velocidad;
    v1.cambiarVelocidad(velocidad);
    
    v1.mostrarAutomovil();
    return 0;
}
