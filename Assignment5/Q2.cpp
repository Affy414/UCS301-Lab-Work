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
int countAndDelete(Node* &head, int k){
    Node* temp1 = NULL;
    Node* temp2 = head;
    int count=0;
    while(temp2!=NULL){
        if (temp2->val == k) {
            if (temp1 == NULL){
                count++;
                head = temp2->next;
                delete temp2;
                temp2 = head;
            }
            else{
                count++;
                temp1->next = temp2->next;
                delete temp2;
                temp2 = temp1->next;
            }
        }
        else{
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    return count;
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
    int n,k;
    cout<<"n: ";
    cin>>n;
    cout<<"k: ";
    cin>>k;
    cout<<"Element: ";
    for (int i=0; i<n;i++){
        int element;
        cin>>element;
        insertAtTail(head,element);
    }
    display(head);
    cout<<countAndDelete(head,k)<<endl;
    display(head);
    return 0;
}