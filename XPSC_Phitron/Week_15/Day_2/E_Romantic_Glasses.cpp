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
    int n;
    cin >> n;
    vector<int> v(n), pf(n + 1, 0);
    int sum = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i & 1)
        {
            v[i] *= (-1);
        }
        // cout << v[i] << " ";
        pf[i + 1] = pf[i] + v[i];
    }
    map<int, int> m;
    for (int i = 0; i <= n; i++)
    {
        // cout << pf[i] << " ";
        m[pf[i]]++;
    }
    for (auto vl : m)
        if (vl.second > 1)
        {
            yes;
            return;
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