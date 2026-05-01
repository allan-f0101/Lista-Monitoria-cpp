#include <iostream>
#include "Formas.h"

using namespace std;

int main(){
    Retangulo a(200, 60, "Retangulo");
    Circulo c(10, "Circulo");
    Triangulo t(10, 20, "Triângulo");

    string name1 = a.descricao();
    string name2 = c.descricao();
    string name3 = t.descricao();
    //Retangulo
    cout << "Dada a figura geométrica: " << name1 << endl;
    cout << "Sua área é: " << a.area() << endl;
    cout << "E o seu perímetro é: " << a.perimetro() << endl;

    //Circulo
    cout << "Dada a figura geométrica: " << name2 << endl;
    cout << "Sua área é: " << c.area() << endl;
    cout << "E o seu perímetro é: " << c.perimetro() << endl;

    //Triangulo
    cout << "Dada a figura geométrica: " << name3 << endl;
    cout << "Sua área é: " << t.area() << endl;
    cout << "E o seu perímetro é: " << t.perimetro() << endl;

    return 0;
}