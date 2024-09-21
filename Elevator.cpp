#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

class Elevator {
public:
    int currentFloor;
    int maxFloor, minFloor;
    string direction;
    vector<int> upRequests;   // Requests to go up
    vector<int> downRequests; // Requests to go down

    Elevator(int maxFloor) {
        this->currentFloor = 0; // Start at ground floor
        this->maxFloor = maxFloor;
        this->minFloor = 0;
        this->direction = "idle";
    }

    // Adds a request based on the direction
    void handleRequest(int floor) {
        if (floor > currentFloor) {
            upRequests.push_back(floor);
            cout << "Request to go up to floor " << floor << " added." << endl;
        } else if (floor < currentFloor) {
            downRequests.push_back(floor);
            cout << "Request to go down to floor " << floor << " added." << endl;
        }
    }

    // Process the requests in order (first up, then down)
    void processRequests() {
        // Sort requests to make sure they are in the correct order
        sort(upRequests.begin(), upRequests.end());
        sort(downRequests.begin(), downRequests.end(), greater<int>());

        // Process up requests first
        if (!upRequests.empty()) {
            direction = "up";
            for (int floor : upRequests) {
                moveToFloor(floor);
            }
            upRequests.clear(); // All up requests handled
        }

        // Process down requests
        if (!downRequests.empty()) {
            direction = "down";
            for (int floor : downRequests) {
                moveToFloor(floor);
            }
            downRequests.clear(); // All down requests handled
        }

        direction = "idle";
    }

private:
    // Move to a specified floor
    void moveToFloor(int floor) {
        while (currentFloor < floor) {
            currentFloor++;
            cout << "Elevator moving up to floor " << currentFloor << endl;
        }
        while (currentFloor > floor) {
            currentFloor--;
            cout << "Elevator moving down to floor " << currentFloor << endl;
        }
        cout << "Elevator arrived at floor " << currentFloor << endl;
    }
};

class Building {
public:
    int floors;
    Elevator elevator;

    Building(int floors): elevator(floors) {
        this->floors = floors;
    }

    // Simulate requesting an elevator from a floor
    void requestElevator(int requestedFloor) {
        elevator.handleRequest(requestedFloor);
    }

    // Simulate elevator processing requests
    void simulate() {
        elevator.processRequests();
    }
};

int main() {
    Building building(10); // 10-floor building

    int choice;
    do {
        cout << "\nEnter a floor number to request the elevator (0 to exit): ";
        int floor;
        cin >> floor;

        if (floor < 0 || floor > 10) {
            cout << "Invalid floor number. Try again." << endl;
        } else if (floor != 0) {
            building.requestElevator(floor);
        }

        // Simulate the elevator's movements after each request
        building.simulate();
        
    } while (choice != 0);

    return 0;
}
