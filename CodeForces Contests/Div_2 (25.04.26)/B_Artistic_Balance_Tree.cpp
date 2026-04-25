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
    int sum = 0ll;
    for (auto &vl : v) {
        cin >> vl;
        sum += vl;
    }
    multiset<int, greater<int>> ms1, ms2;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ms1.insert(v[i]);
        } else
            ms2.insert(v[i]);
    }
    bool flag1 = true, flag2 = true, t1 = false, t2 = false;
    while (k--) {
        int x;
        cin >> x;
        x--;
        if (x & 1) {
            t1 = true;
            if (!ms1.empty() && *ms1.begin() >= 0) {
                flag1 = false;
                sum -= *ms1.begin();
                ms1.erase(ms1.begin());
            }
        } else {
            t2 = true;
            if (!ms2.empty() && *ms2.begin() >= 0) {
                flag2 = false;
                sum -= *ms2.begin();
                ms2.erase(ms2.begin());
            }
        }
    }
    // cerr << flag1 << " " << flag2 << endl;
    // cerr << sum << endl;
    if (flag1 && t1 && ms1.size())
        sum -= *ms1.begin();
    if (flag2 && t2 && ms2.size())
        sum -= *ms2.begin();
    cout << sum << endl;
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