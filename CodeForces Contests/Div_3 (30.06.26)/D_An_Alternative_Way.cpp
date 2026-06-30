#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flush cout.flush()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    int diff = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (diff)
            a[i] += diff;

        if (a[i] > b[i]) {
            diff = a[i] - b[i];
        } else {
            diff = 0;
        }
    }

    if (diff)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}