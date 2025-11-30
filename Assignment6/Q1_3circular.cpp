#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtBeginning(Node* &head, int d){
    Node* newHead = new Node(d);
    if (head == NULL){
        head = newHead;
        head->next = head;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newHead;
        newHead->next = head;
        head = newHead;
    }
}

void insertAtEnd(Node* &head, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        head->next = head;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAfterPosition(Node* &head, int d, int pos){
    Node* temp = head;
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    for(int i=1;i<pos;i++){
        if (temp->next == head){
            cout<<"Position out of range"<<endl;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforePosition(Node* &head, int d, int pos){
    Node* temp = head;
    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }

    if(pos == 1){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    for(int i=1;i<pos-1;i++){
        temp = temp->next;
        if(temp->next == head){
            cout<<"Position out of range"<<endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node* &head){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }
    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    delete head;
    head = temp->next;
}

void deleteAtEnd(Node* &head){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }
    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = head;
    delete del;
}

void deleteAtPos(Node* &head, int pos){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
        if(temp->next == head){
            cout<<"Position out of range\n";
            return;
        }
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void deleteByValue(Node* &head, int value){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    if(head->data == value){
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    while(temp->next != head && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->next == head){
        cout << "Value not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

int searchForNode(Node* head, int val){
    if(head == NULL) return -1;

    int pos = 1;
    Node* temp = head;

    while(true){
        if(temp->data == val)
            return pos;

        temp = temp->next;
        pos++;

        if(temp == head) break;
    }
    return -1;
}

void display(Node* head){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << head->data << endl;
}

int size(Node* head){
    if(head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}


int main(){
    Node* head = NULL;
    int choice, val, pos;

    while(true){
        cout << "\n----- Circular Linked List Menu -----\n";
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

        switch(choice){
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
                if(pos == -1) cout << "Not found\n";
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
