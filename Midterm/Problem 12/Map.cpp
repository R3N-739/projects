/* 
 * File:   set.cpp
 * Author: Renzo Di Cristofaro
 */

//Libraries
#include <cstdlib>//Random number seed
#include <set>//Set the seed
#include <iostream>//I/O
#include <map> //Map
using namespace std;

//No Global Constants

//Function Prototypes
map<int,int> fillMap(int,int);
void prntMap(const map<int,int>&,int);
void prntMod(const map<int,int>&);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int size=15;
    int modNum=10;
    map<int,int> list = fillMap(size,modNum);
    
    //Print the initial array
    prntMap(list,modNum);
    
    //Calculate & Print the modal information of the array
    prntMod(list);
    
    //Exit stage right
    return 0;
}

void prntMod(const map<int,int>& m){
    int max=0;
    set<int> modes;

    for (const auto& i : m) {
        if (i.second > max) {
            max = i.second;
            modes.clear();
            modes.insert(i.first);
        } else if (i.second == max) {
            modes.insert(i.first);
        }
    }

    cout<<endl;
    cout<<"The number of modes = "<<modes.size()<<endl;
    cout<<"The max Frequency = "<<max<<endl;
    if(modes.size()==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(auto it = modes.begin(); it != modes.end(); ++it) {
        cout << *it;
        if (next(it) != modes.end()) cout << ",";
    }
    cout << "}" << endl;
}

void prntMap(const map<int, int>& m, int perLine) {
    cout << endl;
    int i = 0;
    for (auto kv : m) {
        for (int j = 0; j < kv.second; ++j) {
            cout << kv.first << " ";
            i++;
            if (i % perLine == 0) cout << endl;//end line when perline is reached
        }
    }
    if (i % perLine != 0) cout << endl;//end line again for future couts
}

map<int,int> fillMap(int n, int modNum){
    //Create map
    map<int,int> m;

    //Fill the map with 2 digit numbers
    for(int i=0;i<n;i++){
        m[rand()%modNum]++;
    }

    //Exit function
    return m;
}