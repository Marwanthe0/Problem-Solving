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
    int n, x = 0, y = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &vl : a)
    {
        cin >> vl;
        x ^= vl;
    }
    for (auto &vl : b)
    {
        cin >> vl;
        y ^= vl;
    }

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            int d1 = x - y;
            int newx = x, newy = y;
            newx ^= (a[i] ^ b[i]);
            newy ^= (a[i] ^ b[i]);
            int d2 = newx - newy;
            if (d2 < d1)
            {
                swap(a[i], b[i]);
                x = newx, y = newy;
            }
        }
        else
        {
            int d1 = x - y;
            int newx = x, newy = y;
            newx ^= (a[i] ^ b[i]);
            newy ^= (a[i] ^ b[i]);
            int d2 = newx - newy;
            if (d2 > d1)
            {
                swap(a[i], b[i]);
                x = newx, y = newy;
            }
        }
    }
    if (x == y)
        cout << "Tie" << endl;
    else if (x > y)
        cout << "Ajisai" << endl;
    else
        cout << "Mai" << endl;
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