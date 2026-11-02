#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> a;
int uttor;
pair<int, int> dfs(int u, int p) {

    pair<int, int> ans = {0, 0};
    if (a[u])
        ans.first++;
    else
        ans.second++;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        pair<int, int> tans = dfs(v, u);
        ans.first += tans.first, ans.second += tans.second;
    }
    if (ans.first == ans.second)
        uttor++;
    return ans;
}
void marwan() {
    cin >> n;
    a.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] == 'W';
    }
    uttor = 0;
    dfs(1, 1);
    cout << uttor << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}