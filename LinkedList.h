#pragma once
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
        Node(T d){
            data = d;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    // Add new item at end
    void insertAtEnd(T data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete an item by ID
    void deleteById(int id) {
        if (!head){
            cout<<"There is not evidence in record"<<endl;
        }
        else if(head->data.id == id){
            Node* del = head;
            head = head->next;
            delete del;
            cout<<"Evidence is deleted successfully"<<endl;
        }
        else{
            Node* temp = head;
            Node* prev = nullptr;
            bool found = false;
            while(temp){
                if(temp->data.id==id){
                    found = true;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }

            if(found){
                prev->next = temp->next;
                if(temp==tail){
                    tail = prev;
                }
            }
            else{
                cout<<"Evidence not found!"<<endl;
            }
        }
    }

    bool removeById(int evidenceID) {
        if (!head) return false;

        if (head->data.id == evidenceID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr) {
            if (curr->data.id == evidenceID) {
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    // Display all items
    void displayAll(){
        Node* temp = head;
        if (!temp) {
            cout << "No evidence found!\n";
            return;
        }
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
    }
};
