#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<string> tasks;

    //add tasks
    tasks.push_back("Finish homework");
    tasks.push_back("Clean room");
    tasks.push_back("Go for a run");

    //add task to front
    tasks.push_front("Call mom");

    //print task list
    cout << "Task list:" << endl;
    for (const string& task : tasks) {
        cout << "- " << task << endl;
    }

    //pop first
    cout << endl << "Completing task: " << tasks.front() << endl;
    tasks.pop_front();

    //pop last
    cout << "Completing task: " << tasks.back() << endl;
    tasks.pop_back();

    cout << endl << "Remaining tasks:" << endl;
    for (const string& task : tasks) {
        cout << "- " << task << endl;
    }

    return 0;
}