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
void marwan() {
    int n;
    cin >> n;
    vector<int> v;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (v.empty() || (x != v.back())) {
            v.push_back(x);
        }
    }
    n = v.size();
    for (int i = 0; i < n; i++) {
        m[v[i]].push_back(i);
    }
    vector<int> t, vis(n + 1, 0);
    t = v;
    int count = 0;
    sort(all(t), greater<int>());
    for (int i = 0; i < n; i++) {
        int x = m[t[i]].back();
        m[t[i]].pop_back();
        if (vis[x])
            continue;
        // cerr << x << " ";
        if ((x > 0 && vis[x - 1]) || (x < n - 1 && vis[x + 1])) {
        } else
            count++;
        vis[x] = 1;
        // int tx = x;
        // while (tx > 0 && (v[tx] - 1 == v[tx - 1])) {
        //     vis[--tx] = 1;
        // }
        // tx = x;
        // while ((tx < n - 1) && (v[tx] - 1 == v[tx + 1])) {
        //     vis[++tx] = 1;
        // }
    }
    cout << count << endl;
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