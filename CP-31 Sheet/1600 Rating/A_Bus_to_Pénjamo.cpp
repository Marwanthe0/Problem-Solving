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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int ans = 0;
    for (auto &vl : v) {
        cin >> vl;
        k -= vl / 2;
        ans += (vl / 2) * 2;
        vl %= 2;
    }
    int remsum = accumulate(all(v), 0ll);
    if (remsum > k) {
        remsum = 2 * k - remsum;
    }
    cout << ans + remsum << endl;
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