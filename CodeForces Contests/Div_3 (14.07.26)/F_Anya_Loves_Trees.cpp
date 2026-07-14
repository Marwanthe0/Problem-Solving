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
int n;
vector<vector<int>> g;
vector<int> v, lvs;
void dfs(int nd, int p) {
    bool flag = true;
    for (auto child : g[nd]) {
        if (child != p) {
            flag = false;
            dfs(child, nd);
        }
    }
    if (flag)
        lvs.push_back(nd);
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    lvs.clear();
    v.assign(n, 0);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
        cout << i << " " << x << endl;
    }
    for (int i = 1; i <= n; i++)
        sort(all(g[i]));
    dfs(1, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x)
            v[x - 1] = i + 1;
    }
    for (auto vl : lvs)
        cout << vl << " ";
    cout << endl;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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