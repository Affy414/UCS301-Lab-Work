#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* createBinaryTree() {
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node* n = new Node(d);
    n->left = createBinaryTree();
    n->right = createBinaryTree();
    return n;
}

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL)
        return new Node(d);
    if (d < root->data)
        root->left = insertIntoBST(root->left, d);
    else if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key) {
    Node* temp = root;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

Node* minBST(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* maxBST(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

int inOrderSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* succ = NULL;
    while (curr != NULL) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (succ == NULL)
        return -1;
    return succ->data;
}

int inOrderPredecessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    while (curr != NULL) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (pred == NULL)
        return -1;
    return pred->data;
}

Node* deleteFromBST(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteFromBST(root->left, key);
    else if (key > root->data)
        root->right = deleteFromBST(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        if (root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        if (root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* pred = maxBST(root->left);
        root->data = pred->data;
        root->left = deleteFromBST(root->left, pred->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return max(L, R) + 1;
}

int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    if (L == 0 || R == 0)
        return L + R + 1;
    return min(L, R) + 1;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = createBinaryTree();

    return 0;
}
