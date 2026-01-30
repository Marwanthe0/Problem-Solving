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
#define make_unique v.erase(unique(v.begin(), v.end()), v.end());
void marwan()
{
    int n;
    cin >> n;
    vector<int> s(n), t;
    for (auto &vl : s)
        cin >> vl;
    t = s;
    sort(all(t));
    if (s == t)
    {
        cout << -1 << endl;
        return;
    }
    int mx = t.back(), mn = t.front(), ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            ans = min(ans, max(abs(s[i] - mx), abs(s[i] - mn)));
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