#include "HospitalSystem.hpp"

// ============================================================================
// MAIN PROGRAM ENTRY POINT
// ============================================================================

int main() {
    // Create hospital system instance
    HospitalSystem hospital;

    // Optional: Add some initial test data
    cout << "\n[SYSTEM] Initializing Hospital Management System..." << endl;
    cout << "[SYSTEM] Loading initial data..." << endl;

    // Run the main system
    hospital.run();

    return 0;
}
