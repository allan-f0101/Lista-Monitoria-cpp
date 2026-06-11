#include <iostream>

using namespace std;

template <typename E>
class BinaryTree{
private:
    struct Node{
        E data;
        Node* left;
        Node* right;
        Node(E d) : data(d), left(nullptr), right(nullptr) {}
    };  

    Node* root;

public:
    BinaryTree() : 
};

int main(){

    return 0;
}