#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> line;

    //adding people to the queue
    line.push("Alice");
    line.push("Bob");
    line.push("Charlie");

    cout << "People in line:" << endl;
    queue<string> temp = line; //copy to display without changing the original
    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }

    cout << endl;

    //Serve first in line
    if (!line.empty()) {
        cout << "Serving: " << line.front() << endl;
        line.pop();
    }

    //Serve first in line again
    if (!line.empty()) {
        cout << "Serving: " << line.front() << endl;
        line.pop();
    }

    //Print whos left in line
    cout << endl << "People still in line:" << endl;
    while (!line.empty()) {
        cout << line.front() << endl;
        line.pop();
    }

    return 0;
}