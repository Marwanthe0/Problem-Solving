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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int sum = 0, mn = INT_MAX, cnt = 0, ans = 0;
    for (auto vl : v) {
        if (vl == 0) {
            // cerr << cnt << " " << sum << " " << mn << endl;
            if (cnt % 2 == 0) {
                ans += sum;
                sum = 0, mn = INT_MAX, cnt = 0;
            } else {
                ans += sum;
                sum = mn, cnt = 0;
            }
            // cerr << cnt << " " << sum << " " << mn << endl;
            continue;
        }
        sum += abs(vl);
        if (vl < 0)
            cnt++;
        mn = min(mn, abs(vl));
    }
    // cerr << cnt << " " << sum << " " << mn << endl;
    if (cnt % 2 == 0) {
        ans += sum;
    } else {
        ans += sum - (2 * mn);
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