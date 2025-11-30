#include <iostream>
using namespace std;

class PriorityQueue{
public:
    int a[1000];
    int n;

    PriorityQueue(){
        n = 0;
    }

    void push(int x){
        a[n] = x;
        int i = n;
        n++;
        while(i>0){
            int p = (i-1)/2;
            if(a[p] < a[i]){
                swap(a[p], a[i]);
                i = p;
            } else break;
        }
    }

    int top(){
        if(n==0) return -1;
        return a[0];
    }

    void pop(){
        if(n==0) return;
        a[0] = a[n-1];
        n--;
        int i = 0;
        while(true){
            int l = 2*i+1;
            int r = 2*i+2;
            int mx = i;
            if(l<n && a[l] > a[mx]) mx = l;
            if(r<n && a[r] > a[mx]) mx = r;
            if(mx != i){
                swap(a[mx], a[i]);
                i = mx;
            } else break;
        }
    }
};

int main(){
    PriorityQueue pq;
    int x;
    while(cin >> x){
        if(x == -1) break;
        pq.push(x);
    }
    while(pq.n){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
