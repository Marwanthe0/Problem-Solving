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
int n, m;
vector<string> v;
int si, sj, di, dj;
vector<vector<int>> vis;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
bool dfs(int i, int j) {
    if (i == di && j == dj && v[i][j] == 'X')
        return true;
    bool ans = false;
    if (v[i][j] == '.')
        v[i][j] = 'X';
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && (v[x][y] == '.' || (x == di && y == dj))) {
            ans |= dfs(x, y);
        }
    }
    return ans;
}
void marwan() {
    cin >> n >> m;
    vis.assign(n, vector<int>(m, 0));
    v.assign(n, string());
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> si >> sj;
    cin >> di >> dj;
    si--, sj--, di--, dj--;
    for (auto [x, y] : path) {
        x += si, y += sj;
        if (valid(x, y) && (v[x][y] == '.' || (x == di && y == dj))) {
            if (dfs(x, y)) {
                yes;
                return;
            }
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}