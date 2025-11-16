#include "HospitalSystem.hpp"

// ============================================================================
// ROLE 2: MEDICAL SUPPLY MANAGER - STACK IMPLEMENTATION
// Student Name: [STUDENT 2 NAME]
// Student ID: [STUDENT 2 ID]
// ============================================================================

// Constructor
SupplyStack::SupplyStack() {
    top = nullptr;
    count = 0;
}

// Destructor
SupplyStack::~SupplyStack() {
    while (!isEmpty()) {
        useLastAddedSupply();
    }
}

// Functionality 1: Add Supply Stock (Push to stack)
void SupplyStack::addSupplyStock(string type, int quantity, string batch) {
    MedicalSupply newSupply(type, quantity, batch);
    Node* newNode = new Node(newSupply);

    newNode->next = top;
    top = newNode;
    count++;

    cout << "\n[SUCCESS] Supply added to stock!" << endl;
    cout << "Type: " << type << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Batch: " << batch << endl;
}

// Functionality 2: Use Last Added Supply (Pop from stack)
void SupplyStack::useLastAddedSupply() {
    if (isEmpty()) {
        cout << "\n[ERROR] No supplies available in stock!" << endl;
        return;
    }

    Node* temp = top;
    cout << "\n[USAGE] Using last added supply: " << endl;
    cout << "Type: " << temp->data.type << endl;
    cout << "Quantity: " << temp->data.quantity << endl;
    cout << "Batch: " << temp->data.batch << endl;

    top = top->next;
    delete temp;
    count--;

    cout << "[SUCCESS] Supply used successfully!" << endl;
}

// Functionality 3: View Current Supplies
void SupplyStack::viewCurrentSupplies() {
    if (isEmpty()) {
        cout << "\n[INFO] No supplies in stock." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "    MEDICAL SUPPLY INVENTORY (LIFO)" << endl;
    cout << "========================================" << endl;
    cout << left << setw(20) << "Type"
         << setw(12) << "Quantity"
         << setw(15) << "Batch" << endl;
    cout << "----------------------------------------" << endl;

    Node* current = top;
    int position = 1;
    while (current != nullptr) {
        cout << left << setw(20) << current->data.type
             << setw(12) << current->data.quantity
             << setw(15) << current->data.batch << endl;
        current = current->next;
        position++;
    }
    cout << "----------------------------------------" << endl;
    cout << "Total supply items: " << count << endl;
    cout << "========================================" << endl;
}

// Helper: Check if stack is empty
bool SupplyStack::isEmpty() {
    return top == nullptr;
}

// Helper: Get count
int SupplyStack::getCount() {
    return count;
}
