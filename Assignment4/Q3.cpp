#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front;
    int back;
    int capacity;
    vector<int> v;

public:
    Queue(int cap = 10) {
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

    void enqueue(int data) {
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

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = v[front];
        if (front == back) {
            front = back = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return v[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << v[i] << " ";
            if (i == back) break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }

    int size() {
        if (isEmpty()) return 0;
        if (back >= front) return back - front + 1;
        return capacity - front + back + 1;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!\n";
        return;
    }

    int half = n / 2;
    Queue temp(half);

    for (int i = 0; i < half; i++) {
        temp.enqueue(q.dequeue());
    }

    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q(10);

    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved ";
    q.display();

    return 0;
}