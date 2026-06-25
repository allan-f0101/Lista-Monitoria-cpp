#include <iostream>
#include <string>

using namespace std;

class BST{
private:
    struct Node
    {
        int data;
        Node* leftChild;
        Node* rightChild;

        Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr){}
    };

    Node* root;

    Node* insertHealper(Node* current, int key){
        if(current == nullptr){
            return new Node(key);
        }

        if(key < current->data){
            current->leftChild = insertHealper(current->leftChild, key);
        }
        else{
            current->rightChild = insertHealper(current->rightChild, key);
        }
    }

    Node* findMin(Node* node) {
        while (node->leftChild != nullptr) {
            node = node->leftChild;
        }
        return node;
    }

    Node* removeHealper(Node* current, int key){
        if(current == nullptr){
            return;
        }

        if(key < current->data){
            current->leftChild = removeHealper(current->leftChild, key);
        }
        else if(key > current->data){
            current->rightChild = removeHealper(current->leftChild, key);
        }
        else{
            if(current->leftChild == nullptr){
                Node* temp = current->rightChild;
                delete current;
                return temp;
            }
            else if(current->rightChild == nullptr){
                Node* temp = current->leftChild;
                delete current;
                return temp;
            }
            else{
                Node* temp = findMin(current->rightChild);
                current->data = temp->data;
                current->rightChild = removeHealper(current->rightChild, temp->data);
            }
        }
    }

    Node* searchHealper(Node* current, int key){
        Node* current = root;

        while(current != nullptr && current->data != key){
            if(current -> data > key){
                current = current->leftChild;
            }
            else{
                current = current->rightChild;
            }
            return current;
        }

    }

    void preOrder(Node* current){
        if(current == nullptr){
            return;
        }
        cout << current->data << " ";
        preOrder(current->leftChild);
        preOrder(current->rightChild);
    }

    void inOrder(Node* current){
        if(current == nullptr){
            return;
        }
        inOrder(current->leftChild);
        cout << current->data << " ";
        inOrder(current->rightChild);
    }

    void postOrder(Node* current){
        if(current == nullptr){
            return;
        }
        postOrder(current->leftChild);
        postOrder(current->rightChild);
        cout << current->data << " ";
    }

public:
    BST() : root(nullptr) {}

    
    void print(){}
};

int main(){
    return 0;
}