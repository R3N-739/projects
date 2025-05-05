#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct Link
{
    Link(T d) : data(d), next(nullptr) {} //initializing contructor
    Link* next; //pointer to next link
    T data;   //data for link
};

template <typename T>
class LinkedList 
{
private:
Link<T>* head; //head of the list
Link<T>* tail; //tail of the list

//for destructor
void dstryLst() {
    Link<T>* temp = head;  //to store the next value
    Link<T>* kill = head;  //to be deleted next
    while (temp != nullptr) {
        temp = temp->next;  //save next value
        delete kill;    //delete current
        kill = temp;    //prepare next to delete
    }
}
public:
    //Constructor
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }
    //Destructor
    ~LinkedList() {
        dstryLst();
    }
    //getters
    Link<T>* getHead() { return head; } //get head of list
    Link<T>* getTail() { return tail; } //get tail of list
    //Add to front of list
    void push_front(Link<T>* node) 
    {
        if (head == nullptr) { //if list is empty
            head = node;
            tail = node;
            tail->next = nullptr;
        } else {            //if list is not empty
            node->next = head;
            head = node;
        }
    }
    //Add to back of list
    void push_back(Link<T>* node) 
    {
        if (tail == nullptr) {  //if list is empty
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
    Link<T>* pop_front() 
    {   
        //if list is empty
        if (head == nullptr) return nullptr;

        Link<T>* temp = head;  //store the next value
        head = head->next;  //move head to next link

        //if list had only one element reset tail
        if (head == nullptr) tail = nullptr;

        temp->next = nullptr; //clear pointer to next link
        return temp;
    }
    //Remove from back of list
    Link<T>* pop_back() 
    {   
        //if list is empty
        if (tail == nullptr) return nullptr;
        //if list has only one element
        if (head == tail) {
            Link<T>* temp = head;
            head = nullptr;
            tail = nullptr;
            return temp;
        }
        //if list has more than one element
        Link<T>* temp = head;
        while (temp->next != tail) temp = temp->next; //loop to the second last
        tail = temp;//set second last as tail
        temp = tail->next; //store the last link
        tail->next = nullptr;   //clear tail pointer
        return temp;
    }
    //Print the list
    void printlist() 
    {
        //Check if the list is empty
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        //Loop to print all data
        Link<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        } cout << endl;
    }
};
#endif