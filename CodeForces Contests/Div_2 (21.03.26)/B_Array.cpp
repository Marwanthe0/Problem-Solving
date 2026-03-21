#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void marwan() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        int lnt = 0, gnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                lnt++;
            else if (a[j] > a[i])
                gnt++;
        }
        ans[i] = max(lnt, gnt);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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