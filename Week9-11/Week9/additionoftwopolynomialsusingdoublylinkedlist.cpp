#include <iostream>
using namespace std;

struct Node {
    int coefficient, exponent;
    Node* prev;
    Node* next;
    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), prev(nullptr), next(nullptr) {}
};

class Polynomial {
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        while (head) deleteTerm(head->exponent);
    }

    void insertTerm(int coefficient, int exponent) {
        if (coefficient == 0) return;

        Node* newNode = new Node(coefficient, exponent);
        if (!head || head->exponent < exponent) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->exponent > exponent) temp = temp->next;

        if (temp->exponent == exponent) {
            temp->coefficient += coefficient;
            delete newNode; 
            if (temp->coefficient == 0) deleteTerm(temp->exponent);
            return;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteTerm(int exponent) {
        Node* temp = head;

        while (temp && temp->exponent != exponent) temp = temp->next;
        
        if (!temp) return; 

        if (temp->prev) temp->prev->next = temp->next; 
        else head = temp->next; 
        
        if (temp->next) temp->next->prev = temp->prev; 
        delete temp; 
    }

    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        for (Node *p1 = head, *p2 = other.head; p1 || p2;) {
            if (!p1 || (p2 && p2->exponent > p1->exponent)) 
                result.insertTerm(p2->coefficient, p2->exponent), p2 = p2->next;
            else if (!p2 || (p1 && p1->exponent > p2->exponent)) 
                result.insertTerm(p1->coefficient, p1->exponent), p1 = p1->next;
            else 
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent), p1 = p1->next, p2 = p2->next;
        }
        return result;
    }

    void printPolynomial() const {
        for (Node* temp = head; temp; temp = temp->next) {
            cout << temp->coefficient << "x^" << temp->exponent << (temp->next ? " + " : "");
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    for (int coeff, exp; true;) {
        cout << "Polynomial A: Enter coefficient and exponent (-1 to finish): ";
        cin >> coeff; if (coeff == -1) break; cin >> exp; poly1.insertTerm(coeff, exp);
    }

    for (int coeff, exp; true;) {
        cout << "Polynomial B: Enter coefficient and exponent (-1 to finish): ";
        cin >> coeff; if (coeff == -1) break; cin >> exp; poly2.insertTerm(coeff, exp);
    }

    Polynomial result = poly1.add(poly2);
    
    cout << "Polynomial A: "; poly1.printPolynomial();
    cout << "Polynomial B: "; poly2.printPolynomial();
    cout << "Result of A + B: "; result.printPolynomial();

    return 0;
}
