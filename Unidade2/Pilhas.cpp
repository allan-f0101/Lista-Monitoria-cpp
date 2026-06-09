#include <iostream>

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
    virtual ~Stack(){}

    void clear();

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

    

    return 0;
}