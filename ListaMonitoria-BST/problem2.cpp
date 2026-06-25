#include <iostream>
#include <vector>

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
    vector<int> pais;

    Node* insertHealper(Node* current, int key){
        if(current == nullptr){
            return new Node(key);
        }

        if(key < current->data){
            if(current->leftChild == nullptr){
                pais.push_back(current->data);
            }
            current->leftChild = insertHealper(current->leftChild, key);
        }
        else{
            if(current->rightChild == nullptr){
                pais.push_back(current->data);
            }
            current->rightChild = insertHealper(current->rightChild, key);
        }
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert(int key){
        root = insertHealper(root, key);
    }

    void print(){
        for(int value : pais){
            cout << value << " ";
        }
    }
    
};

int main(){

    int num;
    cin >> num;

    BST tree;
    
    for(int i = 0; i < num; i++){
        int number;
        cin >> number;
        tree.insert(number);
    }

    tree.print();

    return 0;
}