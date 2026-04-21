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
    auto ok = [&](int m) {
        int count = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (v[i] <= m)
                continue;
            if (s[i] == 'B' && flag == false) {
                flag = true;
            } else if (s[i] == 'R' && flag == true)
                flag = false, count++;
        }
        if (flag)
            count++;
        return count <= k;
    };
    int l = 0, r = *max_element(all(v)), ans = r;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (ok(m)) {
            ans = m, r = m - 1;
        } else
            l = m + 1;
    }
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