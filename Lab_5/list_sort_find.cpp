#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> numbers = {5, 1, 4, 2, 8};

    //Sort the list
    numbers.sort();

    //Find an element
    auto it = find(numbers.begin(), numbers.end(), 4);

    if (it != numbers.end()) {
        cout << "Found: " << *it << endl;
    } else {
        cout << "Not Found" << endl;
    }

    //Print sorted list
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}