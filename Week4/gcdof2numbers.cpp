#include <iostream>
using namespace std;

int gcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

int main() {
    int a, b;
    cout << "Enter the first number for finding GCD: " << endl;
    cin >> a;
    cout << "Enter the second number for finding GCD: " << endl;
    cin >> b;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    cout << "The GCD of the entered numbers is: " << gcd(a, b) << endl;
    return 0;
}

