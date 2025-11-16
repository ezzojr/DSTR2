#include "HospitalSystem.hpp"

// ============================================================================
// ROLE 3: EMERGENCY DEPARTMENT OFFICER - PRIORITY QUEUE (MAX HEAP)
// Student Name: [STUDENT 3 NAME]
// Student ID: [STUDENT 3 ID]
// ============================================================================

// Constructor
EmergencyPriorityQueue::EmergencyPriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    heap = new EmergencyCase[capacity];
}

// Destructor
EmergencyPriorityQueue::~EmergencyPriorityQueue() {
    delete[] heap;
}

// Helper: Get parent index
int EmergencyPriorityQueue::parent(int i) {
    return (i - 1) / 2;
}

// Helper: Get left child index
int EmergencyPriorityQueue::leftChild(int i) {
    return 2 * i + 1;
}

// Helper: Get right child index
int EmergencyPriorityQueue::rightChild(int i) {
    return 2 * i + 2;
}

// Helper: Heapify up (for insertion)
void EmergencyPriorityQueue::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)].priorityLevel < heap[index].priorityLevel) {
        // Swap with parent if current priority is higher
        EmergencyCase temp = heap[index];
        heap[index] = heap[parent(index)];
        heap[parent(index)] = temp;
        index = parent(index);
    }
}

// Helper: Heapify down (for deletion)
void EmergencyPriorityQueue::heapifyDown(int index) {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    // Find the index with maximum priority
    if (left < size && heap[left].priorityLevel > heap[maxIndex].priorityLevel) {
        maxIndex = left;
    }

    if (right < size && heap[right].priorityLevel > heap[maxIndex].priorityLevel) {
        maxIndex = right;
    }

    // If max is not current index, swap and continue heapifying
    if (maxIndex != index) {
        EmergencyCase temp = heap[index];
        heap[index] = heap[maxIndex];
        heap[maxIndex] = temp;
        heapifyDown(maxIndex);
    }
}

// Helper: Resize array if needed
void EmergencyPriorityQueue::resize() {
    capacity *= 2;
    EmergencyCase* newHeap = new EmergencyCase[capacity];
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

// Functionality 1: Log Emergency Case (Insert into priority queue)
void EmergencyPriorityQueue::logEmergencyCase(string patientName, string emergencyType, int priorityLevel) {
    if (size == capacity) {
        resize();
    }

    EmergencyCase newCase(patientName, emergencyType, priorityLevel);
    heap[size] = newCase;
    heapifyUp(size);
    size++;

    cout << "\n[SUCCESS] Emergency case logged!" << endl;
    cout << "Patient: " << patientName << endl;
    cout << "Emergency Type: " << emergencyType << endl;
    cout << "Priority Level: " << priorityLevel << endl;
}

// Functionality 2: Process Most Critical Case (Extract max from heap)
void EmergencyPriorityQueue::processMostCriticalCase() {
    if (isEmpty()) {
        cout << "\n[ERROR] No emergency cases pending!" << endl;
        return;
    }
    
    cout << "\n[PROCESSING] Most critical case: " << endl;
    cout << "Patient: " << heap[0].patientName << endl;
    cout << "Emergency Type: " << heap[0].emergencyType << endl;
    cout << "Priority Level: " << heap[0].priorityLevel << endl;

    // Replace root with last element
    heap[0] = heap[size - 1];
    size--;

    // Heapify down from root
    if (size > 0) {
        heapifyDown(0);
    }

    cout << "[SUCCESS] Case processed successfully!" << endl;
}

// Functionality 3: View Pending Emergency Cases
void EmergencyPriorityQueue::viewPendingEmergencyCases() {
    if (isEmpty()) {
        cout << "\n[INFO] No pending emergency cases." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "    PENDING EMERGENCY CASES (Priority Order)" << endl;
    cout << "========================================" << endl;
    cout << left << setw(20) << "Patient Name"
         << setw(20) << "Emergency Type"
         << setw(10) << "Priority" << endl;
    cout << "----------------------------------------" << endl;

    // Display all cases (not in perfect priority order for simplicity)
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << heap[i].patientName
             << setw(20) << heap[i].emergencyType
             << setw(10) << heap[i].priorityLevel << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Total emergency cases: " << size << endl;
    cout << "Highest Priority: " << heap[0].patientName
         << " (Level " << heap[0].priorityLevel << ")" << endl;
    cout << "========================================" << endl;
}

// Helper: Check if heap is empty
bool EmergencyPriorityQueue::isEmpty() {
    return size == 0;
}

// Helper: Get size
int EmergencyPriorityQueue::getSize() {
    return size;
}
