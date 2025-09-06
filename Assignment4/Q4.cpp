#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front;
    int back;
    int capacity;
    vector<char> v;

public:
    Queue(int cap = 100) {
        this->front = -1;
        this->back = -1;
        this->capacity = cap;
        v.resize(capacity);
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((back + 1) % capacity == front);
    }

    void enqueue(char data) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = back = 0;
        } else {
            back = (back + 1) % capacity;
        }
        v[back] = data;
    }

    char dequeue() {
        if (isEmpty()) {
            return '#';
        }
        char val = v[front];
        if (front == back) {
            front = back = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return val;
    }

    char getFront() {
        if (isEmpty()) return '#';
        return v[front];
    }
};

void firstNonRepeating(string s) {
    Queue q(s.size() + 5);
    int freq[256] = {0};

    for (char ch : s) {
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.getFront() << " ";
    }
    cout << "\n";
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
    return 0;
}
