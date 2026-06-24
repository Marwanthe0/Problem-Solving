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
vector<int> inv(N + 1, 0);
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = mod(a * 1ll * a);
        b >>= 1;
    }
    return ans % M;
}
void pre() {
    inv[N] = binexp(N, M - 2);
    for (int i = N; i >= 1; i--) {
        inv[i - 1] = mod(inv[i] * (i - 1));
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    vector<pair<int, int>> t;
    for (auto [x, y] : m) {
        t.push_back({x, y});
        // cout << x << " " << y << endl;
    }
    int l = 0, r = 0, ans = 0ll, tans = 1ll;
    multiset<int> ms;
    while (r < t.size()) {
        ms.insert(t[r].first);
        tans = (tans * 1ll * t[r].second) % M;
        if (r - l + 1 == k) {
            int mn = *(ms.begin()), mx = *(--ms.end());
            if (mx - mn + 1 == k) {
                ans = (ans + tans) % M;
            }
            tans = (tans * inv[t[l].second]) % M;
            ms.erase(ms.find(t[l++].first));
        }
        // cerr << r << " " << tans << " " << ans << endl;
        r++;
    }
    // cerr << endl;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}