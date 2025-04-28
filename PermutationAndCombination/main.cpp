#include <iostream>
#include <iomanip>
using namespace std;

//factorial
unsigned long long factorial(int n) {
    //special cases
    if (n == 0 || n == 1) return 1;

    //factoriaL
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {

    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<"  N  M                    P Rep                   P no Rep                 C Rep                  C no Rep"<<endl;
    cout<<"                            N^M                   N!/(N-M)!          (N+M-1)!/((N-1)!M!)         N!/((N-M)!M!)"<<endl<<endl;

    
    for (int n = 2; n <= 26; ++n) {
        for (int m = 0; m <= n; ++m) {
            unsigned long long permRep = 1;
            for (int i = 0; i < m; ++i) {
                permRep *= n;
            }

            unsigned long long perm = 0;
            if (n >= m) {
                perm = factorial(n) / factorial(n - m);
            }

            unsigned long long combRep = 0;
            if (n > 0) {
                combRep = factorial(n + m - 1) / (factorial(n - 1) * factorial(m));
            }

            unsigned long long comb = 0;
            if (n >= m) {
                comb = factorial(n) / (factorial(n - m) * factorial(m));
            }

            cout << setw(3) << n << setw(3) << m
                 << setw(24) << permRep
                 << setw(24) << perm
                 << setw(24) << combRep
                 << setw(24) << comb << endl;
        }
    }

    return 0;
}
