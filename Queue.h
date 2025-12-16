#pragma once
#include <iostream>
#include "Crime.h"
using namespace std;

// template <class T>
class Queue {
public:
    struct Node {
        Crime data;
        Node* next;
        Node(Crime d){
            data = d;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a new case to the queue
    void enqueue(Crime data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Process next case
    void dequeue() {
        if (front == nullptr) {
            cout << "No pending cases.\n";
        }
        else if(front==rear){
            front = rear = nullptr;
        }
        else{
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        
    }

    Crime* search(int crimeID) {
        Node* temp = front;
        while (temp) {
            if (temp->data.caseID == crimeID) {
                return &(temp->data);
            }
            temp = temp->next;
        }
        return nullptr;
    }

    bool removeRear() {
        if (!front) return false;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return true;
        }

        Node* temp = front;
        while (temp->next != rear) temp = temp->next;
        delete rear;
        rear = temp;
        rear->next = nullptr;
        return true;
    }


    // Display all pending cases
    void display() const {
        if (!front) {
            cout << "No pending cases.\n";
        }
        else{
            Node* temp = front;
            cout << "Pending Crime Cases:\n";
            while (temp) {
                temp->data.display();
                temp = temp->next;
            }
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};
