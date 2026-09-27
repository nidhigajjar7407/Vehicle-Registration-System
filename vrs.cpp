#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

public:
    Vehicle() : vehicleID(0), manufacturer("Unknown"), model("Unknown"), year(0) {
        totalVehicles++;
    }

    Vehicle(int id, string mfg, string mdl, int yr)
        : vehicleID(id), manufacturer(mfg), model(mdl), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    int getVehicleID() const { return vehicleID; }
    void setVehicleID(int id) { vehicleID = id; }

    string getManufacturer() const { return manufacturer; }
    void setManufacturer(const string& mfg) { manufacturer = mfg; }

    string getModel() const { return model; }
    void setModel(const string& mdl) { model = mdl; }

    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }

    virtual void displayDetails() const {
        cout << "ID: " << vehicleID
             << " | Manufacturer: " << manufacturer
             << " | Model: " << model
             << " | Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle(), fuelType("Unknown") {}

    Car(int id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr), fuelType(fuel) {}

    string getFuelType() const { return fuelType; }
    void setFuelType(const string& fuel) { fuelType = fuel; }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << " | Fuel Type: " << fuelType;
    }
};

class Sedan : public Car {
private:
    int bootCapacity;

public:
    Sedan() : Car(), bootCapacity(0) {}

    Sedan(int id, string mfg, string mdl, int yr, string fuel, int bootCap)
        : Car(id, mfg, mdl, yr, fuel), bootCapacity(bootCap) {}

    void displayDetails() const override {
        Car::displayDetails();
        cout << " | Type: Sedan | Boot Capacity: " << bootCapacity << "L";
    }
};

class SUV : public Car {
private:
    bool isFourWheelDrive;

public:
    SUV() : Car(), isFourWheelDrive(false) {}

    SUV(int id, string mfg, string mdl, int yr, string fuel, bool fourWD)
        : Car(id, mfg, mdl, yr, fuel), isFourWheelDrive(fourWD) {}

    void displayDetails() const override {
        Car::displayDetails();
        cout << " | Type: SUV | 4WD: "
             << (isFourWheelDrive ? "Yes" : "No");
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car(), batteryCapacity(0) {
        fuelType = "Electric";
    }

    ElectricCar(int id, string mfg, string mdl, int yr, int batteryCap)
        : Car(id, mfg, mdl, yr, "Electric"),
          batteryCapacity(batteryCap) {}

    int getBatteryCapacity() const {
        return batteryCapacity;
    }

    void setBatteryCapacity(int batteryCap) {
        batteryCapacity = batteryCap;
    }

    void displayDetails() const override {
        Car::displayDetails();
        cout << " | Battery Capacity: "
             << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar(), topSpeed(0) {}

    SportsCar(int id, string mfg, string mdl, int yr,
              int batteryCap, int speed)
        : ElectricCar(id, mfg, mdl, yr, batteryCap),
          topSpeed(speed) {}

    void displayDetails() const override {
        ElectricCar::displayDetails();
        cout << " | Top Speed: " << topSpeed << " km/h";
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() : flightRange(0) {}

    Aircraft(int range) : flightRange(range) {}

    int getFlightRange() const {
        return flightRange;
    }

    void setFlightRange(int range) {
        flightRange = range;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int id, string mfg, string mdl, int yr,
              string fuel, int range)
        : Car(id, mfg, mdl, yr, fuel),
          Aircraft(range) {}

    void displayDetails() const override {
        Car::displayDetails();
        cout << " | Flight Range: "
             << flightRange << " km";
    }
};

class VehicleRegistry {
private:
    Vehicle* registry[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete registry[i];
        }
    }

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            registry[count++] = v;
            cout << "\nVehicle registered successfully!\n";
        } else {
            cout << "\nRegistry full! Cannot add more vehicles.\n";
        }
    }

    void displayAll() const {
        if (count == 0) {
            cout << "\nNo vehicles registered yet.\n";
            return;
        }

        cout << "\n================ VEHICLE REGISTRY ================\n";

        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            registry[i]->displayDetails();
            cout << "\n";
        }

        cout << "=================================================\n";
    }

    void searchById(int id) const {
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (registry[i]->getVehicleID() == id) {
                cout << "\n[Vehicle Found]\n";
                registry[i]->displayDetails();
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nVehicle with ID "
                 << id << " not found.\n";
        }
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- VEHICLE REGISTRY SYSTEM MENU ---\n";
        cout << "1. Add a Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. View Total Created Vehicles (Static Counter)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int typeChoice;

            cout << "\nSelect Vehicle Type to Add:\n";
            cout << "1. Sedan \n";
            cout << "2. SUV \n";
            cout << "3. Electric Car \n";
            cout << "4. Sports Car \n";
            cout << "5. Flying Car \n";
            cout << "Enter type: ";
            cin >> typeChoice;

            int id, year;
            string mfg, mdl;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> mfg;

            cout << "Enter Model: ";
            cin >> mdl;

            cout << "Enter Year: ";
            cin >> year;

            if (typeChoice == 1) {
                string fuel;
                int bootCap;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Enter Boot Capacity (L): ";
                cin >> bootCap;

                registry.addVehicle(
                    new Sedan(id, mfg, mdl, year, fuel, bootCap)
                );
            }
            else if (typeChoice == 2) {
                string fuel;
                bool is4WD;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Is 4WD? (1 for Yes, 0 for No): ";
                cin >> is4WD;

                registry.addVehicle(
                    new SUV(id, mfg, mdl, year, fuel, is4WD)
                );
            }
            else if (typeChoice == 3) {
                int batteryCap;

                cout << "Enter Battery Capacity (kWh): ";
                cin >> batteryCap;

                registry.addVehicle(
                    new ElectricCar(id, mfg, mdl, year, batteryCap)
                );
            }
            else if (typeChoice == 4) {
                int batteryCap, topSpeed;

                cout << "Enter Battery Capacity (kWh): ";
                cin >> batteryCap;

                cout << "Enter Top Speed (km/h): ";
                cin >> topSpeed;

                registry.addVehicle(
                    new SportsCar(
                        id, mfg, mdl, year,
                        batteryCap, topSpeed
                    )
                );
            }
            else if (typeChoice == 5) {
                string fuel;
                int flightRange;

                cout << "Enter Fuel Type: ";
                cin >> fuel;

                cout << "Enter Flight Range (km): ";
                cin >> flightRange;

                registry.addVehicle(
                    new FlyingCar(
                        id, mfg, mdl, year,
                        fuel, flightRange
                    )
                );
            }
            else {
                cout << "Invalid vehicle type chosen!\n";
            }

            break;
        }

        case 2:
            registry.displayAll();
            break;

        case 3: {
            int searchId;

            cout << "Enter Vehicle ID to Search: ";
            cin >> searchId;

            registry.searchById(searchId);
            break;
        }

        case 4:
            cout << "\nTotal Vehicle Instances Created: "
                 << Vehicle::getTotalVehicles() << "\n";
            break;

        case 5:
            cout << "\nExiting Vehicle Registry System. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}