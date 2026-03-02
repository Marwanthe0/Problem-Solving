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
    int mn = INT_MAX, mx = INT_MIN;
    for (auto &vl : v) {
        cin >> vl;
        mn = min(mn, vl);
        mx = max(mx, vl);
    }
    int dif = mx - mn;
    if (abs(mn) >= dif || abs(mx) >= dif) {
        no;
        return;
    }
    sort(all(v));
    int l = 0, r = n - 1, lsum = 0, rsum = 0;
    yes;
    while (l <= r) {
        if (lsum <= rsum) {
            cout << v[l] << " ";
            lsum += abs(v[l]);
            l++;
        } else {
            cout << v[r] << " ";
            rsum += abs(v[r--]);
        }
    }
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