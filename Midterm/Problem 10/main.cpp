#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Global Constants
const double eps = 1e-6;

//Function
double g(double x) 
{
    //Base Case
    if (fabs(x) < eps) {
        return (x - (pow(x,3) / 6.0));
    }

    //Recursive Case
    double half = g(x / 2);
    return (2*half/(1 + pow(half, 2)));
}

int main() {;
    for (double x = -1.0; x <= 1.0; x += 0.1) {
        cout << "x = " << fixed << setprecision(1) << x;
        cout << ":  g(2x) = " << setprecision(6) << g(2 * x) << endl;
    }
    return 0;
}