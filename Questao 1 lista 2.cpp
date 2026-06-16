#include <iostream>
#include <string>

using namespace std;

template<typename E>
class Dicionario{
private:
    enum Estado{VAZIO, DELETADO, OCUPADO};
    
    static const int tam = 10;

    E lista[tam];
    Estado estado[tam];
    E keys[tam];

    int Hash(int key){
        return key % 10; 
    }

    int contador = 0;

public:
    Dicionario() : contador(0) {
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
    }
    ~Dicionario(){}

    void insert(int key, E value){
        int pos = Hash(key);

        if(estado[pos] == OCUPADO){
            return;
        }

        if(estado[pos] == VAZIO && keys[pos] == key){
            estado[pos] = OCUPADO;
            keys[pos] = key;
            lista[pos] = value;
            return;
        }

        contador++;
    }

    void remove(int key){
        int pos = Hash(key);

        if(estado[pos] == VAZIO){
            return;
        }

        if(estado[pos] == OCUPADO && keys[pos] == key){
            estado[pos] = VAZIO;
            keys[pos] = 0;
        }

        contador--;
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
    }

    int size(){
        return contador;
    }

    void print(){
        cout << "alpha = " << contador << "/" << tam << endl;
        for(int i = 0; i < tam; i++){
            cout << i << ": " << lista[i] << endl;
        }
    }
};


int main(){
    int cont = 0;
    int num;
    cin >> num;

    string input;

    while(cont < num){
        int contFor;
        cin >> contFor;

        Dicionario<string> dict;

        for(int i = 0; i < contFor; i++){
            string operation;
            int number;
            string name;

            cin >> operation >> number;

            if(operation == "add"){
                cin >> name;
                dict.insert(number, name);
            }
            if(operation == "del"){
                dict.remove(number);
            }
        }

        dict.print();
        cont++;
    }

    return 0;
}

// 1
// 5
// add 123 gustavo
// add 456 lucas
// add 789 pedro
// del 123
// add 6 gustavo


// caso 1:
// alpha = 3/10
// 0:
// 1:
// 2:
// 3:
// 4:
// 5:
// 6:(456,lucas),(6,gustavo)
// 7:
// 8:
// 9:(789,pedro)