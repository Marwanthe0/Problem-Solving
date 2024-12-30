#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
void marwan()
{
    int x, y, k;
    cin >> x >> y >> k;
    for (int i = 1; i <= k; i++)
    {
        if (i % 2)
        {
            if (x > y)
            {
                x = __gcd(x, y);
            }
            else
                y = __gcd(x, y);
        }
        else
        {
            if (x > y)
            {
                x = lcm(x, y);
            }
            else
                y = lcm(x, y);
        }
    }
    cout << x + y << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}