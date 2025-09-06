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
void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = new_node;
}
int middleelem(Node* &head){
    Node* temps = head;
    Node* tempf = head;
    while((tempf != NULL) && (tempf->next != NULL)){
        temps = temps->next;
        tempf = tempf->next->next;
    }
    return temps->val;

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
    int n;
    cout<<"n: ";
    cin>>n;
    cout<<"Element: ";
    for (int i=0; i<n;i++){
        int element;
        cin>>element;
        insertAtTail(head,element);
    }
    display(head);
    cout<<middleelem(head);
    return 0;
}