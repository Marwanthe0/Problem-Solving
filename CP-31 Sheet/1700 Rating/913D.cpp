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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b <= k)
            v.push_back({{a, b}, i + 1});
    }
    sort(all(v));
    int l = 0, r = n, ans = 0;
    vector<int> vans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool ok = false;
        vector<pair<int, int>> tans;
        for (auto vl : v) {
            int i = vl.first.first, j = vl.first.second, y = vl.second;
            if (i < mid)
                continue;
            tans.push_back({j, y});
        }
        sort(all(tans));
        if ((int)tans.size() >= mid) {
            int tsum = 0ll;
            for (int i = 0; i < min(mid, (int)tans.size()); i++) {
                int fs = tans[i].first;
                tsum += fs;
            }
            if (tsum <= k) {
                ok = true;
                vans.resize(mid, 0);
                for (int i = 0; i < min(mid, (int)tans.size()); i++) {
                    int ss = tans[i].second;
                    vans[i] = ss;
                }
            }
        }
        // cerr << mid << " " << ok << endl;
        if (ok)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    cout << vans.size() << endl;
    for (auto vl : vans)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}