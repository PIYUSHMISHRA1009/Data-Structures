#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
    int front, rear, size;
    string* queue;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new string[s];
    }

    void insert(string data) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else if (front == -1) {
            front = rear = 0;
            queue[rear] = data;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = data;
        }
    }

    string deleteElement() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return "";
        } else if (front == rear) {
            string temp = queue[front];
            front = rear = -1;
            return temp;
        } else {
            string temp = queue[front];
            front = (front + 1) % size;
            return temp;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else if (rear >= front) {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i < size; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

// Example usage
int main() {
    CircularQueue cq(5);
    cq.insert("A");
    cq.insert("B");
    cq.insert("C");
    cq.display();
    cout << "Deleted element: " << cq.deleteElement() << endl;
    cq.display();
    cq.insert("D");
    cq.insert("E");
    cq.insert("F");
    cq.display();
    return 0;
}

