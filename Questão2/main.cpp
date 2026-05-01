#include <iostream>
#include "Formas.h"

using namespace std;

int main(){
    try{
        Retangulo a("Retangulo", 40, 60);
        string name1 = a.descricao();

        cout << "Dada a figura geométrica: " << name1 << endl;
        cout << "Sua área é: " << a.area() << endl;
        cout << "E o seu perímetro é: " << a.perimetro() << endl;


    }catch(exception& e){
        cerr << "Erro: " << e.what() << endl;
    }

    try{
        Circulo c("Circulo", 10);
        string name2 = c.descricao();

        cout << "Dada a figura geométrica: " << name2 << endl;
        cout << "Sua área é: " << c.area() << endl;
        cout << "E o seu perímetro é: " << c.perimetro() << endl;

    }catch(exception& e){
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}