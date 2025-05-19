/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes
#include "LinkedList.h"   //Linked List

int main() {
    srand(static_cast<unsigned int>(time(0)));

    for (int n = 10; n <= 200; n += 10) {
        // Step 1: Create an initial Object and initialize the SimpleVector
        Object first(rand() % 10 + 2);
        SimpleVector<Object> sv(first);  // Uses the const T& constructor

        // Step 2: Start timing after the first object
        auto start = high_resolution_clock::now();

        for (int i = 1; i < n; i++) {  // Start from 1 because 1st object already pushed
            Object obj(rand() % 10 + 2);
            sv.push(obj);
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();

        // Step 3: Output n, time, and operation count
        cout << "n = " << n
             << " | Time = " << duration << " μs"
             << " | Operations = " << sv.getOperationCount()
             << endl;
    }

    return 0;
}