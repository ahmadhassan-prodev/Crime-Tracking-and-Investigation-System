#include <iostream>
using namespace std;

#include "Crime.h"
#include "Evidence.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "AVL.h"
#include "Stack.h"
#include "Action.h"

// ---------- UNDO FUNCTION ----------
void undo(Stack<Action>& undoStack,
          Stack<Action>& redoStack,
          Queue& crimeQueue,
          PriorityQueue& crimePQ,
          AVL& suspectTree)
{
    Action act;

    if (!undoStack.pop(act)) {
        cout << "Nothing to undo.\n";
        return;
    }

    switch (act.type) {

    case ADD_CRIME:
        // Remove crime using stored object
        crimeQueue.removeRear();
        crimePQ.removeById(act.crimeData.caseID);
        break;

    case DELETE_CRIME:
        // Restore deleted crime
        crimeQueue.enqueue(act.crimeData);
        crimePQ.enqueue(act.crimeData);
        break;

    case ADD_SUSPECT:
        suspectTree.deleteSuspect(act.suspectData.id);
        break;

    case DELETE_SUSPECT:
        suspectTree.root =
            suspectTree.insert(suspectTree.root, act.suspectData);
        break;

    case ADD_EVIDENCE: {
        Crime* c = crimeQueue.search(act.relatedCrimeID);
        if (c) {
            c->evidenceList.removeById(act.evidenceData.id);
        }
        break;
    }

    case DELETE_EVIDENCE: {
        Crime* c = crimeQueue.search(act.relatedCrimeID);
        if (c) {
            c->evidenceList.insertAtEnd(act.evidenceData);
        }
        break;
    }

    default:
        break;
    }

    redoStack.push(act);
    cout << "Undo successful.\n";
}


// ---------- REDO FUNCTION ----------
void redo(Stack<Action>& undoStack,
          Stack<Action>& redoStack,
          Queue& crimeQueue,
          PriorityQueue& crimePQ,
          AVL& suspectTree)
{
    Action act;

    if (!redoStack.pop(act)) {
        cout << "Nothing to redo.\n";
        return;
    }

    switch (act.type) {

    case ADD_CRIME:
        crimeQueue.enqueue(act.crimeData);
        crimePQ.enqueue(act.crimeData);
        break;

    case DELETE_CRIME:
        crimeQueue.removeRear();
        crimePQ.removeById(act.crimeData.caseID);
        break;

    case ADD_SUSPECT:
        suspectTree.root =
            suspectTree.insert(suspectTree.root, act.suspectData);
        break;

    case DELETE_SUSPECT:
        suspectTree.deleteSuspect(act.suspectData.id);
        break;

    case ADD_EVIDENCE: {
        Crime* c = crimeQueue.search(act.relatedCrimeID);
        if (c) {
            c->evidenceList.insertAtEnd(act.evidenceData);
        }
        break;
    }

    case DELETE_EVIDENCE: {
        Crime* c = crimeQueue.search(act.relatedCrimeID);
        if (c) {
            c->evidenceList.removeById(act.evidenceData.id);
        }
        break;
    }

    default:
        break;
    }

    undoStack.push(act);
    cout << "Redo successful.\n";
}


// ---------- MAIN ----------
int main() {

    Queue crimeQueue;
    PriorityQueue crimePQ;
    AVL suspectTree;

    Stack<Action> undoStack;
    Stack<Action> redoStack;

    int choice;

    do {
        cout << "\n===== Crime Tracking & Investigation System =====\n";
        cout << "1. Register Crime\n";
        cout << "2. Display All Crimes\n";
        cout << "3. Investigate Crime\n";
        cout << "4. Add Evidence to Crime\n";
        cout << "5. Display Evidence of a Crime\n";
        cout << "6. Add Suspect\n";
        cout << "7. Search Suspect\n";
        cout << "8. Display All Suspects\n";
        cout << "9. Undo\n";
        cout << "10. Redo\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        // ----- REGISTER CRIME -----
        case 1: {
            int id, priority;
            string type, loc, date, status;

            cout << "Enter Case ID: ";
            cin >> id;
            cout << "Enter Type: ";
            cin >> type;
            cout << "Enter Location: ";
            cin >> loc;
            cout << "Enter Date: ";
            cin >> date;
            cout << "Enter Status: ";
            cin >> status;
            cout << "Enter Priority (1-High 2-Medium 3-Low): ";
            cin >> priority;

            Crime c(id, type, loc, date, status, priority);

            crimeQueue.enqueue(c);
            crimePQ.enqueue(c);

            undoStack.push(Action(ADD_CRIME, c));
            redoStack = Stack<Action>();

            cout << "Crime registered successfully.\n";
            break;
        }

        // ----- DISPLAY CRIMES -----
        case 2:
            crimeQueue.display();
            break;

        // ----- INVESTIGATE CRIME -----
        case 3: {
            Crime c;
            if(crimePQ.dequeue(c)){
                c.status = "Investigated";
                cout << "Investigating Crime:\n";
                c.display();
            }
            break;
        }

        // ----- ADD EVIDENCE -----
        case 4: {
            int cid, eid;
            string desc, type, date;

            cout << "Enter Crime ID: ";
            cin >> cid;

            Crime* c = crimeQueue.search(cid);
            if (!c) {
                cout << "Crime not found!\n";
                break;
            }

            cout << "Enter Evidence ID: ";
            cin >> eid;
            cout << "Enter Evidence type: ";
            cin >> type;
            cout << "Enter Description: ";
            cin >> desc;
            cout << "Enter Date Collected: ";
            cin >> date;

            Evidence e(eid,type, desc,date);
            c->evidenceList.insertAtEnd(e);

            undoStack.push(Action(ADD_EVIDENCE, e, cid));
            redoStack = Stack<Action>();

            cout << "Evidence added successfully.\n";
            break;
        }

        // ----- DISPLAY EVIDENCE -----
        case 5: {
            int cid;
            cout << "Enter Crime ID: ";
            cin >> cid;

            Crime* c = crimeQueue.search(cid);
            if (!c) {
                cout << "Crime not found!\n";
                break;
            }

            c->evidenceList.displayAll();
            break;
        }

        // ----- ADD SUSPECT -----
        case 6: {
            int sid,age;
            string name,address,status;

            cout << "Enter Suspect ID: ";
            cin >> sid;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter Status: ";
            cin >> status;

            Suspect s(sid, name, age, address, status);
            suspectTree.root = suspectTree.insert(suspectTree.root, s);

            undoStack.push(Action(ADD_SUSPECT, s));
            redoStack = Stack<Action>();

            cout << "Suspect added.\n";
            break;
        }

        // ----- SEARCH SUSPECT -----
        case 7: {
            int sid;
            cout << "Enter Suspect ID: ";
            cin >> sid;

            auto res = suspectTree.search(sid);
            if (res)
                res->data.display();
        }

        // ----- DISPLAY SUSPECTS -----
        case 8:
            if(suspectTree.root){
                suspectTree.inorder_traversal(suspectTree.root);
            }
            else{
                cout<<"No Suspect to Display!"<<endl;
            }
            break;

        // ----- UNDO -----
        case 9:
            undo(undoStack, redoStack, crimeQueue, crimePQ, suspectTree);
            break;

        // ----- REDO -----
        case 10:
            redo(undoStack, redoStack, crimeQueue, crimePQ, suspectTree);
            break;

        case 0:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
