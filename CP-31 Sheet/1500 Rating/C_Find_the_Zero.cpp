#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    if (!(cin >> x) || x == -1)
        exit(0);
    return x;
}
void marwan() {
    int n;
    if (!(cin >> n))
        exit(0);
    int op = n + 1;
    if (ask(1, 2)) {
        cout << "! " << 1 << endl;
        return;
    } else if (ask(2, 3)) {
        cout << "! " << 2 << endl;
        return;
    } else if (ask(1, 3)) {
        cout << "! " << 1 << endl;
        return;
    }
    op -= 3;
    int x = 4;
    for (int i = 0; i < op; i++, x += 2) {
        if (ask(x, x + 1)) {
            cout << "! " << x << endl;
            return;
        }
    }
    cout << "! " << 2 * n << endl;
}
int32_t main() {
    int t;
    if (!(cin >> t))
        return 0;
    while (t--) {
        marwan();
    }
    return 0;
}