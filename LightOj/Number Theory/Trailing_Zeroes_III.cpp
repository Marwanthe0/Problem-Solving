#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    int n;
    cin >> n;
    int l = 1, r = INF, ans = 0;
    auto ok = [&](int x) {
        int y = 5, count = 0;
        while (y <= x)
            count += (x / y), y *= 5;
        return count;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid) >= n) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
    }
    if (ok(ans) == n) {
        cout << ans << endl;
    } else
        cout << "impossible" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}