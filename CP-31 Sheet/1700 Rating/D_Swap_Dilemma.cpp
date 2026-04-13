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
vector<vector<int>> g(2e5 + 5);
vector<int> vis(2e5 + 1, 0);
int dfs(int n) {
    int count = 1;
    vis[n] = 1;
    for (auto child : g[n]) {
        if (!vis[child]) {
            count += dfs(child);
        }
    }
    return count;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ta, tb;
    int mx = 0;
    for (auto &vl : a) {
        cin >> vl;
    }
    for (auto &vl : b) {
        cin >> vl;
    }
    ta = a, tb = b;
    sort(all(ta));
    sort(all(tb));
    if (ta != tb) {
        no;
        return;
    }
    if (a == b) {
        yes;
        return;
    }
    vector<int> s(all(a));
    for (auto vl : b)
        s.push_back(vl);
    make_unique(s);
    for (auto vl : s) {
        g[vl].clear(), vis[vl] = 0;
    }
    for (int i = 0; i < n; i++) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    int count2 = 0;
    for (auto vl : s) {
        if (!vis[vl]) {
            int count = dfs(vl);
            if (count % 2 == 0) {
                count2++;
            }
        }
    }
    if (count2 % 2 == 0)
        yes;
    else
        no;
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