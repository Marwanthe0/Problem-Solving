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
    int n, k, lower, upper;
    cin >> n >> k >> lower >> upper;
    lower = max(k, lower);
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = 0, ans = 0;
    unordered_map<int, int> m;
    while (r < n) {
        m[v[r]]++;
        while (m.size() > k) {
            // if (r - l + 1 >= lower && r - l + 1 <= upper) {
            //     ans++;
            // }
            ans++;
            m[v[l]]--;
            if (m[v[l]] <= 0)
                m.erase(v[l]);
            l++;
        }
        if (m.size() == k) {
            cout << l << " " << r << endl;
        }
        r++;
    }
    cout << endl;
    // cout << ans << endl;
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