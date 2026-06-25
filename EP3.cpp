#include <iostream>

using namespace std;

class BST{
private:
    struct Node
    {
        int data;
        Node* leftChild;
        Node* rightChild;

        Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
    };

    Node* root;

    int cont = 0;

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

    Node* getMin(Node* current){
        if(current->leftChild == nullptr){
            return current;
        }
        return getMin(current->leftChild);
    }

    Node* deleteMin(Node* current){
        if(current->leftChild == nullptr){
            return current->rightChild;
        }
        current->leftChild = deleteMin(current->leftChild);
        return current;
    }

    Node* removeHealper(Node* current, int key){
        if(current == nullptr){
            return nullptr;
        }

        if(key < current->data){
            current->leftChild = removeHealper(current->leftChild, key);
        }
        else if(key > current->data){
            current->rightChild = removeHealper(current->rightChild, key);
        }
        else{
            cont--;
            if(current->leftChild == nullptr){
                Node* temp = current->rightChild;
                delete current->leftChild;
                return temp;
            }

            else if(current->rightChild == nullptr){
                Node* temp = current->leftChild;
                delete current->rightChild;
                return temp;
            }
            
            else{
                if(current->leftChild == nullptr && current->rightChild == nullptr){
                    delete current;
                    return nullptr;
                }
                Node* temp = getMin(current->rightChild);
                current->data = temp->data;
                current->rightChild = deleteMin(current->rightChild);
            }
        }
        return current;
    }

    void postOrder(Node* current){
        if(current == nullptr){
            return;
        }
        postOrder(current->leftChild);
        postOrder(current->rightChild);
        cout << current->data << endl;
    }   

public:
    BST() : root(nullptr) {}

    void insert(int key){
        cont++;
        root = insertHealper(root, key);
    }

    void remove(int key){
        root = removeHealper(root, key);
        
    }

    void print(){
        cout << cont << endl;
        postOrder(root);
    }

};

int main(){
    
    int num;
    cin >> num;

    BST tree;

    for(int i = 0; i < num; i++){
        string input;
        cin >> input;

        if(input == "ins"){
            int number;
            cin >> number;
            tree.insert(number);
        }
        else if(input == "rem"){
            int number;
            cin >> number;
            tree.remove(number);
        }
    }
    tree.print();

    return 0;
}

