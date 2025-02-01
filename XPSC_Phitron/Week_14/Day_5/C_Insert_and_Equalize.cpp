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
    vector<int> v(n), dif;
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(all(v));
    for (int i = 1; i < n; i++)
        dif.push_back(v[i] - v[i - 1]);
    int x = 0;
    for (auto vl : dif)
        x = __gcd(x, vl);
    int z = v.back() - x;
    while (m.find(z) != m.end())
    {
        z -= x;
    }
    v.push_back(z);
    sort(all(v));
    int ans = 0;
    for (auto vl : v)
        ans += (v.back() - vl) / x;
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