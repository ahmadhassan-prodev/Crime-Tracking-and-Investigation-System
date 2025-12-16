#pragma once
#include "LinkedList.h"
#include "Evidence.h"
#include <iostream>
#include <string>
using namespace std;

class Crime {
public:
    int caseID;
    string type;
    string location;
    string dateReported;
    string status;
    int priority;   
    Crime() {}
    
    LinkedList<Evidence> evidenceList;

    Crime(int id, string t, string loc, string d, string s, int p)
    {
        caseID = id;
        type = t;
        location = loc;
        dateReported = d;
        status = s;
        priority = p;
    }

    void display() const {
        cout << "Case ID: " << caseID
             << " | Type: " << type
             << " | Location: " << location
             << " | Date: " << dateReported
             << " | Status: " << status
             << " | Priority: " << priority
             << endl;
    }
};
