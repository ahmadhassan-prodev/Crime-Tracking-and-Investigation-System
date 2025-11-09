#include <iostream>
#include "Evidence.h"
#include "LinkedList.h"
#include "Crime.h"
#include "Queue.h"
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

    Queue<Crime> crimeQueue;

    // Add some cases
    crimeQueue.enqueue(Crime(101, "Robbery", "Market Street", "2025-10-14", "Pending"));
    crimeQueue.enqueue(Crime(102, "Murder", "City Center", "2025-10-15", "Pending"));
    crimeQueue.enqueue(Crime(103, "Cyber Fraud", "Online Portal", "2025-10-16", "Pending"));

    cout << "\n--- All Pending Cases ---\n";
    crimeQueue.display();

    // Process the next case
    cout << "\nProcessing next case...\n";
    crimeQueue.dequeue();

    cout << "\n--- Remaining Cases ---\n";
    crimeQueue.display();

    return 0;
}
