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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    int a = 0, b = 0, sum = 0ll;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            sum += v[i][j];
            if (i == 0 || j == m - 1)
                a += v[i][j];
            if (j == 0 || i == n - 1)
                b += v[i][j];
        }
    }
    if (n == 1 || m == 1) {
        cout << sum << endl;
        return;
    }
    int c = v[0][0];
    int d = v[0][0];
    for (int i = 1; i < m; i++) {
        c += v[1][i];
    }
    for (int i = 2; i < n; i++) {
        c += v[i][m - 1];
    }

    for (int i = 1; i < n; i++)
        d += v[i][1];
    for (int i = 2; i < m; i++)
        d += v[n - 1][i];

    int e = 0, g = b + v[n - 2][1], h = a + v[1][m - 2];
    for (int i = 0; i < n; i++)
        e += v[i][0];
    for (int i = 1; i < m; i++)
        e += v[n - 2][i];
    e += v[n - 1][m - 1];

    int f = 0;
    for (int i = 0; i < m; i++)
        f += v[0][i];
    for (int i = 1; i < n; i++)
        f += v[i][m - 2];
    f += v[n - 1][m - 1];
    // cerr << c << " " << d << " " << e << " " << f << endl;
    cout << max({a, b, c, d, e, f, g, h}) << endl;
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