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
int ck(int n, unordered_set<int> &check) {
    for (int i = 0; i <= n; i++) {
        if (!check.count(i))
            return i;
    }
    return n;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    int a = -1, b;
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        if (v[i] == 0 && a == -1) {
            a = i;
        } else if (v[i] == 0)
            b = i;
    }
    int ans = 1;
    int i = a, j = b;
    // cerr << i << " " << j << endl;
    int ti = i, tj = j;
    unordered_set<int> check;
    while (ti <= tj) {
        if (v[ti] != v[tj]) {
            break;
        } else {
            check.insert(v[ti]);
            ti++, tj--;
        }
    }
    if (ti > tj) {
        while (ti >= 0 && tj < 2 * n) {
            if (v[ti] != v[tj]) {
                break;
            } else {
                check.insert(v[ti]);
                ti--, tj++;
            }
        }
        ans = max(ans, ck(n, check));
    }
    check.clear();
    ti = i, tj = i;
    while (ti >= 0 && tj < 2 * n) {
        if (v[ti] != v[tj]) {
            break;
        } else {
            check.insert(v[ti]);
            ti--, tj++;
        }
    }
    ans = max(ans, ck(n, check));
    check.clear();
    ti = j, tj = j;
    while (ti >= 0 && tj < 2 * n) {
        if (v[ti] != v[tj]) {
            break;
        } else {
            check.insert(v[ti]);
            ti--, tj++;
        }
    }
    ans = max(ans, ck(n, check));
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