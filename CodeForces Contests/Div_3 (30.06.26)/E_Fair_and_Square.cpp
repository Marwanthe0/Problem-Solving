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
vector<vector<int>> g, vals;
vector<int> v;
int dfs(int nd, int p, int d) {
    int x = 0;
    for (auto child : g[nd]) {
        if (child != p) {
            int nodes = dfs(child, nd, d + 1) + 1;
            x += nodes;
            vals[nd].push_back(nodes);
        }
    }
    return x;
}
void marwan() {
    cin >> n;
    v.assign(n, 0);
    for (auto &vl : v) {
        cin >> vl;
    }
    g.assign(n + 1, vector<int>()), vals.assign(n + 1, vector<int>());
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    int ans = 0;
    auto f = [&](vector<int> &arr) {
        int sz = arr.size(), uttor = 0ll, sum = accumulate(all(arr), 0ll);
        int tsum = sum;
        vector<int> contr(sz);
        for (int i = 0; i < sz; i++) {
            sum -= arr[i];
            contr[i] = arr[i] * 1ll * sum;
            uttor += contr[i];
        }
        int tuttor = uttor;
        for (int i = 0; i + 2 < sz; i++) {
            tuttor -= contr[i];
            uttor += arr[i] * 1ll * tuttor;
        }
        return uttor;
    };
    for (int i = 1; i <= n; i++) {
        if ((int)sqrt(v[i - 1]) * (int)(sqrt(v[i - 1])) != v[i - 1])
            continue;
        int x = accumulate(all(vals[i]), 0);
        if (n - x - 1)
            vals[i].push_back(n - x - 1);
        ans += f(vals[i]);
        // cerr << i << endl;
        // for (auto vl : vals[i])
        //     cerr << vl << " ";
        // cerr << endl;
        // cerr << endl;
    }
    // cerr << endl;
    cout << ans << endl;
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