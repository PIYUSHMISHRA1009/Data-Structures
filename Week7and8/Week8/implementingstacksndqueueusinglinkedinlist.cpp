#include <iostream>
using namespace std;

// Node class for Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack implementation using Linked List
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Queue implementation using Linked List
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue\n";
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    Queue queue;

    // Stack operations
    cout << "Stack operations:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Popped from stack: " << stack.pop() << endl;
    stack.display();

    // Queue operations
    cout << "\nQueue operations:\n";
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    cout << "Dequeued from queue: " << queue.dequeue() << endl;
    queue.display();

    return 0;
}
