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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pf;
    for (auto &vl : v) {
        cin >> vl;
        if (pf.size())
            pf.push_back(min(vl, pf.back()));
        else
            pf.push_back(vl);
    }
    vector<vector<int>> t(n, vector<int>(m));
    int ans = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[i][j];
        }
    }
    multiset<int, greater<int>> ms;
    int tsum = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (auto vl : t[i]) {
            ms.insert(vl);
            tsum += vl;
        }
        if (tsum < pf[i])
            continue;
        int l = 0, r = ms.size(), tans = ms.size();
        auto ok = [&](int mid) -> bool {
            int xsum = 0ll, idx = 0;
            for (auto vl : ms) {
                if (idx >= mid)
                    break;
                else {
                    xsum += vl;
                    if (xsum >= pf[i])
                        return true;
                }
                idx++;
            }
            return xsum >= pf[i];
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool kk = ok(mid);
            cerr << mid << " " << kk << endl;
            if (kk) {
                r = mid - 1, tans = mid;
            } else
                l = mid + 1;
        }
        ans = min(ans, tans);
        cerr << endl;
    }
    cerr << endl;
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