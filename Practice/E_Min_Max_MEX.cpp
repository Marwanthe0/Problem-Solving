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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 1, r = min(n, *max_element(all(v)) + 1), ans = 0;
    auto ok = [&](int mex) {
        int partition = 0, count = 0;
        vector<int> vis(mex + 1, -1);
        int last = -1;
        for (int i = 0; i < n; i++) {
            // bool flag = true;
            // if (v[i] == count) {
            //     count++;
            //     flag = false;
            //     if (count == mex) {
            //         partition++, count = 0, last = i;
            //     }
            // }
            // while (m.count(count) && m[count] >= last) {
            //     count++;
            //     if (count == mex) {
            //         partition++, count = 0, last = i;
            //     }
            // }
            // if (flag)
            //     m[v[i]] = i;
            if (v[i] < mex && (vis[v[i]] <= last)) {
                count++;
            }
            if (count == mex) {
                count = 0, partition++, last = i;
            }
            if (v[i] < mex)
                vis[v[i]] = i;
        }
        return partition >= k;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int kk = ok(mid);
        // cerr << mid << "->" << kk << endl;
        if (kk) {
            ans = mid, l = mid + 1;
        } else
            r = mid - 1;
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