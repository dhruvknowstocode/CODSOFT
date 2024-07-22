#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int maxSize = 1000) {
        size = maxSize;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void insert(int data) {
        if (rear == size) {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    void pop() {
        if (front == rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        arr[front] = -1;
        front++;
        if (front == rear) {
            front = 0;
            rear = 0;
        }
    }

    // Function to print the front element of the queue
    void printFront() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    Queue q;

    q.insert(1);
    q.insert(2);
    q.insert(3);

    q.printFront(); // Print the front element

    q.pop();
    q.pop();
    q.pop();
    q.pop(); // This will print "Queue underflow"

    return 0;
}
