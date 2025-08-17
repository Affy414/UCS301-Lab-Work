#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[] = "Hello";
    int n = strlen(str);
    for(int i = 0; i < n / 2; i++){
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str;
    return 0;
}