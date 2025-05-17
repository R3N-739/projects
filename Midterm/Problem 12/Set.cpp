/* 
 * File:   set.cpp
 * Author: Renzo Di Cristofaro
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set> //Set
using namespace std;

//No Global Constants

//Function Prototypes
multiset<int> fillSet(int,int);
void prntSet(const multiset<int>&,int);
void prntMod(const multiset<int>&);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int size=15;
    int modNum=10;
    multiset<int> list = fillSet(size,modNum);
    
    //Print the initial array
    prntSet(list,modNum);
    
    //Calculate & Print the modal information of the array
    prntMod(list);
    
    //Exit stage right
    return 0;
}

void prntMod(const multiset<int>& ms){
    int maxFreq=0;
    set<int> modes;

    for (int i:ms){
        int freq = ms.count(i);
        if (freq > maxFreq) {
            maxFreq = freq;
            modes.clear();//Reset the set to hold only the new mode values
            modes.insert(i);
        } else if (freq == maxFreq) {
            modes.insert(i);
        }
    }

    cout<<endl;
    cout<<"The number of modes = "<<modes.size()<<endl;
    cout<<"The max Frequency = "<<maxFreq<<endl;
    if(modes.size()==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    //use iterator to print the set to not print the last comma
    for(auto it = modes.begin(); it != modes.end(); ++it) {
        cout << *it;
        if (next(it) != modes.end()) cout << ",";//If not the last element, print comma
    }
    cout << "}" << endl;
}

void prntSet(const multiset<int>& ms,int perLine){
    //Output the multiset
    cout<<endl;
    int i = 0;
    for(int value : ms){
        cout<<value<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
        i++;
    }
    cout<<endl;
}

multiset<int> fillSet(int n, int modNum){
    //Create multiset
    multiset<int> ms;

    //Fill the multiset with 2 digit numbers
    for(int i=0;i<n;i++){
        ms.insert(rand()%modNum);
    }
    
    //Exit function
    return ms;
}