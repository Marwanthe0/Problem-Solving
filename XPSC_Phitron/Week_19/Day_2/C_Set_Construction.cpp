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
    char a[n][n];
    vector<int> g[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = s[j];
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == '1')
            {
                // cout << j << " " << i << endl;
                g[j].push_back(i);
            }
        }
        // cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // cout << i + 1 << "::";
        // for (int j = 0; j < g[i].size(); j++)
        //     cout << g[i][j] + 1 << " ";
        v.push_back({g[i].size(), i});
        // cout << endl;
    }
    sort(all(v));
    int count = 0;
    vector<set<int>> ans(n);
    for (auto [x, y] : v)
    {
        // cerr << x << " " << y << endl;
        for (int i = 0; i < x; i++)
        {
            int vl = g[y][i];
            for (auto val : ans[vl])
                ans[y].insert(val);
        }
        ans[y].insert(count);
        count++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].size() << " ";
        for (auto vl : ans[i])
            cout << vl + 1 << " ";
        cout << endl;
    }
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