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
vector<int> g[N];
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
        if (a != -1)
            g[a].push_back(i);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int flag = (v[i].second);
        for (auto vl : g[i])
        {
            flag *= v[vl].second;
        }
        if (flag)
            ans.push_back(i);
    }
    if (ans.empty())
        cout << -1 << endl;
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}