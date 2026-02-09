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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
pair<int, int> bfs(int src, vector<vector<int>> &g, set<int> &leaves)
{
    int n = g.size() - 1;
    vector<int> lvl(n + 1, 0), vis(n + 1, 0);
    queue<int> q;
    q.push(src);
    lvl[src] = 1;
    int mx = INT_MAX, mxnd;
    vis[src] = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        // cerr << nd << "::";
        for (auto child : g[nd])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                lvl[child] = lvl[nd] + 1;
                if (leaves.count(child) && lvl[child] < mx)
                {
                    mx = lvl[child], mxnd = child;
                }
            }
        }
    }
    cerr << src << " " << mx << " " << mxnd << endl;
    return {mx, mxnd};
}
bool dfs(int src, int t, vector<vector<int>> &g, vector<int> &vis, vector<int> &ans)
{
    if (src == t)
        return true;
    vis[src] = true;
    cerr << src << " ";
    for (auto child : g[src])
    {
        if (!vis[src])
        {
            bool x = dfs(child, t, g, vis, ans);
            if (x)
            {
                ans.push_back(child);
                return true;
            }
        }
    }
    return false;
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> leaves;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
            leaves.insert(i);
    }
    int mx = INT_MAX;
    pair<int, int> ans = {-1, -1};
    for (auto leave : leaves)
    {
        // cerr << leave << " ";
        pair<int, int> mn = bfs(leave, g, leaves);
        if (mn.first < mx)
        {
            mx = mn.first, ans = {leave, mn.second};
        }
    }
    cout << ans.first << " " << ans.second << endl;
    vector<int> answer, vis(n + 1);
    dfs(ans.first, ans.second, g, vis, answer);
    for (auto vl : answer)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}