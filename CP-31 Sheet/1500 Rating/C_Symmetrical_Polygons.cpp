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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    int count = 0;
    map<int, int> m, even;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    vector<int> odd;
    odd.push_back(0);
    for (auto &[x, y] : m) {
        if (y & 1) {
            odd.push_back(x);
            y--;
        }
        if (y != 0 && (y % 2) == 0)
            even[x] = y;
    }
    sort(all(odd), greater<int>());
    int ans = 0;
    for (auto [x, y] : even) {
        ans += y * x;
        count += y;
    }
    for (int i = 0; i + 1 < odd.size(); i++) {
        if ((odd[i] - odd[i + 1]) < (ans)) {
            cout << ans + (odd[i]) + odd[i + 1] << endl;
            return;
        }
    }
    int curans = ans;
    if (odd.size() == 1) {
        for (auto [x, y] : even) {
            int tans = curans - 2 * (x);
            if (x < tans)
                ans = max(ans, tans + x);
        }
        int last = -1;
        for (auto [x, y] : even) {
            if (last == -1) {
                last = x;
                continue;
            }
            int tans = curans - (2 * x + 2 * last);
            if (x - last < tans)
                ans = max(tans, ans);
        }
    }
    if (count <= 2)
        cout << 0 << endl;
    else
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