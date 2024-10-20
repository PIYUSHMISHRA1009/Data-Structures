#include <iostream>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        head = new Node(value);
        head->next = head; // Point to itself if it's the only node
    }

    void insertAtEnd(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }

        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new Node(value);
    }

    void insertBefore(int target, int value) {
        if (!head) return;

        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;

        if (!temp->next) {
            cout << "Element " << target << " not found." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;

        if (!temp) {
            cout << "Element " << target << " not found." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteElement(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) temp = temp->next;

        if (!temp->next) {
            cout << "Element " << value << " not found." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void printList() const {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " ";
        
        cout << (head ? "" : "List is empty.") << endl; // Print message if empty
    }

    ~LinkedList() { 
        while (head) deleteElement(head->data);
    }
};

int main() {
    LinkedList list;

    int choice, value, target;

    do {
        cout << "\nMenu:\n1. Insert at beginning\n2. Insert at end\n3. Insert before an element\n4. Insert after an element\n5. Delete an element\n6. Print the list\n7. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value; list.insertAtBeginning(value); break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value; list.insertAtEnd(value); break;

            case 3:
                cout << "Enter target element and value to insert before: ";
                cin >> target >> value; list.insertBefore(target, value); break;

            case 4:
                cout << "Enter target element and value to insert after: ";
                cin >> target >> value; list.insertAfter(target, value); break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> value; list.deleteElement(value); break;

            case 6:
                list.printList(); break;

            case 7:
                cout << "Exiting..." << endl; break;

            default:
                cout << "Invalid choice. Please try again." << endl; 
                break; 
         }
     } while (choice != 7);

     return 0; 
}
