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
    int x = 1;
    if (m % k) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << x << " ";
                x++;
                x %= k;
                if (!x)
                    x = k;
            }
            cout << endl;
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            x = (i + 1) % k;
            if (!x)
                x = k;
            for (int j = 0; j < m; j++) {
                cout << x << " ";
                x++;
                x %= k;
                if (!x)
                    x = k;
            }
            cout << endl;
        }
        cout << endl;
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