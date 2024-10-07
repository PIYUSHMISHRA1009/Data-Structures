#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertBefore(int target, int data) {
        if (head == nullptr) return;
        if (head->data == target) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertAfter(int target, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteElement(int data) {
        if (head == nullptr) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, data, target;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before an element\n";
        cout << "4. Insert after an element\n";
        cout << "5. Delete an element\n";
        cout << "6. Print list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter target element: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                list.insertBefore(target, data);
                break;
            case 4:
                cout << "Enter target element: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                list.insertAfter(target, data);
                break;
            case 5:
                cout << "Enter data to delete: ";
                cin >> data;
                list.deleteElement(data);
                break;
            case 6:
                list.printList();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

