#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;


int Hand() {
    int hand[4];

    //Create 4 random cards with values from 1 to 13
    for (int i = 0; i < 4; i++) {
        hand[i] = rand() % 13 + 1; // values from 1 to 13
    }

    //Count frequencies
    map<int, int> freq;
    for (int i = 0; i < 4; i++) {
        freq[hand[i]]++;  
    }

    //Count how often a frequency occurs
    map<int, int> countFreq;
    for (auto entry : freq) {
        countFreq[entry.second]++;
    }

    //Return correct type of hand
    if (countFreq[4] == 1) return 4;
    if (countFreq[3] == 1) return 3;
    if (countFreq[2] == 2) return 2;
    if (countFreq[2] == 1) return 1;
    return 0;//If no good hands
}

int main() {
    //Seed
    srand(time(0));

    //Trial count
    const long trials = 1000000;

    //Store statistics from trials
    float onePair = 0, twoPair = 0, threeKind = 0, fourKind = 0, noPair = 0;

    //Loop through trials and count hand stats
    for (int i = 0; i < trials; ++i) {
        int x = Hand();
        if (x == 1) onePair++;
        else if (x == 2) twoPair++;
        else if (x == 3) threeKind++;
        else if (x == 4) fourKind++;
        else noPair++;
    }

    //Output results in percentage
    cout << "Results from " << trials << " trials:" << endl;
    cout << "none: " << (100.0 * noPair / trials) << "%" << endl;
    cout << "1 pair: " << (100.0 * onePair / trials) << "%" << endl;
    cout << "2 pairs: " << (100.0 * twoPair / trials) << "%" << endl;
    cout << "3 of a kind: " << (100.0 * threeKind / trials) << "%" << endl;
    cout << "4 of a kind: " << (100.0 * fourKind / trials) << "%" << endl;

    return 0;
}
