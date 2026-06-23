#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m, k;
vector<string> v;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<bool>> vis;
bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(int i, int j) {
    vis[i][j] = 1;
    for (auto [a, b] : path) {
        int x = i + a, y = j + b;
        if (valid(x, y) && !vis[x][y] && v[x][y] != '#') {
            dfs(x, y);
        }
    }
    if (k > 0) {
        v[i][j] = 'X';
        k--;
    }
}
void marwan() {
    cin >> n >> m >> k;
    int a, b;
    v.resize(n);
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.')
                a = i, b = j;
        }
    }
    dfs(a, b);
    for (auto vl : v)
        cout << vl << endl;
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}