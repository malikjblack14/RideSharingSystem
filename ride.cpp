#include <iostream>
#include <vector>
using namespace std;

// Base Ride Class
class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup),
          dropoffLocation(dropoff), distance(dist) {}

    virtual double calculateFare() {
        return distance * 1.5;
    }

    virtual void rideDetails() {
        cout << "Ride ID: " << rideID << endl;
        cout << "From: " << pickupLocation << endl;
        cout << "To: " << dropoffLocation << endl;
        cout << "Distance: " << distance << " miles" << endl;
        cout << "Fare: $" << calculateFare() << endl;
        cout << "----------------------" << endl;
    }
};

// Standard Ride Class
class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double calculateFare() override {
        return distance * 1.5;
    }
};

// Premium Ride Class
class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double calculateFare() override {
        return distance * 3.0;
    }
};

// Driver Class
class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;

public:
    Driver(int id, string n, double r)
        : driverID(id), name(n), rating(r) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() {
        cout << "Driver ID: " << driverID << endl;
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Completed Rides: " << assignedRides.size() << endl;
        cout << "----------------------" << endl;
    }
};

// Rider Class
class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(int id, string n)
        : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() {
        cout << "Rider: " << name << endl;
        for (auto ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

int main() {

    // Create ride objects
    StandardRide ride1(1, "Downtown", "Airport", 10);
    PremiumRide ride2(2, "Mall", "Hotel", 5);

    // Demonstrate Polymorphism
    vector<Ride*> rides;
    rides.push_back(&ride1);
    rides.push_back(&ride2);

    cout << "=== Polymorphism Demo ===" << endl;
    for (auto ride : rides) {
        ride->rideDetails();
    }

    // Driver
    Driver driver(101, "John Smith", 4.9);
    driver.addRide(&ride1);
    driver.addRide(&ride2);
    driver.getDriverInfo();

    // Rider
    Rider rider(201, "Alice Johnson");
    rider.requestRide(&ride1);
    rider.requestRide(&ride2);
    rider.viewRides();

    return 0;
}

