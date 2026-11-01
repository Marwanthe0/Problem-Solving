#include <bits/stdc++.h>
using namespace std;
#define int long long
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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    reverse(all(v));
    long double l = *min_element(all(v)), r = *max_element(all(v)), ans = l;
    auto ok = [&](long double target) {
        long double rem = 0;
        for (auto vl : v) {
            if (vl >= target)
                rem += vl - target;
            else {
                long double req = target - vl;
                req = req + req * ((long double)k / (100 - k));
                // cerr << vl << " " << rem << " " << req << endl;
                if (rem >= req) {
                    rem -= req;
                } else
                    return false;
            }
        }
        return true;
    };
    while (r - l > 1e-6) {
        long double mid = l + (r - l) / 2;
        if (ok(mid)) {
            l = mid, ans = mid;
        } else
            r = mid;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}