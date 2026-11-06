#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
int n, m, q;
vector<string> g, querys;
vector<vector<vector<int>>> vis;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 0}};
// D, R, U, L, DR, UL, DL, UR, *
vector<string> tag;
string ans;
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
bool dfs(int i, int j, int k, string &s, vector<int> &t) {
    if (k == s.size()) {
        string tt = "";
        for (auto vl : t) {
            tt += tag[vl];
        }
        tt.pop_back();
        ans = tt;
        return vis[i][j][k] = true;
    }
    if (vis[i][j][k] != -1)
        return vis[i][j][k];
    int idx = 0;
    for (auto [x, y] : path) {
        x += i, y += j;
        if (valid(x, y) && k + 1 == s.size()) {
            if (dfs(x, y, k + 1, s, t))
                return vis[i][j][k] = true;
        }
        if (valid(x, y) && k + 1 < s.size() && g[x][y] == s[k + 1]) {
            t.push_back(idx);
            if (dfs(x, y, k + 1, s, t))
                return vis[i][j][k] = true;
            t.pop_back();
        }
        idx++;
    }
    return vis[i][j][k] = false;
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    tag = {" D,", " R,", " U,", " L,", " DR,", " UL,", " DL,", " UR,", " *,"};
    map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++)
            mp[g[i][j]].push_back({i, j});
    }
    cin >> q;
    querys.assign(q, string());
    for (int i = 0; i < q; i++) {
        cin >> querys[i];
        string &s = querys[i];
        auto &pos = mp[s[0]];
        bool flag = true;
        vis.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(s.size() + 1, -1)));
        for (auto &[i, j] : pos) {
            vector<int> t;
            if (dfs(i, j, 0, s, t)) {
                cout << s << " found: ";
                cout << '(' << i + 1 << "," << j + 1 << ")," << ans << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << s << " not found" << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}