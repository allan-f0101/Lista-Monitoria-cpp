#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename E>
class Dictionary{
private:
    enum Estado{VAZIO, OCUPADO, DELETADO};

    struct Elemento{
        string key;
        E value;
        Estado estado;

        Elemento() : estado(VAZIO) {}
    };

    static const int tam = 101;
    
    Elemento tabela[tam];
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
    }

public:
    Dictionary() : cont(0) {
        for(int i = 0; i < tam; i++){
            tabela[i].estado = VAZIO;
        }
    }
    ~Dictionary() {};
    //Insere algo no dicionário
    void insert(string key, E value){
        int posParaInserir = -1;
        bool ja_existe = false;

        for(int i = 0; i < 20; i++){
            int pos = (Hash(key) + i*i + 23*i) % 101;

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

        if(posParaInserir != -1 && !ja_existe){
            tabela[posParaInserir].key = key;
            tabela[posParaInserir].value = value;
            tabela[posParaInserir].estado = OCUPADO;
            cont++;
        }
    }

    E remove(string key){
        for(int j = 0; j < 20; j++){
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

    E find(string key){
        for(int j = 0; j < 20; j++){
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
            tabela[i].estado = VAZIO;
        }
        cont = 0;
    }
    
    int size(){
        return cont;
    }

    void print(){
        for(int i = 0; i < tam; i++){
            if(tabela[i].estado == OCUPADO){
                cout << i << ":" << tabela[i].key << endl;
            }
        }
    }
    
};

int main(){
    int cont = 0;
    int t;
    cin >> t;

    while(cont < t){
        int n;
        cin >> n;
        cin.ignore();

        Dictionary<int> dict;

        for(int i = 0; i < n; i++){
            string line;
            getline(cin, line);

            stringstream ss(line);
            string operation;
            string chave;

            getline(ss, operation, ':');
            getline(ss, chave);

            if(operation == "ADD"){
                dict.insert(chave, 1);
            }

            if(operation == "DEL"){
                dict.remove(chave);
            }
        }
        cont++;
        cout << dict.size() << endl;
        dict.print();
    }

    return 0;
}