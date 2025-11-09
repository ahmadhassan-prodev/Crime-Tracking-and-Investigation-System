#pragma once
#include <iostream>
#include <string>
using namespace std;

class Suspect {
public:
    int id;
    string name;
    int age;
    string address;
    string status;

    Suspect(int i, string n, int a, string adr, string s){
        id = i;
        name = n;
        age = a;
        address = adr;
        status = s;
    }

    Suspect(){
        
    }

    // Display suspect details
    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Age: " << age
             << " | Address: " << address
             << " | Status: " << status << endl;
    }
};
