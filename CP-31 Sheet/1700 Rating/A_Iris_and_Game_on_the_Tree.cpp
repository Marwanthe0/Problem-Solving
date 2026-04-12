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
void dfs(int src, vector<vector<int>> &g, vector<int> &vis, string &s, int a, int b, vector<pair<int, int>> &leave) {
    vis[src] = 1;
    bool flag = true;
    int ta = a, tb = b;
    for (auto child : g[src]) {
        if (!vis[child]) {
            flag = false;
            if (s[src - 1] == '1' && s[child - 1] == '0')
                ta = a + 1;
            else
                ta = 0;
            if (s[src - 1] == '0' && s[child - 1] == '1')
                tb = b + 1;
            else
                tb = 0;
            cerr << src << " " << child << " " << ta << ":" << tb << endl;
            dfs(child, g, vis, s, ta, tb, leave);
        }
    }
    if (flag) {
        leave[src] = {a, b};
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    string s;
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s;
    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> leave(n + 1), unin(n + 1);
    dfs(1, g, vis, s, 0, 0, leave);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            cout << i << endl;
            cout << leave[i].first << " " << leave[i].second << endl;
            cur += (abs(leave[i].first - leave[i].second) != 0);
        }
    }
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