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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int tx = 0, x = 0;
    for (auto &vl : v)
    {
        cin >> vl;
        tx ^= vl;
    }
    for (int i = 0; i < n; i++)
    {
        if (x == tx)
        {
            yes;
            return;
        }
        x ^= v[i];
        tx ^= v[i];
        if (x == tx)
        {
            yes;
            return;
        }
    }
    // cout << x << " " << tx << endl;
    swap(x, tx);
    for (int i = 0; i < n; i++)
    {
        x ^= v[i];
        tx ^= v[i];
        int ttx = tx, xi = 0;
        for (int j = i + 1; j < n; j++)
        {
            ttx ^= v[j], xi ^= v[j];
            if (x == ttx && ttx == xi)
            {
                yes;
                return;
            }
        }
    }
    no;
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