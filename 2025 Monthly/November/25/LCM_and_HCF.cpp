#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int gd(int a, int b)
{
    if (a == 0 || b == 0)
        return max(a, b);
    if (a == b)
        return a;
    return gd(max(a, b) - min(a, b), min(a, b));
    // if (a > b)
    //     return gd(a - b, b);
    // else
    //     return gd(a, b - a);
}
void marwan()
{
    int a, b;
    cin >> a >> b;
    int gcd = gd(a, b);
    cout << a * b / gcd << " " << gcd << endl;
}
int32_t main()
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