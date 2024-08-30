#include <iostream>
#include <string>
using namespace std;

class Flight {
private:
    int flight_number;
    string destination;
    float distance;
    float fuel;

    void calculate_fuel() {
        if (distance <= 1000)
            fuel = 500;
        else if (distance > 1000 && distance <= 2000)
            fuel = 1100;
        else
            fuel = 2200;
    }

public:
    Flight() {
        fuel = 13.2;
    }

    void information_entry() {
        cout << "Enter flight number: ";
        cin >> flight_number;
        cout << "Enter destination: ";
        cin >> destination;
        cout << "Enter distance (in kilometers): ";
        cin >> distance;
        calculate_fuel();
    }

    void display_info() {
        cout << "Flight Number: " << flight_number << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Fuel Required: " << fuel << " liters" << endl;
    }
};

int main() {
    Flight flight;
    flight.information_entry();
    flight.display_info();
    return 0;
}

