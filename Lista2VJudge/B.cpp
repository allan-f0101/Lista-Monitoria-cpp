#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

template<typename E>
class Dictionary{
private:
    struct Par{
        string chave;
        E value;
    };

    static const int tam = 100003;

    list<Par> lista[tam];

    int Hash(string key){
        int forCont = 1;
        int sum = 0;

        for(char i : key){
            sum += i * forCont;
            forCont++;
        }

        return sum % tam;
    }

    int cont;

public:
    Dictionary() : cont(0){
        for(int i = 0; i < tam; i++){
            lista[i].clear();
        }
    }
    ~Dictionary(){}

    void insert(string key, E value){
        int pos = Hash(key);

        Par novoPar;
        novoPar.chave = key;
        novoPar.value = value;

        lista[pos].push_back(novoPar);

        cont++;
    }

    E find(string key){
        int pos = Hash(key);

        for(auto const& par : lista[pos]){
            if(par.chave == key){
                return par.value;
            }
        }

        return E();
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            lista[i].clear();
        }
    }

    int size(){
        return cont;
    }

};

int main(){
    int cont = 0;

    Dictionary<string> dict;
    string input;

    while(getline(cin, input)){
        
        if(input.empty()){
            break;
        }

        stringstream ss(input);

        string chave, valor;
        ss >> valor;
        ss >> chave;

        dict.insert(chave, valor);

    }   

    while(getline(cin, input)){
        if(input.empty()) continue;
        
        string resposta = dict.find(input);
        if(resposta.empty()){
            cout << "eh\n";
        }
        else{
            cout << resposta << "\n";
        }
    }
    return 0;
}