#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
map<pair<int, int>, int> m;
vector<int> path, vis;
void dfs(int v) {
    path.push_back(v);
    vis[v] = 1;
    for (auto child : g[v]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        m[{x, y}] = z;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int aa = 0, bb = 0;
    dfs(1);
    // for (auto vl : path)
    //     cerr << vl << " ";
    for (int i = 0, j = path.size() - 1; i < path.size() - 1; i++, j--) {
        if (m.count({path[i + 1], path[i]}))
            aa += m[{path[i + 1], path[i]}];
        if (m.count({path[j - 1], path[j]}))
            bb += m[{path[j - 1], path[j]}];
    }
    if (m.count({path.front(), path.back()}))
        aa += m[{path.front(), path.back()}];
    if (m.count({path.back(), path.front()}))
        bb += m[{path.back(), path.front()}];
    cout << min(aa, bb) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}