#include <iostream>
#include <string>
using namespace std;
class Stack{
    int* arr;
    int top;
    int capacity;
    public:
    Stack(int c){
        this->capacity = c;
        this->arr = new int[c];
        this->top = -1;
    }
void push(int w){
    if(this->top == this->capacity - 1){
        cout<<"Overflow\n";
        return;
    }
    this->top++;
    this->arr[this->top] = w;
}
int pop(){
    if(this->top == -1){
        cout<<"Underflow\n";
        return INT_LEAST16_MIN;
    }
    this->top--;
}
int peek(){
    if(this->top == -1){
        cout<<"Underflow\n";
        return INT_LEAST16_MIN;
    }
    return this->arr[this->top];
}
int postfixSolve(string s){
    for (int i=0;i<s.size();i++){
        if (s[i] == '+'|| s[i] == '-'|| s[i] == '*'|| s[i] == '/'){
            int y = this->peek();
            this->pop();
            int x = this->peek();
            this->pop();
            if (s[i] == '+') this->push(x+y);
            else if (s[i] == '-') this->push(x-y);
            else if (s[i] == '*') this->push(x*y);
            else this->push(x/y);
        }
        else{
            this->push(s[i]-'0');
        }
    }
    return this->peek();
}

};
int main(){
    string str;
    cout<<"String: ";
    getline(cin,str);
    int c = str.size();
    Stack st(c);
    cout<<"Sum: "<<st.postfixSolve(str);
}