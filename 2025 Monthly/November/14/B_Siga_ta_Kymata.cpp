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
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1')
    {
        cout << -1 << endl;
        return;
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < v[mn])
        {
            mn = i;
        }
        if (v[i] > v[mx])
        {
            mx = i;
        }
    }
    if (s[mn] == '1' || s[mx] == '1')
    {
        cout << -1 << endl;
        return;
    }
    int mnn = min(mn, mx) + 1, mxx = max(mn, mx) + 1;
    set<pair<int, int>> ans;
    ans.insert({1, mnn});
    ans.insert({1, mxx});
    ans.insert({mnn, mxx});
    ans.insert({mnn, n});
    ans.insert({mxx, n});
    cout << ans.size() << endl;
    // cout << 1 << " " << mnn << endl;
    // cout << 1 << " " << mxx << endl;
    // cout << mnn << " " << n << endl;
    // cout << mxx << " " << n << endl;
    // cout << mnn << " " << mxx << endl;
    for (auto vl : ans)
        cout << vl.first << " " << vl.second << endl;
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