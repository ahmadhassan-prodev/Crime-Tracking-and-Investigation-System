#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(T d) {
            data = d;
            next = nullptr;
        }
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // PUSH
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

    // POP (returns removed item)
    bool pop(T &removedData) {
        if (!top) {
            cout << "Stack is empty.\n";
            return false;
        }

        Node* temp = top;
        removedData = top->data;
        top = top->next;
        delete temp;
        return true;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};
