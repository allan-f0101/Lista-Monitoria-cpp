#ifndef FORMAS_H
#define FORMAS_H

#include <string>
#include <stdexcept>


class Forma{
    protected:
        std::string name;

    public:
        Forma(const std::string& n) : name(n){}
        virtual ~Forma() = default;

        virtual double area() const = 0;
        virtual double perimetro() const = 0;
        virtual std::string descricao() const = 0;

};

class Retangulo : public Forma{
    private:
        double largura;
        double altura;
    
    public:
        Retangulo(const std::string& name, double largura, double altura) : Forma(name), largura(largura), altura(altura){
            if(largura < 0 || altura < 0){
                throw std::invalid_argument("Você passou uma medida negativa");
            }
        };

        double area() const override;

        double perimetro() const override;

        bool quadrado() const;

        std::string descricao() const override;
};

class Circulo : public Forma{
    private:
        double raio;
    
    public:
        Circulo(const std::string& name, double raio) : Forma(name), raio(raio){
            if(raio < 0){
                throw std::invalid_argument("A medida do raio não pode ser negativa");
            }
        };

        double area() const override;

        double perimetro() const override;

        std::string descricao() const override;
};

#endif