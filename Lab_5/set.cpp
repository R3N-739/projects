#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> numbers;

    numbers.insert(5);
    numbers.insert(2);
    numbers.insert(8);
    numbers.insert(3);
    numbers.insert(5); //cant add value more than once

    cout << "Set contents:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    //Check if number in set
    int search = 3;
    if (numbers.find(search) != numbers.end()) {
        cout << search << " is in the set." << endl;
    } else {
        cout << search << " is not in the set." << endl;
    }

    //Remove number 2 from set
    numbers.erase(2);

    cout << "Set after removing 2:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}