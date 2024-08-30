#include <iostream>
#include <string>
using namespace std;

class EMPLOYEE {
private:
    int Employee_Number;
    string Employee_Name;
    double Basic;
    double DA;
    double IT;
    double Gross_salary;
    double Net_Sal;

public:
    void readData() {
        cout << "Enter Employee Number: ";
        cin >> Employee_Number;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, Employee_Name);
        cout << "Enter Basic Salary: ";
        cin >> Basic;
    }

    void calculateSalary() {
        DA = 0.12 * Basic;
        Gross_salary = Basic + DA;
        IT = 0.18 * Gross_salary;
        Net_Sal = Gross_salary - IT;
    }

    void displaySalary() const {
        cout << "\nEmployee Number: " << Employee_Number;
        cout << "\nEmployee Name: " << Employee_Name;
        cout << "\nBasic Salary: " << Basic;
        cout << "\nDearness Allowance (DA): " << DA;
        cout << "\nGross Salary: " << Gross_salary;
        cout << "\nIncome Tax (IT): " << IT;
        cout << "\nNet Salary: " << Net_Sal << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;

    EMPLOYEE employees[N];

    for (int i = 0; i < N; ++i) {
        cout << "\nEnter details for employee " << (i + 1) << ":\n";
        employees[i].readData();
        employees[i].calculateSalary();
    }

    cout << "\nSalary details of all employees:\n";
    for (int i = 0; i < N; ++i) {
        employees[i].displaySalary();
        cout << "-----------------------------------\n";
    }

    return 0;
}

