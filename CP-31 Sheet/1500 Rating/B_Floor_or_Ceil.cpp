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
    int x, n, m;
    cin >> x >> n >> m;
    int tx = x, tn = n, tm = m;
    for (int i = 0; i < tm; i++) {
        tx = (tx / 2) + (tx & 1);
        if (tx == 1 || tx == 0)
            break;
    }
    for (int i = 0; i < tn; i++) {
        tx /= 2;
        if (tx == 0)
            break;
    }
    cout << tx << " ";
    for (int i = 0; i < n; i++) {
        x = (x / 2);
        if (x == 0)
            break;
    }
    for (int i = 0; i < m; i++) {
        x = (x / 2) + (x & 1);
        if (x == 1 || x == 0)
            break;
    }
    cout << x << endl;
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