#pragma once
#include <iostream>
#include <string>
using namespace std;

class Evidence {
public:
    int id;
    string type;
    string description;
    string dateCollected;

    Evidence(){
        
    }
    Evidence(int i, string t, string dp, string da){
        id = i;
        type = t;
        description = dp;
        dateCollected = da;
    }

    void display(){
        cout << "ID: " << id
             << " | Type: " << type
             << " | Description: " << description
             << " | Date: " << dateCollected << endl;
    }
};
