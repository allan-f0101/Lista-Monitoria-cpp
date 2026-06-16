#include <iostream>
#include <list>

using namespace std;

template<typename E>
class Dictionary{
private:
    struct Par{
        string chave;
        E valor;
    };

    static const int tam = 100003;

    list<Par> tabela[tam];

    int cont;

    int Hash(string key){
        int forCont = 1;
        int sum = 0;

        for(char i : key){
            sum += i * forCont;
            forCont++;
        }

        return sum % tam;
    };

public:
    Dictionary() : cont(0) {
        for(int i = 0; i < tam; i++){
            tabela[i].clear();
        }
    }

    ~Dictionary(){}

    void insert(string key, E value){
        int pos = Hash(key);

        Par novoPar;
        novoPar.chave = key;
        novoPar.valor = value;

        tabela[pos].push_back(novoPar);

        cont++;

    }
        
    E find(string key){
        int pos = Hash(key);

        for(auto const& par : tabela[pos]){
            if(par.chave == key){
                return par.valor;
            }
        }

        return E();
    }
    
    void clear(){
        for(int i = 0; i < tam; i++){
            
        }
    }

    int size(){
        return cont;
    }
};

int main(){
    return 0;
}