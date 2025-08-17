#include <iostream>
using namespace std;

void create(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void display(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertion(int arr[], int &n) {
    int pos, val;
    cout << "Enter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deletion(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}

void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }
}

void predictOutput() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        cout << arr[i];
    cout << "  (Explanation: First element is 1, rest are 0 due to default initialization)" << endl;
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void matrixMultiplication() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible." << endl;
        return;
    }

    int A[10][10], B[10][10], C[10][10] = {0};
    cout << "Enter elements of first matrix: ";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];
    cout << "Enter elements of second matrix: ";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Resultant Matrix: \n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}

void transpose() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int mat[10][10];
    cout << "Enter elements: ";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    cout << "Transpose: \n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << mat[j][i] << " ";
        cout << endl;
    }
}

void sumRowsCols() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int mat[10][10];
    cout << "Enter elements: ";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += mat[i][j];
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += mat[i][j];
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int arr[100], n = 0, choice;

    while (true) {
        cout << "\n--- MENU ---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.REMOVE DUPLICATES\n7.PREDICT OUTPUT\n8.REVERSE ARRAY\n9.MATRIX MULTIPLICATION\n10.TRANSPOSE MATRIX\n11.SUM OF ROWS & COLS\n12.EXIT\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(arr, n); break;
            case 2: display(arr, n); break;
            case 3: insertion(arr, n); break;
            case 4: deletion(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: removeDuplicates(arr, n); break;
            case 7: predictOutput(); break;
            case 8: reverseArray(arr, n); break;
            case 9: matrixMultiplication(); break;
            case 10: transpose(); break;
            case 11: sumRowsCols(); break;
            case 12: return 0;
            default: cout << "Invalid Input" << endl;
        }
    }
}
