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
void dfs(int src, vector<set<int>> &g, vector<int> &vis) {
    vis[src] = 1;
    for (auto child : g[src]) {
        if (!vis[child])
            dfs(child, g, vis);
    }
}
void dfs2(int src, vector<set<int>> &g, vector<int> &vis, set<int> &khali) {
    vis[src] = 1;
    if (g[src].size() == 1)
        khali.insert(src);
    for (auto child : g[src]) {
        if (!vis[child])
            dfs2(child, g, vis, khali);
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n), vis(n + 1, 0), vis2(n + 1, 0);
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1];
        g[i].insert(v[i - 1]);
        g[v[i - 1]].insert(i);
    }
    // for (int i = 1; i <= n; i++) {
    //     //cerr << i << endl;
    //     for (auto vl : g[i])
    //         //cerr << vl << " ";
    //     //cerr << endl;
    // }
    vector<set<int>> g2(all(g));
    set<int> khali;
    for (int i = 1; i <= n; i++) {
        set<int> tkhali;
        if (!vis2[i]) {
            dfs2(i, g2, vis2, tkhali);
        }
        if (tkhali.size() && khali.size()) {
            auto age = tkhali.begin(), pore = khali.begin();
            g2[*age].insert(*pore);
            g2[*pore].insert(*age);
            tkhali.erase(age), khali.erase(pore);
        }
        for (auto vl : tkhali)
            khali.insert(vl);
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << i << endl;
    //     for (auto vl : g2[i])
    //         cerr << vl << " ";
    //     cerr << endl;
    // }
    // cerr << endl;
    int count = 0, count2 = 0;
    for (int i = 1; i <= n; i++)
        vis2[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, g, vis);
            count++;
        }
        if (!vis2[i]) {
            dfs(i, g2, vis2);
            count2++;
        }
    }
    cout << count2 << " " << count << endl;
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