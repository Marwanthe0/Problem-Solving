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
int sq(int x) {
    return x * 1ll * x;
}
void marwan() {
    int n, q;
    cin >> n >> q;
    int x, y;
    cin >> x >> y;
    vector<pair<pair<int, int>, int>> v(n);
    int dist = -1e17;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
        int tx = v[i].first.first, ty = v[i].first.second;
        dist = max(dist,
                   sq(abs(tx - x)) + sq(abs(ty - y)));
    }
    auto ok = [&](int mid, int w8) {
        int count = 0ll;
        for (int i = 0; i < n; i++) {
            int tx = v[i].first.first, ty = v[i].first.second, val = v[i].second;
            if ((sq(abs(tx - x)) + sq(abs(ty - y))) <= mid)
                count += val;
            if (count >= w8)
                return true;
        }
        return count >= w8;
    };
    // cerr << dist << endl;
    while (q--) {
        int w8;
        cin >> w8;
        if (w8 <= 0) {
            cout << 0 << endl;
            return;
        }
        int l = 0, r = dist, tans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2ll;
            bool kk = ok(mid, w8);
            // cerr << mid << " " << kk << endl;
            if (kk) {
                tans = mid, r = mid - 1;
            } else
                l = mid + 1;
        }
        // cerr << endl;
        cout << tans << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}