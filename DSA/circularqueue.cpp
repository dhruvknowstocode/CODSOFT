#include<iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int maxSize = 1000) {
        size = maxSize;
        arr = new int[size];
        front = -1; // Initialize front and rear to -1 to indicate an empty queue
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to insert an element into the queue
    void insert(int data) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size; // Wrap around if necessary
        }
        arr[rear] = data;
    }

    // Function to remove an element from the queue
    void pop() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return;
        }
        if (front == rear) {
            // If there's only one element in the queue, reset front and rear to -1
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Wrap around if necessary
        }
    }

    // Function to print the front element of the queue
    void printFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    CircularQueue cq(5); // Create a circular queue with a maximum size of 5

    cq.insert(1);
    cq.insert(2);
    cq.insert(3);

    cq.printFront(); // Print the front element

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop(); // This will print "Queue underflow"

    return 0;
}
