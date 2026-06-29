#include <iostream>
#include <string>

template<typename E>
class Dicionario{
    enum Estado{VAZIO, OCUPADO, DELETADO}

    struct Elemento{
        int key;
        E value;
        Estado estado;

        Elemento() : estado(VAZIO) {}
    }; 

    static const int tam = 20;

    Elemento tabela[tam];

    int cont;

    int Hash(int key){
        return key % 10;
    }

public:
    Dicionario() : cont(0){
        for(int i = 0; i < tam; i++){
            tabela[i].estado = VAZIO;
        }
    }

    ~Dicionario(){}

    void insert(int key, E value){
        int posParaInserir = -1;
        bool ja_existe = false;

        for(int i = 0; i < tam; i++){
            int pos = Hash(key);

            if(tabela[pos].estado == OCUPADO && tabela[pos].key == key){
                ja_existe = true;
                break;
            }
            if((tabela[pos].estado == VAZIO || tabela[pos].estado == DELETADO) && posParaInserir == -1){
                posParaInserir = pos;
            }
            if(tabela[pos].estado == VAZIO){
                break;
            }
        }
    }

    E remove(int key){
        for(int j = 0; j < tam; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;

            if(tabela[pos].estado == VAZIO){
                break;
            }

            if(tabela[pos].estado == OCUPADO && tabela[pos].key == key){
                tabela[pos].estado = DELETADO;
                cont--;
                return tabela[pos].value;
            }
        }
        return E();
    }

    E find(int key){
        for(int j = 0; j < tam; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;

            if(tabela[pos].estado == VAZIO){
                return E();
            }

            if(tabela[pos].estado == OCUPADO && tabela[pos].key == key){
                return tabela[pos].value;
            }
        }
        return E();
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            
        }
    }
};