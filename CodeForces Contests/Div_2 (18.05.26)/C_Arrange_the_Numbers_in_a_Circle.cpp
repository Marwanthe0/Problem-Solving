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
    vector<int> v(n), valid;
    int ans = 0ll, one = 0ll, mx = 0ll;
    for (auto &vl : v) {
        cin >> vl;
        if (vl >= 2) {
            valid.push_back(vl);
            mx = max(mx, vl);
            ans += vl;
        } else
            one++;
    }
    if (valid.size() == 1)
        ans += min(one, mx / 2);
    else {
        for (int i = 0; i < valid.size(); i++) {
            // if (i == valid.size() - 1) {

            // } else {
            int x = max(0ll, min(one, (valid[i] - 2) / 2));
            one -= x;
            ans += x;
            // }
        }
    }
    if (ans <= 2)
        ans = 0;
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