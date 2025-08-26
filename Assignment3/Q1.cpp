#include <iostream>
using namespace std;

class Stack{
    int capacity;
    int* arr;
    int top;
    public:
    Stack(int c){
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
void push(int data){
    if(this->top == this->capacity - 1){
        cout<<"Overflow\n";
        return;
    }
    this->top++;
    this->arr[this->top] = data;
}
int pop(){
    if(this->top == -1){
        cout<<"Overflow\n";
        return INT_LEAST16_MIN;
    }
    this->top--;
}
int peek(){
    if(this->top == -1){
        cout<<"Overflow\n";
        return INT_LEAST16_MIN;
    }
    return this->arr[this->top];
}
void display(){
    for(int i=top;i>=0;i--){
        cout<<this->arr[i]<<" ";
    }
}
bool isEmpty(){
    return this->top == -1;
}
bool isFull(){
    return this->top == this->capacity - 1;
}
};
int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.peek()<<endl;
    st.pop();
    st.push(6);
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    st.display();
    return 0;
}