#include <iostream>
#include <utility> // for std::pair
#include <string>
using namespace std;

int main() {
    
    // Creating a pair of int and string
    pair<int, string> p0 = {1, "Geeks"};

    cout << p0.first << ": " << p0.second<<endl;
    
    // Creating an empty pair
    pair<int, string> p1;

    // Insert values using curly braces {}
    pair<int, string> p2 = {1, "Geeks"};

    // Insert values using make_pair method
    pair<int, string> p3 = make_pair(2, "ForGeeks");

    cout << p2.first << " " << p2.second << endl;
    cout << p3.first << " " << p3.second;

    // printing result of comparision
    cout << boolalpha;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p3: " << (p1 != p3) << endl;
    cout << "p1 > p3: " << (p1 > p3) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 >= p3: " << (p1 >= p3) << endl;
    cout << "p3 <= p1: " << (p3 <= p1);

    return 0;
}
