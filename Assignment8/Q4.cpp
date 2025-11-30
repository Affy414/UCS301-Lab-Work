#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* createTree(){
    int d;
    cin >> d;
    if(d == -1) return NULL;
    Node* n = new Node(d);
    n->left = createTree();
    n->right = createTree();
    return n;
}

bool isBSTUtil(Node* root, long minVal, long maxVal){
    if(!root) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

int main(){
    Node* root = createTree();
    if(isBSTUtil(root, -1000000000, 1000000000)) cout << "YES";
    else cout << "NO";
    return 0;
}
