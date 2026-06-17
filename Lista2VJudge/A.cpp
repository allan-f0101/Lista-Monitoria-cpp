#include <iostream>
#include <string>
#include <sstream>

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
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
    }
    ~Dictionary() {};
    //Insere algo no dicionário
    void insert(string key, E value){
        int posParaInserir = -1;
        bool ja_existe = false;

        for(int i = 0; i < 20; i++){
            int pos = (Hash(key) + i*i + 23*i) % 101;

            if(estado[pos] == OCUPADO && keys[pos] == key){
                ja_existe = true;
                break;
            }

            if((estado[pos] == VAZIO || estado[pos] == DELETADO) && posParaInserir == -1){
                posParaInserir = pos;
            }

            if(estado[pos] == VAZIO){
                break;
            }
        }

        if(posParaInserir != -1 && !ja_existe){
            keys[posParaInserir] = key;
            values[posParaInserir] = value;
            estado[posParaInserir] = OCUPADO;
            cont++;
        }
    }

    E remove(string key){
        for(int j = 0; j < 20; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;
            // if(estado[pos] == VAZIO){
            //     break;
            // }

            if(estado[pos] == OCUPADO && keys[pos] == key){
                estado[pos] = DELETADO;
                cont--;
                return values[pos];
            }
        }
        return E();
    }

    E find(string key){
        for(int j = 0; j < 20; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;

            if(estado[pos] == VAZIO){
                return E();
            }

            if(estado[pos] == OCUPADO && keys[pos] == key){
                return values[pos];
            }
        }
        return E();
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
        cont = 0;
    }
    
    int size(){
        return cont;
    }

    void print(){
        for(int i = 0; i < tam; i++){
            if(estado[i] == OCUPADO){
                cout << i << ":" << keys[i] << endl;
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