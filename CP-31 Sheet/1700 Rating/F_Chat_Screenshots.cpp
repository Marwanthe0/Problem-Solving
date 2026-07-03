#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int>> v, g;
vector<int> indegree, vis;
void marwan() {
    int n, k;
    cin >> n >> k;
    g.assign(n + 1, vector<int>());
    v.assign(k, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (j > 1) {
                g[v[i][j - 1]].push_back(v[i][j]);
            }
        }
    }
    if (k == 1) {
        yes;
        return;
    }
    indegree.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // cerr << i << endl;
        make_unique(g[i]);
        for (auto vl : g[i]) {
            // cerr << vl << " ";
            indegree[vl]++;
        }
        // cerr << endl;
    }
    // cerr << endl;
    queue<int> q;
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        ans.push_back(nd);
        vis[nd] = 1;
        for (auto child : g[nd]) {
            indegree[child]--;
            if (indegree[child] <= 0)
                q.push(child);
        }
    }
    for (auto vl : ans)
        cerr << vl << " ";
    cerr << endl;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            no;
            return;
        }
    }
    yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}