#include <iostream>
#include <string>

using namespace std;

// Como a questão fala que os barcos são atendidos na ordem de chegada, usaremos FILA
// First In First Out

template <typename E>
class Queue{
private:
    struct Node{
        E data;
        Node* next;
        Node(E d) : data(d), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    virtual ~Queue(){
        clear();
    }
    
    void clear(){
        while(size > 0){
            dequeue();
        }
    }

    void enqueue(const E& valor){
        Node* novoNo = new Node(valor);

        if(front == nullptr){
            front = novoNo;
            rear = novoNo;
        }
        else{
            rear->next = novoNo;    
            rear = novoNo;
        }
        size++;
    }

    E dequeue(){
        E valor = front->data;
        Node* temp = front;
        front = front->next;

        delete temp;
        size--;

        if(front == nullptr){
            rear = nullptr;
        }
        return valor;
    }

    const E& frontValue() const{
        return front->data;
    }

    int length() const{
        return size;
    }
};

int main(){
    int cont = 0;
    int tamanho;
    string lado;
    int a;
    int b;
    int contaux = 0;

    int numInicio = 0;
    cin >> numInicio;
    
    while(cont < numInicio){
        Queue<int> filaEsquerda;
        Queue<int> filaDireita;

        string estado_atual = "left";

        cin >> a >> b;
        a = a * 100;        

        for(int i = 0; i < b; i++){
            cin >> tamanho >> lado;

            if(lado == "left"){
                //Chama a Queue do lado esquerdo
                filaEsquerda.enqueue(tamanho);
            }
            else{
                //Chama a Queue do lado direito
                filaDireita.enqueue(tamanho);
            }
        }

        int travessias = 0;

        while(filaEsquerda.length() > 0 || filaDireita.length() > 0){
            int espacoDisponivel = a;

            if(estado_atual == "left"){
                while(filaEsquerda.length() > 0 && filaEsquerda.frontValue() <= espacoDisponivel){
                    espacoDisponivel -= filaEsquerda.dequeue();
                }
            }
            else{
                while(filaDireita.length() > 0 && filaDireita.frontValue() <= espacoDisponivel){
                    espacoDisponivel -= filaDireita.dequeue();
                }
            }

            travessias++;

            if(estado_atual == "left") estado_atual = "right";
            else estado_atual = "left";
        }
        cout << travessias << endl;
        cont++;
    }
    return 0;
}