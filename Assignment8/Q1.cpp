#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* createBinaryTree(Node* n){
    int d;
    cout<<"Input Data: ";
    cin>>d;
    n = new Node(d);
    if(d==-1){
        return NULL;
    }
    cout<<"Input value for the left of "<<n->data<<endl;
    n->left = createBinaryTree(n->left);
    cout<<"Input value for the right of "<<n->data<<endl;
    n->right = createBinaryTree(n->right);
    return n;
}

void inOrderTraversal(Node* n){ // LNR
    if(n==NULL) return;
    inOrderTraversal(n->left);
    cout<<n->data<<" ";
    inOrderTraversal(n->right);
}

void preOrderTraversal(Node* n){ //NLR
    if(n==NULL) return;
    cout<<n->data<<" ";
    preOrderTraversal(n->left);
    preOrderTraversal(n->right);
}

void postOrderTraversal(Node* n){ //LRN
    if(n==NULL) return;
    postOrderTraversal(n->left);
    postOrderTraversal(n->right);
    cout<<n->data<<" ";
}
int main(){
    Node* root = NULL;
    root = createBinaryTree(root);
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    return 0;
}