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
    }

    bool isEmpty() {
        return (front == -1 && back == -1);
    }

    bool isFull() {
        return (back == capacity - 1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            back = 0;
        } else {
            back++;
        }
        v.push_back(data);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == back) {
            front = back = -1;
            v.clear();
        } else {
            front++;
        }
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
        for (int i = front; i <= back; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Peek: " << q.peek() << "\n";
    q.dequeue();
    q.display();
    cout << "Is Empty? " << q.isEmpty() << "\n";
    cout << "Is Full? " << q.isFull() << "\n";
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    cout << "Is Empty? " << q.isEmpty() << "\n";
    q.enqueue(38);
    q.enqueue(39);
    q.enqueue(31);
    q.enqueue(33);
    q.enqueue(36);
    q.enqueue(30);
    q.display();
    return 0;
}
