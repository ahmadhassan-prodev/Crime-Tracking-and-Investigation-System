#include <iostream>
#include "Evidence.h"
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<Evidence> evidenceList;

    // Add some evidence
    evidenceList.insertEnd(Evidence(1, "CCTV", "Footage from market street", "2025-10-10"));
    evidenceList.insertEnd(Evidence(2, "Fingerprint", "Door handle prints", "2025-10-12"));
    evidenceList.insertEnd(Evidence(3, "Weapon", "Knife found at scene", "2025-10-13"));

    cout << "All evidence:\n";
    evidenceList.displayAll();

    // Delete evidence
    int delID;
    cout << "\nEnter evidence ID to delete: ";
    cin >> delID;
    evidenceList.deleteById(delID);
    
    cout << "\nUpdated list:\n";
    evidenceList.displayAll();

    return 0;
}
