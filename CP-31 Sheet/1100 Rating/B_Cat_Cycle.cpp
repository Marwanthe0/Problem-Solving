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
void marwan()
{
    int n, k;
    cin >> n >> k;
    if (n & 1)
    {
        int d = (k - 1) / (n / 2);
        int x = (d + k) % n;
        if (x == 0)
            cout << n << endl;
        else
            cout << x << endl;
    }
    else
    {
        int x = (k % n);
        if (x == 0)
            cout << n << endl;
        else
            cout << x << endl;
    }
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