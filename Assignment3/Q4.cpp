#include <iostream>
#include <string>
using namespace std;
int precedence(char sign);
class Stack{
    char* arr;
    int top;
    int capacity;
    public:
    Stack(int c){
        this->capacity = c;
        this->arr = new char[c];
        this->top = -1;
    }
void push(char w){
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
string infixToPostfix(string s){
    string res;
    for (int i=0;i<s.size();i++){
        if (s[i] == '+'|| s[i] == '-'|| s[i] == '*'|| s[i] == '/'){
        while ((this->top != -1) && (precedence(s[i]) <= precedence(this->peek()))){
            res.push_back(this->peek());
            this->pop();
        }
        this->push(s[i]);
        }
        else if(s[i] == '('){
        this->push('(');
        }
        else if(s[i] == ')'){
            while(this->top != -1 && this->peek() != '('){
                res.push_back(this->peek());
                this->pop();
            }
            if(this->top != -1) this->pop();
        }
        else res.push_back(s[i]);
    }
    while(this->top != -1){
        res.push_back(this->peek());
        this->pop();
    }
    return res;
}

};
int precedence(char sign){
    if (sign == '*' || sign == '/') return 2;
    if (sign == '+' || sign == '-') return 1;
    return 0;
}
int main(){
    string str;
    cout<<"String: ";
    getline(cin,str);
    int c = str.size();
    Stack st(c);
    cout<<st.infixToPostfix(str);
}