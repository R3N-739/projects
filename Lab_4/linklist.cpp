
#include "LinkedList.h"

int main() {
    linkedList* renzo = new linkedList();
    // add one to front
    Link* first = new Link(1);
    renzo->push_front(first);
    renzo->printlist();
    // add two to end
    Link* second = new Link(2);
    renzo->push_back(second);
    renzo->printlist();

    Link* third = new Link(3);
    renzo->push_back(third);
    renzo->printlist();

    Link* popped = renzo->pop_back();
    renzo->printlist();

    popped = renzo->pop_front();
    renzo->printlist();

    popped = renzo->pop_front();
    renzo->printlist();
    
    return 0;
}