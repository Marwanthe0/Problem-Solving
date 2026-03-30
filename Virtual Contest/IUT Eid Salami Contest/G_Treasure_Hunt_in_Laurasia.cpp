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
int f(int i, int sum, vector<int> &a, vector<int> &v) {
    if (i < 0)
        return 0;
    int nibona = f(i - 1, sum, a, v), nibo = 0;
    if (a[i] <= sum)
        nibo = f(i - 1, sum - a[i], a, v) + v[i];
    return max(nibo, nibona);
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), v(n);
    set<int> s;
    vector<vector<int>> g(5001);
    for (auto &vl : a) {
        cin >> vl;
        s.insert(vl);
    }
    for (auto &vl : v) {
        cin >> vl;
    }
    for (int i = 0; i < n; i++) {
        g[a[i]].push_back(v[i]);
    }
    for (auto vl : s) {
        sort(all(g[vl]), greater<int>());
    }
    vector<pair<int, int>> ans;
    for (auto vl : s) {
        for (int i = 0; i < min((int)g[vl].size(), (k / vl)); i++) {
            ans.push_back({vl, g[vl][i]});
        }
    }
    n = ans.size();
    a.clear(), v.clear();
    for (auto &[x, y] : ans) {
        a.push_back(x);
        v.push_back(y);
    }
    vector<int> next(k + 1, 0), prev(k + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int nibona = prev[j], nibo = 0;
            if (j >= a[i - 1])
                nibo = prev[j - a[i - 1]] + v[i - 1];
            next[j] = max(nibo, nibona);
        }
        prev = next;
    }
    for (int i = 1; i <= k; i++)
        cout << next[i] << " ";
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