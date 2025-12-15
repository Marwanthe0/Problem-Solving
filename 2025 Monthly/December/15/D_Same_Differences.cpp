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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        v[i] -= i;
    }
    int ans = 0;
    for (auto vl : v)
    {
        m[vl]++;
        cerr << vl << " ";
    }
    for (auto [vl, y] : m)
    {
        ans += (m[vl] * ((m[vl] - 1)) / 2);
    }
    cerr << endl;
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