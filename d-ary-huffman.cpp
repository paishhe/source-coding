#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;


struct Node{

    float data;
    string code;
    vector<Node*> children;

    Node(float value){
        data = value;
        code = "";
        
    }

};

struct Compare{
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void CreateTree(priority_queue<Node*, vector<Node*>, Compare> &pq, int D_ary){

    if (pq.size() == 1) return;

    float sum = 0;
    vector <Node*> children ;
    
    for (int i = 0; i<D_ary; i++){
        sum += pq.top() -> data;
        children.push_back(pq.top());
        pq.pop();

    }

    Node* newnode = new Node(sum);
    newnode -> children = children;
    pq.push(newnode);

    
    CreateTree(pq, D_ary);
    

}

void AssignCode(Node* root, int D_ary){

    if (root->children.size() == 0) return;

    for (int i = 0; i<root->children.size();i++){
        root->children [i]->code = root->code + to_string(i); // some bug
        AssignCode(root->children[i], D_ary);
    }

}

void PrintTree(Node* root) {

    if (root == nullptr) return;

    // If leaf node (no children)
    if (root->children.size() == 0) {
        cout << root->code << " "<< root->data << "\n";
        return;
    }

    // Recurse on actual children
    for (Node* child : root->children) {
        PrintTree(child);
    }
}
int main()
{   
    int D_ary;
    D_ary = 3;
    int Num_symbols = 7;
    priority_queue<Node*, vector<Node*>, Compare>  pq;
    Node* node1 = new Node (0.4);
    pq.push(node1);
    Node* node2 = new Node (0.1);
    pq.push(node2);
    Node* node3 = new Node (0.1);
    pq.push(node3);
    Node* node4 = new Node (0.1);
    pq.push(node4);
    Node* node5 = new Node (0.1);
    pq.push(node5);
    Node* node6 = new Node (0.1);   
    pq.push(node6);
    Node* node7 = new Node (0.1);
    pq.push(node7);

    float K = float((Num_symbols - 1))/(D_ary-1);
    // cout << Num_symbols << "\n";
    while (fabs(K - round(K)) > 1e-6){
        Num_symbols++;
        K = float((Num_symbols - 1))/(D_ary-1);
    }

    
    for (int i = 0; i < Num_symbols - 7; i++){
        Node* newNode = new Node(0.0f);
        pq.push(newNode);
    }

    CreateTree(pq, D_ary);
    AssignCode(pq.top(), D_ary);
    PrintTree(pq.top());

    return 0;
};