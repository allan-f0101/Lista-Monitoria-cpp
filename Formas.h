#ifndef FORMAS_H
#define FORMAS_H

#include <string>
#include <cmath>


class Forma{
    private:
        std::string name;
    
    public:
        Forma(std::string n){
            this->name = n;
        }
        virtual ~Forma() = default;
        virtual double area() const = 0;
        virtual double perimetro() const = 0;
        virtual std::string descricao() const{
            return name;
        };

        std::string getNome() const{
            return name;
        }
};

class Circulo : public Forma{
    private:
        double pi = 3.14;
        double raio;
    
    public:
        Circulo(double r, std::string n) : Forma(n), raio(r){

        }

        double area() const override{
            return pi * raio * raio;
        }

        double perimetro() const override{
            return 2 * pi * raio;
        }
};

class Retangulo : public Forma{
    private:
        double base;
        double altura;

    public:
        Retangulo(double b, double a, std::string n) : Forma(n), base(b), altura(a){

        }   
        
        double area() const override{
            return base * altura;
        }

        double perimetro() const override{
            return 2 * base + 2 * altura;
        }
};

class Triangulo : public Forma{
    private:
        double base;
        double altura;
    
    public:
        Triangulo(double b, double a, std::string n) : Forma(n), base(b), altura(a){

        }

        double area() const override{
            return (base * altura) / 2;
        }

        double perimetro() const override{
            double hipotenusa = sqrt(base * base + altura * altura);
            return hipotenusa + base + altura;
        }

};

#endif