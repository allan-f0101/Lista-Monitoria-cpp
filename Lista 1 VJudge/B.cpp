#include <iostream>

using namespace std;

template<typename E> class Stack{
private:
    struct Node{
        E data;
        Node* next;
        Node(E d) : data(d), next(nullptr) {}
    };

    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}
    virtual ~Stack(){
        clear();
    }

    void clear(){
        while(size > 0){
            pop();
        }
    }

    void push(const E& it){
        Node* novoNo = new Node(it);
        novoNo->next = top;
        top = novoNo;
        size++;
    }

    E pop(){
        Node* temp = top;
        top = top->next;
        E valor = temp->data;
        delete temp;
        size--;
        return valor;
    }

    const E& topValue() const{
        return top->data;
    }

    int length() const{
        return size;
    }
};

int main(){
    int input;

    while(cin >> input && input != 0){
        while(true){

            int primeiro;
            cin >> primeiro;
            
            if(primeiro == 0) break;

            int desejada[input];
            desejada[0] = primeiro;
            for(int i = 1; i < input; i++){
                cin >> desejada[i];
            }

            Stack<int> estacao;
            int proxVagaoEntrando = 1;
            int indiceDesejado = 0;
            bool possivel = true;

            while(indiceDesejado < input && possivel){
                if(estacao.length() > 0 && estacao.topValue() == desejada[indiceDesejado]){
                    estacao.pop();
                    indiceDesejado++;
                }
                else if(proxVagaoEntrando <= input){
                    estacao.push(proxVagaoEntrando);
                    proxVagaoEntrando++;
                }
                else{
                    possivel = false;
                }
            }
            cout << (possivel ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}