#include <iostream>
using namespace std;

void heapify(int a[], int n, int i){
    int mx = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && a[l] > a[mx]) mx = l;
    if(r < n && a[r] > a[mx]) mx = r;
    if(mx != i){
        swap(a[i], a[mx]);
        heapify(a, n, mx);
    }
}

void heapSortInc(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void heapifyMin(int a[], int n, int i){
    int mn = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && a[l] < a[mn]) mn = l;
    if(r < n && a[r] < a[mn]) mn = r;
    if(mn != i){
        swap(a[i], a[mn]);
        heapifyMin(a, n, mn);
    }
}

void heapSortDec(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyMin(a,n,i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapifyMin(a,i,0);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    heapSortInc(a,n);
    heapSortDec(b,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << b[i] << " ";
    return 0;
}
