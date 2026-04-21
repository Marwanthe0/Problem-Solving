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
    int n, m, k;
    cin >> n >> m >> k;
    if (abs(n - m) > k || max(n, m) < k) {
        minus;
        return;
    }
    int tk = k, tn = n, tm = m, flag = n > m ? 0 : 1;
    for (int i = 0; i < (n + m); i++) {
        cout << flag;
        tk--;
        if (flag == 0)
            tn--;
        else
            tm--;
        if (tk == 0)
            tk = k, flag = !flag;
        if (tn == 0 || tm == 0)
            break;
    }
    while (tn--)
        cout << 0;
    while (tm--)
        cout << 1;
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