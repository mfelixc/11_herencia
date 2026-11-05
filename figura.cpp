#include <iostream>
using namespace std;

class Figura {
    private:
    string color;
    public:
    Figura(string c){ {
        color = c;
        }
    }
};

class Circulo : public Figura {
    private:
        int radio;
    public:
        Circulo(string c, int r) : Figura(c) {
            radio = r;
        }
        double calcularArea() {
            return 3.1416 * radio * radio;
        }
        double calcularPerimetro() {
            return 2 * 3.1416 * radio;
        }

};

class Rectangulo : public Figura {
    private:
        int base;
        int altura;
    public:
        Rectangulo(string c, int b, int a) : Figura(c) {
            base = b;
            altura = a;
        }
        double calcularArea() {
            return base * altura;
        }
};


int main () {

    return 0;
}