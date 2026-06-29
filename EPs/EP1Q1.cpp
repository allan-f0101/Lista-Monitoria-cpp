#include <iostream>
#include <string>

using namespace std;

template<typename E>
class Queue{
private:
    struct Node{
        E data;
        Node* next;
        Node(E d) : data(d), next(nullptr){}
    };      

    int cont;
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr), cont(0) {}
    ~Queue(){
        clear();
    }

    void enqueue(E value){
        Node* novono = new Node(value);
        if(front == nullptr){
            front = novono;
            rear = novono;
        }
        else{
            rear->next = novono;
            rear = novono;
        }
        cont++;
    }

    void enqueue(E value, int pos){
        
        if(pos == 0){
            enqueue(value);
            return;
        }
        
        Node* novono = new Node(value);

        if(front == nullptr){
            front = rear = novono;
            cont++;
            return;
        }

        if(pos == 1){
            novono->next = front;
            front = novono;
            cont++;
        }
        else{
            Node* atual = front;

            for(int i = 1; i < pos - 1 && atual->next != nullptr; i++){
                atual = atual->next;
            }

            if(atual->next == nullptr){
                atual->next = novono;
                rear = novono;
            }
            else{
                novono->next = atual->next;
                atual->next = novono;
            }
            cont++;
        }
    }

    void dequeue(){
        if(front == nullptr) return;
        Node* temp = front;
        front = front->next;

        delete temp;
        cont--;
        if(front == nullptr){
            rear = nullptr;
        }
    }

    void clear(){
        while(cont > 0){
            dequeue();
        }
    }

    void print() const{
        if(front == nullptr){
            cout << "---\n";
            return;
        }

        Node* atual = front;

        while(atual != nullptr){
            cout << atual->data;

            if(atual->next != nullptr){
                cout << ", ";
            }

            atual = atual->next;
        }
        cout << "\n";
    }

    int length() const{
        return cont;
    }
};

int main(){

    int num;
    cin >> num;
    
    int num2;

    Queue<string> queue;

    for(int i = 0; i < num; i++){
        cin >> num2;
        for(int j = 0; j < num2; j++){
            string input;
            cin >> input;

            if(input == "add"){
                string proximo_dado;
                cin >> proximo_dado;

                int prioridade;
                string nome_paciente;

                if(proximo_dado[0] >= '0' && proximo_dado[0] <= '9'){
                    prioridade = stoi(proximo_dado);
                    cin >> nome_paciente;

                    queue.enqueue(nome_paciente, prioridade);
                }
                else{
                    nome_paciente = proximo_dado;
                    prioridade = 0;

                    queue.enqueue(nome_paciente, prioridade);
                }
            }
            else if(input == "status"){
                queue.print();
            }
            else if(input == "next"){
                queue.dequeue();
            }
        }
    }
    return 0;
}