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

int dp[55][2][2];
int f(int i, bool tight, bool prev, int num) {
    if (i < 0)
        return 1;
    if (dp[i][tight][prev] != -1)
        return dp[i][tight][prev];

    int high = tight ? ((num >> i) & 1LL) : 1, ans = 0;
    for (int d = 0; d <= high; d++) {
        if (d && prev)
            continue;
        ans += f(i - 1, tight && (high == d), d, num);
    }
    return dp[i][tight][prev] = ans;
}

int ok(int mid) {

    int ans = f(__lg(mid), 1, 0, mid);
    return ans - 1;
}
void marwan(int n) {
    int l = 1, r = (1LL << 45), ans = -1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1ll);
        if (ok(mid) >= n) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
    }
    for (int i = __lg(ans); i >= 0; i--) {
        cout << ((ans >> i) & 1LL);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case " << i << ": ";
        marwan(n);
            cout << endl;
    }
    return 0;
}