#include "HospitalSystem.hpp"

// ============================================================================
// ROLE 1: PATIENT ADMISSION CLERK - QUEUE IMPLEMENTATION
// Student Name: [STUDENT 1 NAME]
// Student ID: [STUDENT 1 ID]
// ============================================================================

// Constructor
PatientQueue::PatientQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

// Destructor
PatientQueue::~PatientQueue() {
    while (!isEmpty()) {
        dischargePatient();
    }
}

// Functionality 1: Admit Patient
void PatientQueue::admitPatient(int id, string name, string conditionType) {
    Patient newPatient(id, name, conditionType);
    Node* newNode = new Node(newPatient);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
    cout << "\n[SUCCESS] Patient admitted successfully!" << endl;
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Condition: " << conditionType << endl;
}

// Functionality 2: Discharge Patient (Remove from front)
void PatientQueue::dischargePatient() {
    if (isEmpty()) {
        cout << "\n[ERROR] No patients in queue to discharge!" << endl;
        return;
    }

    Node* temp = front;
    cout << "\n[DISCHARGE] Discharging patient: " << endl;
    cout << "Patient ID: " << temp->data.id << endl;
    cout << "Name: " << temp->data.name << endl;
    cout << "Condition: " << temp->data.conditionType << endl;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    count--;
    cout << "[SUCCESS] Patient discharged successfully!" << endl;
}

// Functionality 3: View Patient Queue
void PatientQueue::viewPatientQueue() {
    if (isEmpty()) {
        cout << "\n[INFO] No patients in the queue." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       PATIENT QUEUE (FIFO)" << endl;
    cout << "========================================" << endl;
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Condition" << endl;
    cout << "----------------------------------------" << endl;

    Node* current = front;
    int position = 1;
    while (current != nullptr) {
        cout << left << setw(10) << current->data.id
             << setw(20) << current->data.name
             << setw(20) << current->data.conditionType << endl;
        current = current->next;
        position++;
    }
    cout << "----------------------------------------" << endl;
    cout << "Total patients waiting: " << count << endl;
    cout << "========================================" << endl;
}

// Helper: Check if queue is empty
bool PatientQueue::isEmpty() {
    return front == nullptr;
}

// Helper: Get count
int PatientQueue::getCount() {
    return count;
}
