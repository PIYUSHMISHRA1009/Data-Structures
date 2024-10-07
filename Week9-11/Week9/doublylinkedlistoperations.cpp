#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL; // Use NULL instead of nullptr for compatibility
    }

    ~DoublyLinkedList() {
        // Destructor to free memory
        while (head != NULL) {
            deleteFromEnd();
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        if (position == 1) {
            newNode->next = head;
            newNode->prev = NULL;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            delete newNode; // Prevent memory leak
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteFromPosition(int position) {
        if (head == NULL || position <= 0) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* temp = head;
        if (position == 1) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return;
        }
        for (int i = 1; temp != NULL && i < position; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void insertAfter(int target, int data) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Target element not found" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void insertBefore(int target, int data) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == target) {
            insertAtPosition(data, 1);
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Target element not found" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, data, position, target;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Delete from end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from position\n";
        cout << "5. Insert after element\n";
        cout << "6. Insert before element\n";
        cout << "7. Print list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 2:
                list.deleteFromEnd();
                break;
            case 3:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter data: ";
                cin >> data;
                list.insertAtPosition(data, position);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 5:
                cout << "Enter target element: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                list.insertAfter(target, data);
                break;
            case 6:
                cout << "Enter target element: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                list.insertBefore(target, data);
                break;
            case 7:
                list.printList();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

