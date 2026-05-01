#include "Formas.h"

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Implementação do Retângulo
double Retangulo::area() const{
    return largura * altura;
}

double Retangulo::perimetro() const{
    return (2 * altura) + (2 * largura);
}

bool Retangulo::quadrado() const{
    return largura == altura;
}

string Retangulo::descricao() const{
    return name;
}

//Implementação do Círculo
double Circulo::area() const{
    return raio * raio * 3.14;
}

double Circulo::perimetro() const{
    return 2 * raio * 3.14;
}

string Circulo::descricao() const{
    return name;
}