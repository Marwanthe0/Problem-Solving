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
    int l, r;
    cin >> l >> r;
    vector<int> ans(r - l + 1);
    unordered_set<int> s;
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = -1;
        s.insert(l + i);
    }
    int mx = __lg(r), last = 0;
    for (int i = r; i >= l; i--) {
        int x = 0;
        if (ans[i - l] != -1) {
            last += ans[i - l] | i;
            continue;
        }
        for (int j = 0; j <= mx; j++) {
            if (!(1 & (i >> j))) {
                x = x | (1 << j);
            }
        }
        while (!s.count(x)) {
            x = x & ~(1 << __lg(x));
        }
        if (s.count(x)) {
            ans[i - l] = x;
            ans[x] = i;
            s.erase(i);
            s.erase(x);
        }
        last += (i | x);
    }
    cout << last << endl;
    for (auto vl : ans)
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