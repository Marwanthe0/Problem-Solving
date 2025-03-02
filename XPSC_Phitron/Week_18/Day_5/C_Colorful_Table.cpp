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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<pair<int, int>> m(k + 1, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (m[v[i]].first == -1)
            m[v[i]] = {i + 1, i + 1};
        else
            m[v[i]].second = i + 1;
    }
    for (int i = 1; i <= k; i++)
    {
        cerr << i << ":: " << m[i].first << " " << m[i].second << endl;
    }
    cerr << endl;
    vector<int> ans;
    int mx = -1, mn = INT_MAX;
    for (int i = k; i >= 1; i--)
    {
        if (m[i].first == -1)
        {
            ans.push_back(0);
            continue;
        }
        mx = max(mx, m[i].second);
        mn = min(mn, m[i].first);
        if (i == k)
        {
            ans.push_back(2 * ((m[i].second - m[i].first + 1)));
        }
        else
        {
            ans.push_back(2 * (mx - mn + 1));
        }
    }
    reverse(all(ans));
    for (auto vl : ans)
        cout << vl << " ";
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