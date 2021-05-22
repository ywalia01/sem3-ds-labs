#include <iostream>
#include <stdlib.h>
using namespace std;

int gcd(int dividend, int divisor)
{
    while (divisor != 0)
    {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main(void)
{
    int a, b, gcd;
    cout << "\nEnter 2 numbers: ";
    cin >> a >> b;
    gcd = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: ";
    cout << gcd;
}