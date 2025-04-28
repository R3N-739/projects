#include <iostream>
using namespace std;

int main() 
{
    //Constants and variables
    const int n = 100;    //Index where the summation ends
    const int m = 30;    //Index where the summation starts
    const int c = 100;    //Constant
    long sum = 0;   //Variable to store the sum

    //Display the values of the variables
    cout << "C = " << c << endl;
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;

    //Summation of the series
    for (int i = m; i <= n; i++) 
    {
        sum += c;
    }

    cout << "Summation of the series is: " << sum << endl;
    cout << "c*(n-m+1) = " << c << "*(" << n << "-" << m << "+1) = " << c*(n-m+1) << endl;
    
    return 0;
}