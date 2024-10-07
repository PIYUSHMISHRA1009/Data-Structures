#include <iostream>
using namespace std;

struct Node {
    int coefficient;
    int exponent;
    Node* prev;
    Node* next;
};

class Polynomial {
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    ~Polynomial() {
        while (head != NULL) {
            deleteTerm(0);
        }
    }

    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node();
        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
        newNode->next = NULL;

        if (head == NULL || head->exponent < exponent) {
            newNode->prev = NULL;
            if (head != NULL) {
                newNode->next = head;
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }

        if (temp->exponent == exponent) {
            temp->coefficient += coefficient;
            delete newNode;
            if (temp->coefficient == 0) {
                deleteTerm(temp->exponent);
            }
            return;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteTerm(int exponent) {
        if (head == NULL) return;

        Node* temp = head;
        while (temp != NULL && temp->exponent != exponent) {
            temp = temp->next;
        }
        if (temp == NULL) return;

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    Polynomial add(const Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL && (p2 == NULL || p1->exponent > p2->exponent)) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else if (p2 != NULL && (p1 == NULL || p2->exponent > p1->exponent)) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    void printPolynomial() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coefficient << "x^" << temp->exponent;
            if (temp->next != NULL) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2, result;
    int choice, coefficient, exponent;

    cout << "Polynomial A:\n";
    while (true) {
        cout << "Enter coefficient and exponent (or -1 to finish): ";
        cin >> coefficient;
        if (coefficient == -1) break;
        cin >> exponent;
        poly1.insertTerm(coefficient, exponent);
    }

    cout << "Polynomial B:\n";
    while (true) {
        cout << "Enter coefficient and exponent (or -1 to finish): ";
        cin >> coefficient;
        if (coefficient == -1) break;
        cin >> exponent;
        poly2.insertTerm(coefficient, exponent);
    }

    result = poly1.add(poly2);

    cout << "Polynomial A: ";
    poly1.printPolynomial();
    cout << "Polynomial B: ";
    poly2.printPolynomial();
    cout << "Result of A + B: ";
    result.printPolynomial();

    return 0;
}

