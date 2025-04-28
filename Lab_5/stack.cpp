#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> browserHistory;

    //Visit websites
    browserHistory.push("google.com");
    browserHistory.push("stackoverflow.com");
    browserHistory.push("github.com");

    cout << "Current page: " << browserHistory.top() << endl;

    //Go back in web history
    cout << "Going back from: " << browserHistory.top() << endl;
    browserHistory.pop();

    cout << "Now at: " << browserHistory.top() << endl;

    //back again
    cout << "Going back from: " << browserHistory.top() << endl;
    browserHistory.pop();

    if (!browserHistory.empty()) {
        cout << "Now at: " << browserHistory.top() << endl;
    } else {
        cout << "No more history." << endl;
    }

    return 0;
}