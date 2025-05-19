/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Your includes
#include "Object.h"
#include "SimpleVector.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random numbers once

    for (int n = 10; n <= 200; n += 10) {
        SimpleVector<Object> sv;

        auto start = high_resolution_clock::now();

        for (int i = 0; i < n; i++) {
            int rSize = rand() % 10 + 2;  // Object size at least 2
            Object o(rSize);
            sv.push(o);
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();

        cout << "n = " << n
             << " | Time = " << duration << " μs"
             << " | Operations = " << sv.getOperationCount()
             << endl;
    }

    return 0;
}
