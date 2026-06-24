#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
vector<vector<pair<int, int>>> g;
vector<int> edgeDay;
void dfs(int v, int p, int color) {
    int currrentColor = 1;
    for (auto &[child, edge] : g[v]) {
        if (child == p)
            continue;
        if (currrentColor == color)
            currrentColor++;
        edgeDay[edge] = currrentColor;
        dfs(child, v, currrentColor);
        currrentColor++;
    }
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<pair<int, int>>());
    edgeDay.assign(n, 0);
    int uttor = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        uttor = max(uttor, (int)g[u].size());
        uttor = max(uttor, (int)g[v].size());
    }
    dfs(1, 0, 0);
    vector<vector<int>> ans(uttor + 1);
    for (int i = 1; i < n; i++) {
        ans[edgeDay[i]].push_back(i);
    }
    cout << uttor << endl;
    for (int i = 1; i <= uttor; i++) {
        cout << ans[i].size() << " ";
        for (auto &vl : ans[i])
            cout << vl << " ";
        cout << endl;
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}