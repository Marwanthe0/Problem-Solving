#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll x, y, k;
    cin >> x >> y >> k;
    ll a = (min(x, y) / k) * 2, b = max(x, y) - min(x, y);
    a += ((b / k) + (b % k != 0)) * 2;
    if (x > y)
        a--;
    cout << a << endl;
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