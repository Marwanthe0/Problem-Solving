#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
double dif = 1e-6;
long double multiply(double n, double m)
{
    long double ans = 1;
    while (m--)
        ans *= n;
    return ans;
}
long double sqroot(double n, double m)
{
    long double lo = 1, hi = n, mid, count = 0;
    while (hi - lo > dif)
    {
        mid = (hi + lo) / 2;
        // cout << mid << " ";
        if (multiply(mid, m) < n)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    return hi;
}
void marwan()
{
    long double n, m;
    cin >> n >> m;
    cout << sqroot(n, m) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}