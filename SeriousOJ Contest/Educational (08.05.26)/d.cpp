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
    vector<int> a(n), b(n), c(n);
    for (auto &vl : a)
        cin >> vl;
    int lastb = INT_MIN, lastc = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] >= lastb && a[i] >= lastc) {
            b[i] = c[i] = lastb = lastc = a[i];
            if (a[i] > 1e9) {
                minus;
                return;
            }
        } else if (a[i] >= lastb) {
            b[i] = lastb = a[i];
            int x = ((lastc / a[i]) + (lastc % a[i] != 0)) * a[i];
            while (__gcd(x, b[i]) != a[i]) {
                x += a[i];
                if (x > 1e9) {
                    minus;
                    return;
                }
            }
            c[i] = lastc = x;
            if (x > 1e9 || lastb > 1e9) {
                minus;
                return;
            }
        } else if (a[i] >= lastc) {
            c[i] = lastc = a[i];
            int x = ((lastb / a[i]) + (lastb % a[i] != 0)) * a[i];
            while (__gcd(x, c[i]) != a[i]) {
                x += a[i];
                if (x > 1e9) {
                    minus;
                    return;
                }
            }
            b[i] = lastb = x;
            if (x > 1e9 || lastc > 1e9) {
                minus;
                return;
            }
        } else {
            int x = ((lastb / a[i]) + (lastb % a[i] != 0)) * a[i];
            int y = ((lastc / a[i]) + (lastc % a[i] != 0)) * a[i];
            while (__gcd(x, y) != a[i]) {
                if (x + a[i] <= 1e9 && (y + a[i] > 1e9 || x <= y)) {
                    x += a[i];
                } else {
                    y += a[i];
                }
                if (x > 1e9) {
                    minus;
                    return;
                }
            }
            if (x > 1e9 || y > 1e9) {
                minus;
                return;
            }
            b[i] = lastb = x;
            c[i] = lastc = y;
        }
    }
    for (auto vl : b)
        cout << vl << " ";
    cout << endl;
    for (auto vl : c)
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