#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), pf(n, 0);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (int i = 0; i < n; i++)
        pf[i] += v[i] + (i ? pf[i - 1] : 0);
    int ans = 1, ansval = v[0];
    auto ok = [&](int l, int r, int x) {
        int sum = x * (r - l + 1);
        sum = sum - (pf[r] - (l ? pf[l - 1] : 0));
        return sum <= k;
    };

    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1, tans = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ok(mid, i - 1, v[i])) {
                r = mid - 1, tans = max(tans, i - mid + 1);
            } else
                l = mid + 1;
        }
        if (tans > ans)
            ans = tans, ansval = v[i];
    }
    cout << ans << " " << ansval << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}