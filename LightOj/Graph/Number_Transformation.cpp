#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 2000
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int>> primes;
vector<int> ps;
void pre() {
    ps.assign(N + 1, 0);
    primes.assign(N + 1, vector<int>());
    for (int i = 2; i <= N; i++) {
        if (!ps[i]) {
            for (int j = i * i; j <= N; j += i) {
                primes[j].push_back(i);
                ps[j] = 1;
            }
        }
    }
}
void marwan(int cs) {
    int n, m;
    cin >> n >> m;

    vector<int> vis(n + m + 1, 0), dist(n + m + 1, 0);
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cerr << u << " ";
        if (u == m) {
            cout << dist[u] << endl;
            return;
        }
        vector<int> primefactors = primes[u];
        for (auto v : primefactors) {
            if (v == u)
                continue;
            v += u;
            if (!vis[v] && v <= m) {
                vis[v] = 1;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    minus;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}