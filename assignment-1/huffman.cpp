#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;




struct Node{
    float data;
    Node* left;
    Node* right;
    string code;
    

    Node(float value){

        data = value;
        code = "";
        left = nullptr;
        right = nullptr;
    }
};



struct Compare{
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

priority_queue<Node*, vector<Node*>, Compare>  pq;

Node* CreateNode(Node* child1, Node* child2){

    float value = child1->data + child2->data;
    Node* newNode = new Node(value);

    newNode->left = child1;
    newNode->right = child2;

    return newNode;

};

void MakeTree(){

    if (pq.size() == 1) return;

    Node* top1;
    Node* top2;
    Node* NewNode;

    top1 = pq.top();
    pq.pop();
    top2 = pq.top();
    pq.pop();

    NewNode = CreateNode(top1, top2);
    pq.push(NewNode);

    MakeTree();
};

void printTree(Node* root, int space = 0) {
    if (root == nullptr)
        return;

    space += 5;

    printTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->data << " " << root->code << "\n";
    

    printTree(root->left, space);
}

void coding (Node* root){

    if (root->left == nullptr || root->right == nullptr) return;

    root->left->code = root->code + '0';
    root->right->code = root->code + '1';

    coding(root->left);
    coding(root->right);


}

void PrintSymbolCodes(Node* root){

    if (root == nullptr) return;

    PrintSymbolCodes(root->right);
    if (root->left == nullptr | root->right == nullptr) {
        cout << root->data << " " << root->code << "\n";
        return;
    }
    

    PrintSymbolCodes(root->left);
    if (root->left == nullptr | root->right == nullptr) cout << root->data << " " << root->code << "\n";


}



int main(){


    int NumInputs;
    float SymProb;
    cout << "how many symbols to be coded?" << "\n";
    cin >> NumInputs;
    cout << "enter symbol probabilities one after the other" << "\n";

    for (int i = 0; i<NumInputs; i++){
        cin >> SymProb;
        Node* node = new Node(SymProb);
        pq.push(node);
    }

    MakeTree();
    Node* root = pq.top();
    coding(root);
    PrintSymbolCodes(root);

    return 0;
}