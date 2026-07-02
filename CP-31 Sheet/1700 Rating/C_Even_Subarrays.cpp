#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 2e6
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
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    int ans = 0ll;
    for (auto &vl : v) {
        cin >> vl;
        mx = max(mx, vl);
        // if ((int)(sqrt(vl)) * (int)(sqrt(vl)) == vl)
        //     ans++;
    }
    vector<int> m(2 * n + 1, 0);
    m[0]++;
    int x = 0;
    for (int i = 0; i < n; i++) {
        x ^= v[i];
        // cerr << x << " ";
        // ans += m[x];
        for (int j = 0; j * j <= 2 * n; j++) {
            if (((j * j) ^ x) <= (2 * n))
                ans += m[(j * j) ^ x];
            // cerr << j * j << " " << m[(j * j) ^ x] << endl;
        }
        // cerr << endl;
        m[x]++;
    }
    // cerr << endl;
    // cerr << endl;
    cout << ((n * (n + 1)) / 2) - ans << endl;
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