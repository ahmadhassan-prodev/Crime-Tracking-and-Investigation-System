#include <iostream>
#include "Evidence.h"
#include "LinkedList.h"
#include "Crime.h"
#include "Queue.h"
#include "Suspect.h"
#include "Stack.h"
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

    Stack<Suspect> suspectStack;

    // Add suspects (push)
    suspectStack.push(Suspect(1, "Ali Khan", 32, "Lahore", "Under Investigation"));
    suspectStack.push(Suspect(2, "Bilal Ahmed", 27, "Karachi", "Arrested"));
    suspectStack.push(Suspect(3, "Umar Farooq", 40, "Faisalabad", "Under Surveillance"));

    cout << "\n--- Current Suspect Records ---\n";
    suspectStack.display();

    // Peek at top suspect
    cout << "\n--- Most Recent Suspect ---\n";
    suspectStack.peek();

    // Undo last added suspect
    cout << "\nUndoing last action (removing last suspect)...\n";
    suspectStack.pop();

    cout << "\n--- Updated Suspect Records ---\n";
    suspectStack.display();

    return 0;
}
