#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

struct Link {
    Link(int d) : data(d) {} //initializing contructor
    Link* next; //pointer to next link
    int data;   //data for link
};

class linkedList {
public:
    //Constructor
    linkedList() 
    {
        head->next = nullptr;
        tail = nullptr;
    }
    //Destructor
    ~linkedList() {
        dstryLst();
    }
    //Add to front of list
    void push_front(Link* node) 
    {
        if (head == nullptr) {
            head = node;
            tail = node;
            tail->next = nullptr;
        } else {
            node->next = head;
            head = node;
        }
    }
    //Add to back of list
    void push_back(Link* node) 
    {
        if (tail == nullptr) {
            tail = node;
            head = node;
            tail->next = nullptr;
        } else {
            tail->next = node;
            tail = node;    
            node->next = nullptr;
        }
    }
    //Remove from front of list
    Link* pop_front() 
    {
        if (head == nullptr) return nullptr;
        Link* temp = head;
        head = head->next;
        return nullptr;
    }
    //Remove from back of list
    Link* pop_back() 
    {
        if (tail == nullptr) return nullptr;
        Link* temp = head;
        while (temp->next != tail) temp = temp->next;
        tail = temp;
        Link* ret = tail->next;
        tail->next = nullptr;
        return ret;
    }
    //Print the list
    void printlist() 
    {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Link* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        } cout << endl;
    }

private:
    Link* head; //head of the list
    Link* tail; //tail of the list

    //for destructor
    void dstryLst() {
        Link* temp = head;  //to store the next value
        Link* kill = head;  //to be deleted next
        while (temp != nullptr) {
            temp = temp->next;  //save next value
            delete kill;    //delete current
            kill = temp;    //prepare next to delete
        }
    }
};
#endif