#ifndef POINT_H
#define POINT_H

#include <iostream>

class Vetor2D{
    private:
        double x, y;
    
    public:
        Vetor2D(double x, double y) : x(x), y(y){}

        Vetor2D operator+(const Vetor2D& outro) const{
            return Vetor2D(x + outro.x, y + outro.y);
        }
        
};

class Produto{
    public:
        std::string nome;
        int id;

        Produto(std::string n, int i) : nome(n), id(i){}

        bool operator==(const Produto& outro) const{
            return id == outro.id;
        }
};

#endif