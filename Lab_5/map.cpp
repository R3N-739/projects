#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> data;

    //create pairs
    data[3] = 15;
    data[1] = 10;
    data[4] = 20;
    data[2] = 12;

    cout << "Map contents:" << endl;
    for (const auto& entry : data) 
    {
        cout << entry.first << " -> " << entry.second << endl;
    }

    //Find key 2
    int key = 2;
    if (data.find(key) != data.end()) 
    {
        cout << "Found key " << key << " with value " << data[key] << endl;
    } else 
    {
        cout << "Key " << key << " not found." << endl;
    }

    //Remove key 3
    data.erase(3);

    cout << "Removed key 3:" << endl;
    for (const auto& entry : data) 
    {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}