#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int32_t>> divs(N + 1);
void prediv() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int32_t> v(n);
    unordered_map<int32_t, int32_t> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    int ans = 0ll;
    for (auto &[x, y] : m) {
        if (y >= 3) {
            ans += (y * 1ll * (y - 1) * 1ll * (y - 2));
        }
    }
    sort(all(v));
    unordered_map<int32_t, int32_t> vis;
    unordered_map<int32_t, int> tg;
    for (int i = 0; i < n; i++) {
        if (tg.count(v[i]))
            ans += tg[v[i]];
        // cerr << v[i] << " " << ans << endl;
        for (auto &d : divs[v[i]]) {
            if (vis[d]) {
                // cerr << d << " ";
                if (v[i] == d) {
                    continue;
                } else {
                    int target = (v[i] / d) * 1ll * v[i];
                    if (target <= N)
                        tg[target] += vis[d];
                }
            }
        }
        // cerr << endl;
        vis[v[i]]++;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    prediv();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}