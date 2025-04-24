#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string make;
    string model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string id, string mk, string mdl, int yr, double rate)
        : vehicleID(id), make(mk), model(mdl), year(yr), dailyRentalRate(rate), isRented(false) {}

    virtual ~Vehicle() {}

    string getVehicleID() { return vehicleID; }
    string getMake() { return make; }
    string getModel() { return model; }
    int getYear() { return year; }
    bool getIsRented() { return isRented; }
    double getDailyRentalRate() { return dailyRentalRate; }

    virtual double calculateRentalCost(int days) = 0;
    virtual void displayDetails() {
        cout << "ID: " << vehicleID << "\nMake: " << make << "\nModel: " << model
             << "\nYear: " << year << "\nRate: $" << dailyRentalRate
             << "\nRented: " << (isRented ? "Yes" : "No") << endl;
    }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }
};

class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;

public:
    Car(string id, string mk, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, mk, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Doors: " << numberOfDoors << "\nFuel: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicle {
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string id, string mk, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, mk, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Engine: " << engineType << "\nSidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string id, string mk, string mdl, int yr, double rate, double cargo, int axles)
        : Vehicle(id, mk, mdl, yr, rate), cargoCapacity(cargo), numberOfAxles(axles) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Cargo Capacity: " << cargoCapacity << " m^3\nAxles: " << numberOfAxles << endl;
    }
};

class RentalSystem {
    vector<Vehicle*> vehicles;

public:
    ~RentalSystem() {
        for (auto v : vehicles) delete v;
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() {
        for (auto v : vehicles) {
            if (!v->getIsRented()) {
                v->displayDetails();
                cout << "------------------" << endl;
            }
        }
    }

    Vehicle* findVehicle(string vehicleID) {
        for (auto v : vehicles) {
            if (v->getVehicleID() == vehicleID) return v;
        }
        return nullptr;
    }

    void rentVehicle(string vehicleID, int days) {
        Vehicle* v = findVehicle(vehicleID);
        if (v && !v->getIsRented()) {
            v->rentVehicle();
            double cost = v->calculateRentalCost(days);
            cout << "Rental Cost: $" << cost << endl;
        } else {
            cout << "Vehicle not available." << endl;
        }
    }

    void returnVehicle(string vehicleID) {
        Vehicle* v = findVehicle(vehicleID);
        if (v && v->getIsRented()) {
            v->returnVehicle();
            cout << "Vehicle returned." << endl;
        } else {
            cout << "Vehicle not found or not rented." << endl;
        }
    }
};

int main() {
    RentalSystem system;

    system.addVehicle(new Car("CAR123", "Toyota", "Corolla", 2020, 50, 4, "Petrol"));
    system.addVehicle(new Motorcycle("MOTO456", "Yamaha", "R15", 2019, 30, "Inline-4", false));
    system.addVehicle(new Truck("TRUCK789", "Volvo", "FH16", 2018, 100, 15.5, 4));

    int choice;
    string id;
    int days;

    do {
        cout << "\n1. Display Available Vehicles\n2. Rent a Vehicle\n3. Return a Vehicle\n4. Find Vehicle and Display Details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.displayAvailableVehicles();
            break;
        case 2:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter number of days: ";
            cin >> days;
            system.rentVehicle(id, days);
            break;
        case 3:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            system.returnVehicle(id);
            break;
        case 4:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            {
                Vehicle* v = system.findVehicle(id);
                if (v) v->displayDetails();
                else cout << "Vehicle not found." << endl;
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}

