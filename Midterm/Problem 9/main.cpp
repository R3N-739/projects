#include <iostream>
using namespace std;

//O(n)
double On(double x, int n) {
    //base
    if (n == 0) return 1;
    //recursive
    return x * On(x, n - 1);
}

//O(log n)
double Ologn(double x, int n) {
    //base
    if (n == 0) return 1;
    //recursive
    double half = Ologn(x, n / 2);
    //if n is even else odd
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main() {
    double x = -2.0;
    cout << "O(n) and O(log n) for x = " << x << endl;
    //Loop through 10 int n values
    for (int n = 0; n <= 10; n++) {
        cout << "n = " << n
             << " : O(n) = " << On(x, n)
             << " : O(log n) = " << Ologn(x, n)
             << endl;
    }
    return 0;
}