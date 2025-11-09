#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d){
            data = d;
            next = nullptr;
        }
    };

    Node* top;
public:
    Stack(){
        top = nullptr;
    }

    // Add new item
    void push(T data) {
        Node* newNode = new Node(data);
        if(!top){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    // Remove the last added item
    void pop() {
        if (!top) {
            cout << "Stack is empty. Nothing to undo.\n";
        }
        else{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // View top item (PEEK)
    void peek() const {
        if (!top) {
            cout << "Stack is empty.\n";
        }
        else{
            cout << "Most recent suspect:\n";
            top->data.display();
        }
    }

    // Display all suspects
    void display() const {
        if (!top) {
            cout << "No suspects in record.\n";
        }
        else{
            Node* temp = top;
            cout << "Current Suspect Stack (Top to Bottom):\n";
            while (temp) {
                temp->data.display();
                temp = temp->next;
            }
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};
