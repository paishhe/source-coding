#include <iostream>
#include <queue>

using namespace std;



struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


int main(){
    

    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(11);


    cout << root->data << "";

    return 0;
}