#pragma once
#include <iostream>
#include "Crime.h"
using namespace std;

class PriorityQueue {
private:
    struct Node {
        Crime data;
        Node* next;

        Node(Crime c) {
            data = c;
            next = nullptr;
        }
    };

    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Insert based on priority
    void enqueue(Crime c) {
        Node* newNode = new Node(c);

        // If empty OR higher priority than front
        if (!front || c.priority < front->data.priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next &&
                   temp->next->data.priority <= c.priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Remove highest priority crime
    bool dequeue(Crime &removedCrime) {
        if (!front) {
            cout << "No crime to investigate.\n";
            return false;
        }

        Node* temp = front;
        removedCrime = front->data;
        front = front->next;
        delete temp;
        return true;
    }

    // View highest priority crime
    bool peek(Crime &topCrime) const {
        if (!front) {
            cout << "No crime available.\n";
            return false;
        }
        topCrime = front->data;
        return true;
    }

    bool removeById(int crimeID) {
        if (!front) return false;

        if (front->data.caseID == crimeID) {
            Node* temp = front;
            front = front->next;
            delete temp;
            return true;
        }

        Node* prev = front;
        Node* curr = front->next;

        while (curr) {
            if (curr->data.caseID == crimeID) {
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void display() const {
        if (!front) {
            cout << "No crimes in priority queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Crimes by Priority (High → Low):\n";
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};
