#include <cmath>
#include <iostream>
using namespace std;

int main()
{
long long x;
cout<<"cin x : ";
cin>>x;
int n = 0;
long long ans = 0;
do
{
    ans = tgamma(n + 1);
    n++;
} while (ans < x);

cout<<"n : "<<n-1<<endl;

}