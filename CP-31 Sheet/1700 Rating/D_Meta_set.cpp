#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
int f(int i, int j) {
    if (i == j)
        return i;
    else
        return 3 - (i + j);
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(k, 0));
    map<vector<int>, int> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> v[i][j];
        }
        m[v[i]] = i;
    }
    map<int, int> fr;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vis[i][j])
                continue;
            vector<int> temp;
            for (int t = 0; t < k; t++) {
                temp.push_back(f(v[i][t], v[j][t]));
            }
            if (m.count(temp)) {
                // cerr << i << " " << j << " " << m[temp] << endl;
                vis[i][m[temp]] = vis[j][m[temp]] = 1;
                fr[m[temp]]++;
                fr[i]++, fr[j]++;
            }
        }
    }
    int ans = 0ll;
    for (auto [x, y] : fr) {
        // cout << x << " " << y << endl;
        ans += (y * (y - 1)) / 2;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}