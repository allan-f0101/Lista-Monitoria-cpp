#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename E>
class Dicionario{
private:
    struct Elemento{
        int key;
        E value;
    };

    static const int tam = 10;

    vector<Elemento> tabela[tam];
    int contador = 0;

    int Hash(int key){
        return key % 10; 
    }

public:
    Dicionario() : contador(0) {}
    ~Dicionario(){}

    void insert(int key, E value){
        int pos = Hash(key);

        for(const auto& elem : tabela[pos]){
            if(elem.key == key){
                return;
            }
        }

        contador++;
        tabela[pos].push_back({key, value});
    }

    void remove(int key){
        int pos = Hash(key);

        for(int i = 0; i < tabela[pos].size(); i++){
            if(tabela[pos][i].key == key){
                tabela[pos].erase(tabela[pos].begin() + i);
                contador--;
                return;
            }
        }
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            tabela[i].clear();
        }
    }

    int size(){
        return contador;
    }

    void print(int numeroCaso){
        cout << "caso " << numeroCaso << ":" << endl;
        cout << "alpha = " << contador << "/" << tam << endl;
        for(int i = 0; i < tam; i++){
            cout << i << ":";

            for(int j = 0; j < tabela[i].size(); j++){
                cout << "(" << tabela[i][j].key << "," << tabela[i][j].value << ")";

                if(j < tabela[i].size() - 1){
                    cout << ",";
                }
            }
            cout << endl;
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

        dict.print(cont + 1);
        cont++;
    }

    return 0;
}
