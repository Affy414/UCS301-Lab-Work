#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front;
    int back;
    int capacity;
    vector<int> v;

public:
    Queue(int cap = 5) {
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
            front = 0;
            back = 0;
        } else {
            back = (back + 1) % capacity;
        }
        v[back] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == back) {
            front = back = -1;
        } else {
            front = (front + 1) % capacity;
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
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << v[i] << " ";
            if (i == back) break;
            i = (i + 1) % capacity;
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

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();

    q.dequeue();
    q.enqueue(70); 
    q.display();

    cout << "Is Empty? " << q.isEmpty() << "\n";
    cout << "Is Full? " << q.isFull() << "\n";
    return 0;
}
