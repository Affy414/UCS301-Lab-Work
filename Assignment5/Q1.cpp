#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};
void insertAtHead(Node* &head,int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}
void insertAtTail(Node* &head, int value){
    Node* new_node = new Node(value);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = new_node;
}
void insertAtPos(Node* &head, int value, int pos){
    Node* new_node = new Node(value);
    Node* temp = head;
    int i = 0;
    while(i!=pos-1) {
        temp = temp->next;
        i++;
    } // 0->1->2->3
    new_node->next = temp->next;
    temp->next = new_node;
}
void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteAtPos(Node* &head, int pos){
    Node* temp1 = head;
    int i=0;
    while(i!=pos-1){
        temp1 = temp1->next;
        i++;
    }
    Node* temp2 = temp1->next;
    Node* temp3 = temp2->next;
    temp1->next = temp3;
    delete temp2;
}
void deleteAtEnd(Node* &head){
    Node* temp1 = head;
    while(temp1->next->next != NULL){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = NULL;
    delete temp2;
    
}
int searchAndDisplay(Node* &head, int pos){
    Node* temp = head;
    int n = 0;
    while(n!=pos-1 && temp!=NULL){
        temp = temp->next;
        n++;
    }
    if (temp == NULL) return -1;
    return temp->val;
}
void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head = NULL;
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtHead(head,2);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtPos(head,9,2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtPos(head,2);
    display(head);
    deleteAtEnd(head);
    display(head);
    cout<<searchAndDisplay(head,3);
    return 0;
}