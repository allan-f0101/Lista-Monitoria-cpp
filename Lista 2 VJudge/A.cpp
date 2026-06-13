#include <iostream>
#include <string>

using namespace std;

template<typename E>
class Dictionary{
private:
    enum Estado{VAZIO, OCUPADO, DELETADO};

    static const int tam = 101;
    string keys[tam];
    E values[tam];
    Estado estado[tam];
    int cont;

    int Hash(string key){
        int forCont = 1;
        int sum = 0;

        for(char i : key){
            sum += i * forCont;
            forCont++;
        }

        int function = 19 * sum;
        
        return function % 101;
    };

public:
    Dictionary() : cont(0) {
        for(int i = 0, i < tam; i++){
            estado[i] = VAZIO;
        }
    }
    ~Dictionary();

    void insert(string key, E value){
        int initialPos = Hash(key);
        
        for(int i = 0; i < 20; i++){
            if(initialPos == 0){
                
            }
        }
    }

    E remove(string key);
    E find(string key);
    void clear();
    int size();
    
};

int main(){
    return 0;
}