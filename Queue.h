#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue {
public:
    struct Node {
        T data;
        Node* next;
        Node(T d){
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
    void enqueue(T data) {
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
