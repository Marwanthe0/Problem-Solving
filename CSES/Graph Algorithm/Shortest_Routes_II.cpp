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
void marwan() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e15));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != 1e15 && dist[k][j] != 1e15) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while (k--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] != 1e15)
            cout << dist[u][v] << endl;
        else
            cout << -1 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}