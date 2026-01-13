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
    vector<pair<int, int>> v(n + 1);
    map<int, int> resp;
    int root = 0;
    vector<int> g[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
        resp[i] = v[i].second;
        if (v[i].first == -1)
            root = i;
        else
        {
            g[i].push_back(v[i].first);
            g[v[i].first].push_back(i);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     //cerr << i << endl;
    //     for (auto vl : g[i])
    //         //cerr << vl << " ";
    //     //cerr << endl;
    //     //cerr << endl;
    // }
    vector<int> ans;
    vector<bool> vis(n + 1, false);
    auto bfs = [&](int root)
    {
        queue<int> q;
        q.push(root);
        vis[root] = true;
        bool check = true;
        while (!q.empty())
        {
            check = true;
            int par = q.front();
            q.pop();
            vis[par] = true;
            // cerr << par << " ";
            if (!resp[par])
                check = false;
            for (auto child : g[par])
            {
                if (!vis[child])
                {
                    q.push(child);
                    if (!resp[child])
                        check = false;
                }
            }
            if (check)
                ans.push_back(par);
        }
    };
    bfs(root);
    sort(all(ans));
    if (ans.empty())
        cout << -1;
    else
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