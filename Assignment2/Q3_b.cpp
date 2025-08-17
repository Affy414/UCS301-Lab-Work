#include <iostream>
using namespace std;
int findMissing(int arr[], int n){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == mid + 1) l = mid + 1;
        else r = mid - 1;
    }
    return l + 1;
}
int main(){
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number: " << findMissing(arr, n);
    return 0;
}