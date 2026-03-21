#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define aint(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(aint((x)));   \
    (x).erase(unique(aint((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    auto que = [&](int i, int j) {
        cout << "? " << i << " " << j << '\n'
             << flush;
        int x;
        cin >> x;
        if (x == -1)
            exit(0);
        return x;
    };
    if (n == 2) {
        if (que(1, 2)) {
            cout << "! " << 1 << '\n'
                 << flush;
            return;
        } else if (que(1, 3)) {
            cout << "! " << 1 << '\n'
                 << flush;
            return;
        } else if (que(2, 3)) {
            cout << "! " << 2 << '\n'
                 << flush;
            return;
        } else {
            cout << "! " << 4 << '\n'
                 << flush;
            return;
        }

    } else if (n == 3) {
        if (que(1, 2)) {
            cout << "! " << 1 << '\n'
                 << flush;
            return;
        } else if (que(1, 3)) {
            cout << "! " << 1 << '\n'
                 << flush;
            return;
        } else if (que(2, 3)) {
            cout << "! " << 2 << '\n'
                 << flush;
            return;
        } else if (que(4, 5)) {
            cout << "! " << 4 << '\n'
                 << flush;
            return;
        } else {
            cout << "! " << 6 << '\n'
                 << flush;
            return;
        }

    } else {
        int x = 1, y = n + 1;
        for (int i = 1; i < n; i++, x++, y++) {
            if (que(x, y)) {
                cout << "! " << x << '\n'
                     << flush;
                return;
            }
        }
        if (que(1, (2 * n))) {
            cout << "! " << 1 << '\n'
                 << flush;
            return;
        } else {
            cout << "! " << 2 << '\n'
                 << flush;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}