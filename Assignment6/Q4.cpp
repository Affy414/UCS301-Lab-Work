#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &tail, char d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

bool isPalindrome(Node* head, Node* tail) {
    Node* left = head;
    Node* right = tail;

    while (left != NULL && right != NULL && left != right && left->prev != right) {

        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters:" << endl;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        insertAtEnd(head, tail, c);
    }

    if (isPalindrome(head, tail))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is NOT a palindrome." << endl;

    return 0;
}
