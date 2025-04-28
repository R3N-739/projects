#include <iostream>
#include <vector>
#include <algorithm>
#include <random>  //shuffle

using namespace std;

int main() {
    vector<int> scores = {85, 92, 78, 90, 88, 76, 95};

    cout << "Original scores: ";
    for (int i : scores) {
        cout << i << " ";
    }
    cout << endl;

    //Shuffle scores
    random_device rd;
    mt19937 g(rd());
    shuffle(scores.begin(), scores.end(), g);

    cout << "Shuffled scores: ";
    for (int i : scores) {
        cout << i << " ";
    }
    cout << endl;

    //Sort the scores
    sort(scores.begin(), scores.end());

    cout << "Sorted scores: ";
    for (int i : scores) {
        cout << i << " ";
    }
    cout << endl;

    //Find min and max scores
    auto minIt = min_element(scores.begin(), scores.end());
    auto maxIt = max_element(scores.begin(), scores.end());

    if (minIt != scores.end() && maxIt != scores.end()) {
        cout << "Lowest score: " << *minIt << endl;
        cout << "Highest score: " << *maxIt << endl;
    }

    return 0;
}