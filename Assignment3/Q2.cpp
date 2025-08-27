#include <iostream>
#include <string>
using namespace std;

class Stack{
    char* arr;
    int top;
    int capacity;
    public:
    Stack(int c){
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
void reverseString(){
    for(int i = top;i>=0;i--){
        cout<<this->arr[i];
    }
}
};
int main(){
    string str;
    cout<<"String: ";
    getline(cin,str);
    int c = str.size();
    Stack st(c);
    for(int i=0;i<str.size();i++){
        st.push(str[i]);
    }
    st.reverseString();
    return 0;
}