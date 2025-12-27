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
    vector<pair<int, vector<int>>> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (auto &vl : temp)
            cin >> vl;
        v.push_back({-1, temp});
    }
    for (auto &vl : v)
    {
        int mx = vl.second.back() + 2;
        for (int i = vl.second.size() - 1; i >= 0; i--)
        {
            mx = max(mx - 1, vl.second[i] + 1);
        }
        vl.first = mx;
    }
    sort(all(v));
    reverse(all(v));
    int ans = v.back().second.back() + 2;
    for (auto vl : v)
    {
        reverse(all(vl.second));
        // cout << vl.first << endl;
        for (auto val : vl.second)
        {
            ans = max(ans - 1, val + 1);
        }
        // cout << endl;
    }
    cout << ans << endl;
    // cout << endl;
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