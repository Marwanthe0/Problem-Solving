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
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    set<pair<int, int>> con;
    vector<int> all;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u < v)
            swap(u, v);
        con.insert({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int, vector<int>> level;
    vector<int> lvl(n + 1), vis(n + 1, 0), par(n + 1, 1);
    queue<int> q;
    q.push(1);
    lvl[1] = 1;
    vis[1] = 1;
    level[1].push_back(1);
    int mxlvl = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        all.push_back(nd);
        // cerr << nd << " ";
        for (auto child : g[nd])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                par[child] = nd;
                lvl[child] = lvl[nd] + 1;
                level[lvl[child]].push_back(child);
                mxlvl = max(mxlvl, lvl[child]);
            }
        }
    }
    int mx = 0, mxidx = 1;
    for (auto &vl : level)
    {
        int count = vl.second.size();
        bool flag = true;
        int first = par[vl.second.front()];
        for (auto &val : vl.second)
        {
            if (par[val] != first)
                flag = false;
        }
        if (flag)
            count++;
        if (count > mx)
        {
            mx = count;
            mxidx = vl.first;
        }
    }
    vector<int> target = level[mxidx];
    if (mx > level[mxidx].size())
        target.push_back(par[target.front()]);
    int ans = 0;
    vector<set<int>> answer;
    set<int> shesh;
    for (auto vl : target)
    {
        set<int> tempset;
        tempset.insert(vl);
        for (int i = 1; i <= mxlvl; i++)
        {
            if (i == mxidx)
                continue;
            for (auto node : level[i])
            {
                if (!shesh.count(node) && tempset.find(par[node]) == tempset.end())
                {
                    tempset.insert(node);
                    shesh.insert(node);
                    break;
                }
            }
        }
        answer.push_back(tempset);
    }
    cout << answer.size() << endl;
    for (auto &vl : answer)
    {
        cout << vl.size() << " ";
        for (auto &val : vl)
            cout << val << " ";
        cout << endl;
    }
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