#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
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
vector<pair<int, int>> pos;
int n;
vector<string> v;
pair<int, uint> dp[8][8][8];
pair<int, uint> f(int i, int j, int idx) {
    int anscost = 1e9;
    uint ansmask = (1LL << (n * i + j)), tmask = 0;
    // current queen cost calculation
    int curcost = 0;
    auto [curi, curj] = pos[idx];
    if (curi == i && curj == j)
        curcost = 0;
    else if (curi == i || curj == j || (curi - curj == i - j) || (curi + curj == i + j))
        curcost = 1;
    else
        curcost = 2;

    if (idx == n - 1) {
        // cerr << i << " " << j << " " << curcost << " " << ansmask << endl;
        return dp[i][j][idx] = {curcost, ansmask};
    }
    if (dp[i][j][idx].first != -1)
        return dp[i][j][idx];

    // next queen place setting
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {

            auto [cost, mask] = f(k, l, idx + 1);
            vector<pair<int, int>> maskpos;

            for (int m = 63; m >= 0; m--) {
                if ((mask >> m) & 1LL) {
                    maskpos.push_back({m / 8, m % 8});
                }
            }
            bool flag = true;
            for (auto [x, y] : maskpos) {
                if (x == i || y == j || (x - y == i - j) || (x + y == i + j)) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            if (cost + curcost < anscost) {
                anscost = cost + curcost, tmask = mask;
            }
        }
    }
    ansmask |= tmask;
    return dp[i][j][idx] = {anscost, ansmask};
}
void marwan(int cs) {
    n = 8;
    v.assign(n, string());
    pos.clear();
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'q') {
                pos.push_back({i, j});
            }
        }
    }
    memset(dp, -1, sizeof dp);
    pair<int, int> ans{1e9, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> tans = f(i, j, 0);
            if (tans.first < ans.first)
                ans = tans;
        }
    }
    cout << ans.first << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}