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
    string s;
    cin >> s;
    int ans1 = 0;
    int mx = INT_MIN, mn = INT_MAX;
    int l = 0, r = n - 1;
    vector<pair<int, int>> cng;
    while (l <= r) {
        ans1 += abs(s[r] - s[l]);
        if (s[l] != s[r]) {
            if (s[l] > s[r])
                swap(s[l], s[r]);
            cng.push_back({s[l] - 'a', s[r] - 'a'});
        }
        l++, r--;
    }
    sort(all(cng));
    int ans = 0, mx2 = -1, mn2 = -1;
    for (auto [x, y] : cng) {
        // cerr << x << " " << y << endl;
        if (mx2 == -1) {
            mn2 = x, mx2 = y;
            continue;
        }
        if (x <= mx2)
            mx2 = max(mx2, y);
        else {
            ans += mx2 - mn2;
            mn2 = x, mx2 = y;
        }
    }
    ans += mx2 - mn2;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}