#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        int s = (A + B + C) / 2;
        int r_squared = (s - A) * (s - B) * (s - C) / s;

        // Reduce the fraction
        int gcd = __gcd(r_squared, s);
        r_squared /= gcd;
        s /= gcd;

        cout << r_squared << "/" << s << endl;
    }

    return 0;
}