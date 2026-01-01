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
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> v(n), t(n);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : t)
        cin >> vl;
    map<int, int> x, y;
    map<pair<int, int>, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
            ans += ((i) - (x[v[i]] + y[t[i]] - m[{v[i], t[i]}]));
        x[v[i]]++, y[t[i]]++, m[{v[i], t[i]}]++;
    }
    cout << ans << endl;
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