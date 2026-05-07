#include <iostream>
#include "Point.h"

int main(){;
    Vetor2D vetor1(2.0, 3.0);
    Vetor2D vetor2(4.0, 5.0); 
    Vetor2D vetor3 = vetor1 + vetor2;
    
    Produto num1("ponto", 5);
    Produto num2("ponto2", 10);
    Produto num3("mouse", 12);

    if(num1 == num2){
        std::cout << "num1 e num2 são iguais (mesmo)";
    }
    
    return 0;
}