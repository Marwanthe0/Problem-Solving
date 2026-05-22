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
    string s;
    cin >> s;
    vector<int> a(n), c(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : c)
        cin >> vl;
    if (!is_sorted(all(c))) {
        no;
        return;
    }
    if (s[i] == '1' && a[i] != c[i]) {
        no;
        return;
    }
    vector<int> low(n, INT_MAX), up(n, INT_MIN);
    low[0] = up[0] = c[0];
    for (int i = 1; i < n; i++) {
        if (c[i] != c[i - 1]) {
            if (s[i] == '1') {
                low[i] = low[i - 1] + a[i];
                up[i] = up[i - 1] + a[i];
            } else {
                
            }
        }
    }
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