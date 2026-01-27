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
    vector<int> g[n + 1], vis(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> s;
    s.insert(1);
    vis[1] = 1;
    while (!s.empty())
    {
        int par = *s.begin();
        s.erase(s.begin());
        vis[par] = true;
        cout << par << " ";
        for (auto child : g[par])
        {
            if (!vis[child])
            {
                s.insert(child);
            }
        }
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     marwan();
    // }
    marwan();
    return 0;
}