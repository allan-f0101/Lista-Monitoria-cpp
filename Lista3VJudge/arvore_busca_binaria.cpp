#include <iostream>
#include <string>

using namespace std;

class BST{
private:
    struct Node{
        int data;
        Node *leftChild;
        Node *rightChild;

        Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
    };

    Node* root;

    Node* searchHealper(Node* current, int key){
        Node* current = root;

        while(current != nullptr && current->data != key){

            if(current->data > key){
                current = current->leftChild;
            }
            else{
                current = current->rightChild;
            }
        }

        return current;
    }

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
        return current;
    }

    Node* removeHealper(Node* current, int key){

    }

public:
    BST() : root(nullptr) {}

    bool search(int data){
        return (searchHealper(root, data) != nullptr);
    }

    void insert(int data){
        root = insertHealper(root, data);
    }

};

int main(){
    return 0;
}

