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
    string s;
    cin >> s;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int mx = INT_MIN, cur = 0, mn = 0, sum = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // cerr << cur << " ";
            mx = max(mx, cur);
            cur = 0;
            sum = 0;
            mn = 0;
            zero++;
        } else {
            sum += v[i];
            mn = min(mn, sum);
            cur = max(cur, sum - mn);
        }
    }
    // cerr << cur << endl;
    mx = max(mx, cur);
    if (mx > k || (mx != k && zero == 0)) {
        no;
        return;
    }
    yes;
    unordered_map<int, pair<int, int>> ans;
    int last = -5;
    cur = 0ll, mx = 0ll;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (last != -5) {
                ans[last].second = mx;
            }
            last = i, cur = 0, mx = 0;
            continue;
        }
        cur += v[i];
        mx = max(cur, mx);
    }
    if (last != -5)
        ans[last].second = mx;
    cur = 0ll, mx = 0ll, last = -5;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            if (last != -5) {
                ans[last].first = mx;
            }
            last = i, cur = 0ll, mx = 0ll;
            continue;
        }
        cur += v[i];
        mx = max(cur, mx);
    }
    if (last != -5)
        ans[last].first = mx;
    int temp = k;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            v[i] = temp - (ans[i].first + ans[i].second);
            temp = 0;
        }
    }
    // for (auto &[x, y] : ans) {
    //     // cerr << x << "::" << y.first << " " << y.second << endl;
    //     v[x] = k - (y.first + y.second);
    //     k -= v[x];
    // }
    // // cerr << endl;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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