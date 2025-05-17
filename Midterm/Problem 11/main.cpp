#include <iostream>
#include <cmath>
using namespace std;

//Global Constants
const double PI = 3.1415926;
const double EPSILON = 1e-6;

//Function Prototypes
double C(double x);
double S(double x);

//Function Definitions
double C(double x) {
    //Base Case
    if (fabs(x) < EPSILON) {
        return 1.0 / x + x / 6.0;
    }

    //C(2x) using C(x) and S(x)
    double c_half = C(x/2);
    double s_half = S(x/2);
    return (c_half * s_half) / 2.0;
}

double S(double x) {
    //Base Case
    if (fabs(x) < EPSILON) {
        return 1.0 + (x * x) / 2.0;
    }

    //Compute S(2x) using C(x) and S(x)
    double c_half = C(x/2);
    double s_half = S(x/2);
    double numerator = pow(c_half, 2) * pow(s_half, 2);
    double denominator = pow(c_half, 2) - pow(s_half, 2);
    return numerator / denominator;
}

int main() {
    double bound = PI / 4;
    for (double x = -bound; x <= bound; x += 0.1) {
        cout << "x = " << x << ":  C(2x) = " << (C(x) * S(x)) / 2.0;
        cout << ", S(2x) = ";

        double c = C(x);
        double s = S(x);
        double numerator = pow(c, 2) * pow(s, 2);
        double denominator = pow(c, 2) - pow(s, 2);
        double s2x = numerator / denominator;
        cout << s2x << endl;
    }
    return 0;
}
