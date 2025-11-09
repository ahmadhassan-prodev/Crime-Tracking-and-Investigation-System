#pragma once
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

    Crime(){

    }

    Crime(int id, string t, string loc, string d, string s)
    {
        caseID = id;
        type = t;
        location = loc;
        dateReported = d;
        status = s;
    }

    // Display case info
    void display() const {
        cout << "Case ID: " << caseID
             << " | Type: " << type
             << " | Location: " << location
             << " | Date: " << dateReported
             << " | Status: " << status << endl;
    }
};
