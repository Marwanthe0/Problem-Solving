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
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     marwan();
    // }
    int n = 500;
    auto bt = [&](int x) {
        for (int i = 20; i >= 0; i--) {
            cout << (1 & (x >> i));
        }
        cout << endl;
    };
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((i ^ j) == 2 * (i & j)) {
                cout << i << " " << j << endl;
                vis[i] = 1;
                bt(i);
                bt(j);
                // bt(k);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // if (vis[i]) {
        //     sum++;
        // }
        // cout << i << " " << i - sum << endl;
        // // bt(i);
        // // bt(i - sum);
    }
    return 0;
}