#include <iostream>
#include <cmath>

using namespace std;

int main () {
    
    unsigned long long ops = 4036608000 * 100;
   unsigned long long n = 0;

    do
    {
        n++;
    } while ((n*n)*log2(n) <= ops);
    
    cout << "n = " << n-1 << endl;
    return 0;
}