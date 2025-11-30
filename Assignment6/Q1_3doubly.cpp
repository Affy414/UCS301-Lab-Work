#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtBeginning(Node* &head, int d) {
    Node* newHead = new Node(d);
    if (head == NULL) {
        head = newHead;
        return;
    }
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
}

void insertAtEnd(Node* &head, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterPosition(Node* &head, int d, int pos) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBeforePosition(Node* &head, int d, int pos) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    if (pos == 1) {
        insertAtBeginning(head, d);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteAtEnd(Node* &head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

void deleteAtPos(Node* &head, int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void deleteByValue(Node* &head, int value) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == value) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

int searchForNode(Node* head, int val) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "The List is Empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int size(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int choice, val, pos;

    while (true) {
        cout << "\n----- Doubly Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Position\n";
        cout << "4. Insert Before Position\n";
        cout << "5. Delete at Head\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete at Position\n";
        cout << "8. Delete by Value\n";
        cout << "9. Search for Value\n";
        cout << "10. Display List\n";
        cout << "11. Size of List\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(head, val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(head, val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertAfterPosition(head, val, pos);
                break;

            case 4:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertBeforePosition(head, val, pos);
                break;

            case 5:
                deleteAtHead(head);
                break;

            case 6:
                deleteAtEnd(head);
                break;

            case 7:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPos(head, pos);
                break;

            case 8:
                cout << "Enter value: ";
                cin >> val;
                deleteByValue(head, val);
                break;

            case 9:
                cout << "Enter value: ";
                cin >> val;
                pos = searchForNode(head, val);
                if (pos == -1) cout << "Not found\n";
                else cout << "Found at position " << pos << endl;
                break;

            case 10:
                display(head);
                break;

            case 11:
                cout << "Size = " << size(head) << endl;
                break;

            case 12:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
