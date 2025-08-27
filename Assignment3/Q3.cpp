#include <iostream>
#include <string>
using namespace std;
bool isMatching(char open,char close);
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
        cout<<"Overflow\n";
        return INT_LEAST16_MIN;
    }
    this->top--;
}
bool isBalanced(string s){
    for (int i=0;i<s.size();i++){
        if (s[i] == '{'|| s[i] == '['|| s[i] == '('){
            this->push(s[i]);
        }
        if (s[i] == '}'|| s[i] == ']'|| s[i] == ')'){
            if (this->top == -1) return false;
            else if(!isMatching(this->arr[this->top],s[i])) return false;
            else this->pop();
        }
    }
    return this->top == -1;
}

};
bool isMatching(char open,char close){
    return (open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')');
}
int main(){
    string str;
    cout<<"String: ";
    getline(cin,str);
    int c = str.size();
    Stack st(c);
    if (st.isBalanced(str)) cout<<"True";
    else cout<<"False";
    return 0;
}