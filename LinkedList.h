#pragma once
#include <iostream>
using namespace std;

template <typename T>
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
    void insertEnd(T data) {
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
                temp = temp->next
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
