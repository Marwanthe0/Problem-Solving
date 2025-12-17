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
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (m.find(v[i]) == m.end())
        {
            m[v[i]] = {i + 1, i + 1};
        }
        else
            m[v[i]].second = i + 1;
    }
    vector<int> ans(n + 1, 0);
    for (auto vl : m)
    {
        if (vl.second.first == vl.second.second)
        {
            cout << -1 << endl;
            return;
        }
        pair<int, int> idx = vl.second;
        if ((idx.second - idx.first + 1) % 2 == 0)
        {
            int cnt = idx.second;
            for (int i = idx.first; i <= idx.second; i++)
            {
                ans[i] = cnt--;
            }
        }
        else
        {
            int cnt = idx.first;
            ans[idx.first] = idx.second;
            for (int i = idx.first + 1; i <= idx.second; i++)
            {
                ans[i] = cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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