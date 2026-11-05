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
    cout<<"Seleccione el tipo de vehiculo: "<<endl;
    cout<<"1. Automovil"<<endl;
    cout<<"2. Camion"<<endl;
    cin>>opcion;
    switch (opcion) {
        case 1:{
            cout<<"Ingrese los datos del automovil: "<<endl;
            cout<<"Numero de placa: ";
            cin>>placa;
            cout<<"Color: ";
            cin>>color;
            cout<<"Marca: ";
            cin>>marca;
            cout<<"Velocidad: ";
            cin>>velocidad;
            cout<<"Cantidad de puertas: ";
            cin>>cantidaddepuertas;
            cout<<"Cantidad de asientos: ";
            cin>>cantidaddeasientos;
            
            Automovil auto1(placa, color, marca, velocidad, cantidaddepuertas, cantidaddeasientos);
            auto1.mostrarAutomovil();
            cout <<"Desea cambiar la velocidad del automovil? (1. Si / 2. No): ";
            cin >> opcion;  
            switch (opcion)
            {
                case 1:
                    int nuevaVelocidad;
                    cout << "Ingrese la nueva velocidad: ";
                    cin >> nuevaVelocidad;
                    auto1.cambiarVelocidad(nuevaVelocidad);
                    cout << "La velocidad del automovil ha sido cambiada a " << nuevaVelocidad << " km/h." << endl;
                    break;
                case 2:
                    cout << "No se realizo ningun cambio en la velocidad del automovil." << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }
            cout <<"Desea subir o bajar pasajeros del automovil? (1. Subir / 2. Bajar / 3. Ninguno): ";
            cin >> opcion;
            switch (opcion)
            {
                case 1:
                    int pasajerosSubir;
                    cout << "Ingrese la cantidad de pasajeros a subir: ";
                    cin >> pasajerosSubir;
                    auto1.subirpasajeros(pasajerosSubir);
                    cout << "Se han subido " << pasajerosSubir << " pasajeros al automovil." << endl;
                    break;
                case 2:
                    int pasajerosBajar;
                    cout << "Ingrese la cantidad de pasajeros a bajar: ";
                    cin >> pasajerosBajar;
                    auto1.bajarpasajeros(pasajerosBajar);
                    cout << "Se han bajado " << pasajerosBajar << " pasajeros del automovil." << endl;
                    break;
                case 3:
                    cout << "No se realizo ningun cambio en la cantidad de pasajeros del automovil." << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }   
            break;}
        case 2:{
            cout<<"Ingrese los datos del camion: "<<endl;
            cout<<"Numero de placa: ";
            cin>>placaCamion;
            cout<<"Color: ";
            cin>>colorCamion;
            cout<<"Marca: ";
            cin>>marcaCamion;
            cout<<"Velocidad: ";
            cin>>velocidadCamion;
            cout<<"Carga: ";
            cin>>cargaCamion;

            Camion camion1(placaCamion, colorCamion, marcaCamion, velocidadCamion, cargaCamion);
            camion1.mostrarCamion();
            cout <<"Desea cambiar la carga del camion? (1. Si / 2. No): ";
            cin >> opcion; 
            switch (opcion)
            {
                case 1:
                    int nuevaCarga;
                    cout << "Ingrese la nueva carga: ";
                    cin >> nuevaCarga;
                    camion1.cambiarCarga(nuevaCarga);
                    cout << "La carga del camion ha sido cambiada a " << nuevaCarga << " kg." << endl;
                    break;
                case 2:
                    cout << "No se realizo ningun cambio en la carga del camion." << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }
            break;}
        default:
            cout<<"Opcion invalida."<<endl;
    }
    return 0;
}
