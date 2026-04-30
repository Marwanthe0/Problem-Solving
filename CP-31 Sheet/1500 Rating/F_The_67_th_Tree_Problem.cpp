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
    int x, y;
    cin >> x >> y;
    if (x > y || (x == 0 && y % 2 == 0)) {
        no;
        return;
    }
    yes;
    if (abs(x - y) & 1) {
        int a = 2, b = x + 2;
        for (int i = 0; i < x; i++) {
            cout << 1 << " " << a << endl;
            cout << a << " " << b << endl;
            a++, b++;
        }
        y -= x;
        y--;
        while (y--) {
            cout << 1 << " " << b << endl;
            b++;
        }
    } else {
        int a = 2, b = x + 1;
        for (int i = 1; i < x; i++) {
            cout << 1 << " " << a << endl;
            cout << a << " " << b << endl;
            a++, b++;
        }
        y -= x;
        y++;
        while (y--) {
            cout << 1 << " " << b << endl;
            b++;
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