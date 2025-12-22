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
    int l, v, t, n;
    cin >> l >> v >> t >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int d = abs(v - y);
        int rem = t - x;
        int kkk = (l / d);
        if (i == n - 1)
            cout << 1 + ((rem * d) / l);
        else
            cout << 1 + ((rem * d) / l) << " ";
    }
    cout << endl;
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