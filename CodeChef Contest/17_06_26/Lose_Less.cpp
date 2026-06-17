#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m;
    cin >> n >> m;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        int x = n - i;
        for (int j = 0; j <= x; j++) {
            if ((j * 3 + (x - j)) == m) {
                // cerr << i << " " << j << " " << x << endl;
                ans = min(ans, i);
            }
        }
    }
    // cerr << endl;
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