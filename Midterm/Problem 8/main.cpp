#include <iostream>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for time
#include <cmath>    // for pow
using namespace std;

int main() {

    const double prob = 0.4; //probability of filling a bit
    const long trials = 10000000; //number of trials
    srand(time(0)); //Random seed

    //Success counter
    float successCount = 0;

    //Loop through trials
    for (int t = 0; t < trials; t++) {
        
        bool allFilled = true;

        for (int i = 0; i < 5; ++i) {
            //random number from 0 to 1
            float r = static_cast<float>(rand()) / RAND_MAX;    //Divide by max to get float between 0 and 1

            //if random number is greater than prob, then not all bits are filled
            if (r >= prob) {
                allFilled = false;
                break;
            }
        }

        if (allFilled) successCount++;
    }

    double simulated = successCount / trials * 100.0;
    
    double theoretical = pow(prob, 5) * 100.0;  //0.4^5 * 100 = 1.024%

    cout << "Simulated Probability: " << simulated << "%" << endl;
    cout << "Theoretical Probability: " << theoretical << "%" << endl;

    return 0;
}
