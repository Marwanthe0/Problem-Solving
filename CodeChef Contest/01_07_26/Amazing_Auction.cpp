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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x;
    for (auto &[x, y] : v)
        cin >> y;
    sort(all(v));
    reverse(all(v));
    int ans = v[k].first * k;
    for (int i = v[k - 1].first; i <= v[0].first; i++) {
        int cost = 0ll;
        for (int j = 0; j < k; j++) {
            if (v[j].first < i) {
                cost += v[j].second * (i - v[j].first);
            }
        }
        int tcost = INT_MAX;
        for (int j = k; j < n; j++) {
            tcost = min(tcost,
                        (i - v[j].first) * v[j].second);
        }
        cost += tcost;
        if (k * i - cost < ans)
            break;
        else
            ans = max(ans, k * i - cost);
        // cerr << ans << " ";
    }
    // cerr << endl;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}