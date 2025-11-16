#include "HospitalSystem.hpp"

// ============================================================================
// MAIN HOSPITAL SYSTEM INTEGRATION
// ============================================================================

// Constructor
HospitalSystem::HospitalSystem() {
    // Initialize all subsystems
}

// Display Main Menu
void HospitalSystem::displayMainMenu() {
    cout << "\n============================================" << endl;
    cout << "   HOSPITAL PATIENT CARE MANAGEMENT SYSTEM" << endl;
    cout << "============================================" << endl;
    cout << "1. Patient Admission Clerk" << endl;
    cout << "2. Medical Supply Manager" << endl;
    cout << "3. Emergency Department Officer" << endl;
    cout << "4. Ambulance Dispatcher" << endl;
    cout << "5. Exit System" << endl;
    cout << "============================================" << endl;
    cout << "Enter your choice: ";
}

// Handle Patient Admission Menu
void HospitalSystem::handlePatientAdmissionMenu() {
    int choice;
    do {
        cout << "\n========================================" << endl;
        cout << "     PATIENT ADMISSION CLERK MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Admit Patient" << endl;
        cout << "2. Discharge Patient" << endl;
        cout << "3. View Patient Queue" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, condition;
                cout << "\nEnter Patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Patient Name: ";
                getline(cin, name);
                cout << "Enter Condition Type: ";
                getline(cin, condition);
                patientQueue.admitPatient(id, name, condition);
                break;
            }
            case 2:
                patientQueue.dischargePatient();
                break;
            case 3:
                patientQueue.viewPatientQueue();
                break;
            case 4:
                cout << "\nReturning to main menu..." << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

// Handle Medical Supply Menu
void HospitalSystem::handleMedicalSupplyMenu() {
    int choice;
    do {
        cout << "\n========================================" << endl;
        cout << "     MEDICAL SUPPLY MANAGER MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Add Supply Stock" << endl;
        cout << "2. Use Last Added Supply" << endl;
        cout << "3. View Current Supplies" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string type, batch;
                int quantity;
                cin.ignore();
                cout << "\nEnter Supply Type: ";
                getline(cin, type);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cin.ignore();
                cout << "Enter Batch Number: ";
                getline(cin, batch);
                supplyStack.addSupplyStock(type, quantity, batch);
                break;
            }
            case 2:
                supplyStack.useLastAddedSupply();
                break;
            case 3:
                supplyStack.viewCurrentSupplies();
                break;
            case 4:
                cout << "\nReturning to main menu..." << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

// Handle Emergency Department Menu
void HospitalSystem::handleEmergencyDepartmentMenu() {
    int choice;
    do {
        cout << "\n========================================" << endl;
        cout << "   EMERGENCY DEPARTMENT OFFICER MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Log Emergency Case" << endl;
        cout << "2. Process Most Critical Case" << endl;
        cout << "3. View Pending Emergency Cases" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, emergencyType;
                int priority;
                cin.ignore();
                cout << "\nEnter Patient Name: ";
                getline(cin, name);
                cout << "Enter Emergency Type: ";
                getline(cin, emergencyType);
                cout << "Enter Priority Level (1-10, higher = more critical): ";
                cin >> priority;
                emergencyQueue.logEmergencyCase(name, emergencyType, priority);
                break;
            }
            case 2:
                emergencyQueue.processMostCriticalCase();
                break;
            case 3:
                emergencyQueue.viewPendingEmergencyCases();
                break;
            case 4:
                cout << "\nReturning to main menu..." << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

// Handle Ambulance Dispatch Menu
void HospitalSystem::handleAmbulanceDispatchMenu() {
    int choice;
    do {
        cout << "\n========================================" << endl;
        cout << "       AMBULANCE DISPATCHER MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Register Ambulance" << endl;
        cout << "2. Rotate Ambulance Shift" << endl;
        cout << "3. Display Ambulance Schedule" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string vehicleID, driverName;
                cin.ignore();
                cout << "\nEnter Vehicle ID: ";
                getline(cin, vehicleID);
                cout << "Enter Driver Name: ";
                getline(cin, driverName);
                ambulanceQueue.registerAmbulance(vehicleID, driverName);
                break;
            }
            case 2:
                ambulanceQueue.rotateAmbulanceShift();
                break;
            case 3:
                ambulanceQueue.displayAmbulanceSchedule();
                break;
            case 4:
                cout << "\nReturning to main menu..." << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

// Main System Run Loop
void HospitalSystem::run() {
    int choice;

    cout << "\n*" << endl;
    cout << "   WELCOME TO HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "*" << endl;

    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                handlePatientAdmissionMenu();
                break;
            case 2:
                handleMedicalSupplyMenu();
                break;
            case 3:
                handleEmergencyDepartmentMenu();
                break;
            case 4:
                handleAmbulanceDispatchMenu();
                break;
            case 5:
                cout << "\n*" << endl;
                cout << "   Thank you for using the Hospital System!" << endl;
                cout << "   Exiting program..." << endl;
                cout << "*" << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please enter 1-5." << endl;
        }
    } while (choice != 5);
}
