#ifndef HOSPITAL_SYSTEM_HPP
#define HOSPITAL_SYSTEM_HPP

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================================
// COMMON DATA STRUCTURES - Patient, Supply, Emergency, Ambulance
// ============================================================================

struct Patient {
    int id;
    string name;
    string conditionType;
    
    Patient() : id(0), name(""), conditionType("") {}
    Patient(int i, string n, string c) : id(i), name(n), conditionType(c) {}
};

struct MedicalSupply {
    string type;
    int quantity;
    string batch;

    MedicalSupply() : type(""), quantity(0), batch("") {}
    MedicalSupply(string t, int q, string b) : type(t), quantity(q), batch(b) {}
};

struct EmergencyCase {
    string patientName;
    string emergencyType;
    int priorityLevel;  // Higher number = higher priority

    EmergencyCase() : patientName(""), emergencyType(""), priorityLevel(0) {}
    EmergencyCase(string n, string t, int p) : patientName(n), emergencyType(t), priorityLevel(p) {}
};

struct Ambulance {
    string vehicleID;
    string driverName;

    Ambulance() : vehicleID(""), driverName("") {}
    Ambulance(string v, string d) : vehicleID(v), driverName(d) {}
};

// ============================================================================
// ROLE 1: PATIENT ADMISSION CLERK - QUEUE IMPLEMENTATION
// ============================================================================

class PatientQueue {
private:
    struct Node {
        Patient data;
        Node* next;
        Node(Patient p) : data(p), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    PatientQueue();
    ~PatientQueue();

    void admitPatient(int id, string name, string conditionType);
    void dischargePatient();
    void viewPatientQueue();
    bool isEmpty();
    int getCount();
};

// ============================================================================
// ROLE 2: MEDICAL SUPPLY MANAGER - STACK IMPLEMENTATION
// ============================================================================

class SupplyStack {
private:
    struct Node {
        MedicalSupply data;
        Node* next;
        Node(MedicalSupply s) : data(s), next(nullptr) {}
    };

    Node* top;
    int count;

public:
    SupplyStack();
    ~SupplyStack();

    void addSupplyStock(string type, int quantity, string batch);
    void useLastAddedSupply();
    void viewCurrentSupplies();
    bool isEmpty();
    int getCount();
};

// ============================================================================
// ROLE 3: EMERGENCY DEPARTMENT OFFICER - PRIORITY QUEUE (MAX HEAP)
// ============================================================================

class EmergencyPriorityQueue {
private:
    EmergencyCase* heap;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void resize();

public:
    EmergencyPriorityQueue(int cap = 50);
    ~EmergencyPriorityQueue();

    void logEmergencyCase(string patientName, string emergencyType, int priorityLevel);
    void processMostCriticalCase();
    void viewPendingEmergencyCases();
    bool isEmpty();
    int getSize();
};

// ============================================================================
// ROLE 4: AMBULANCE DISPATCHER - CIRCULAR QUEUE IMPLEMENTATION
// ============================================================================

class AmbulanceCircularQueue {
private:
    Ambulance* queue;
    int front;
    int rear;
    int capacity;
    int count;

public:
    AmbulanceCircularQueue(int cap = 10);
    ~AmbulanceCircularQueue();

    void registerAmbulance(string vehicleID, string driverName);
    void rotateAmbulanceShift();
    void displayAmbulanceSchedule();
    bool isEmpty();
    bool isFull();
    int getCount();
};

// ============================================================================
// MAIN HOSPITAL SYSTEM - INTEGRATION OF ALL MODULES
// ============================================================================

class HospitalSystem {
private:
    PatientQueue patientQueue;
    SupplyStack supplyStack;
    EmergencyPriorityQueue emergencyQueue;
    AmbulanceCircularQueue ambulanceQueue;

public:
    HospitalSystem();
    void displayMainMenu();
    void run();

    // Menu handlers for each role
    void handlePatientAdmissionMenu();
    void handleMedicalSupplyMenu();
    void handleEmergencyDepartmentMenu();
    void handleAmbulanceDispatchMenu();
};

#endif // HOSPITAL_SYSTEM_HPP
