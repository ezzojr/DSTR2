#include "HospitalSystem.hpp"

// ============================================================================
// ROLE 4: AMBULANCE DISPATCHER - CIRCULAR QUEUE IMPLEMENTATION
// Student Name: [STUDENT 4 NAME]
// Student ID: [STUDENT 4 ID]
// ============================================================================

// Constructor
AmbulanceCircularQueue::AmbulanceCircularQueue(int cap) {
    capacity = cap;
    queue = new Ambulance[capacity];
    front = -1;
    rear = -1;
    count = 0;
}

// Destructor
AmbulanceCircularQueue::~AmbulanceCircularQueue() {
    delete[] queue;
}

// Functionality 1: Register Ambulance (Add to circular queue)
void AmbulanceCircularQueue::registerAmbulance(string vehicleID, string driverName) {
    if (isFull()) {
        cout << "\n[ERROR] Ambulance roster is full! Cannot register more ambulances." << endl;
        return;
    }

    Ambulance newAmbulance(vehicleID, driverName);

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }

    queue[rear] = newAmbulance;
    count++;

    cout << "\n[SUCCESS] Ambulance registered!" << endl;
    cout << "Vehicle ID: " << vehicleID << endl;
    cout << "Driver: " << driverName << endl;
}

// Functionality 2: Rotate Ambulance Shift
void AmbulanceCircularQueue::rotateAmbulanceShift() {
    if (isEmpty()) {
        cout << "\n[ERROR] No ambulances registered!" << endl;
        return;
    }

    cout << "\n[ROTATION] Rotating ambulance shift..." << endl;
    cout << "Ambulance " << queue[front].vehicleID
         << " (Driver: " << queue[front].driverName << ") completes duty." << endl;

    // Move front ambulance to rear (rotation)
    Ambulance rotatedAmbulance = queue[front];

    front = (front + 1) % capacity;
    rear = (rear + 1) % capacity;
    queue[rear] = rotatedAmbulance;

    cout << "Ambulance " << rotatedAmbulance.vehicleID
         << " moved to end of rotation." << endl;
    cout << "[SUCCESS] Shift rotation complete!" << endl;
}

// Functionality 3: Display Ambulance Schedule
void AmbulanceCircularQueue::displayAmbulanceSchedule() {
    if (isEmpty()) {
        cout << "\n[INFO] No ambulances in rotation schedule." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "    AMBULANCE DUTY ROTATION SCHEDULE" << endl;
    cout << "========================================" << endl;
    cout << left << setw(15) << "Vehicle ID"
         << setw(20) << "Driver Name"
         << setw(10) << "Status" << endl;
    cout << "----------------------------------------" << endl;

    int index = front;
    for (int i = 0; i < count; i++) {
        string status = (i == 0) ? "ON DUTY" : "WAITING";
        cout << left << setw(15) << queue[index].vehicleID
             << setw(20) << queue[index].driverName
             << setw(10) << status << endl;
        index = (index + 1) % capacity;
    }

    cout << "----------------------------------------" << endl;
    cout << "Total ambulances: " << count << endl;
    cout << "Next on duty: " << queue[front].vehicleID << endl;
    cout << "========================================" << endl;
}

// Helper: Check if queue is empty
bool AmbulanceCircularQueue::isEmpty() {
    return count == 0;
}

// Helper: Check if queue is full
bool AmbulanceCircularQueue::isFull() {
    return count == capacity;
}

// Helper: Get count
int AmbulanceCircularQueue::getCount() {
    return count;
}
