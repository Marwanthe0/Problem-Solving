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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> v[i][j];
    }
    int l = 0, r = n, ans = 0;
    auto ok = [&](int mid) {
        if (mid == 0)
            return true;
        int l = 1, r = mid, count = 0;
        for (int i = 0; i < n; i++) {
            if (l < v[i][0] || l > v[i][1]) {
                if (r < v[i][2] || r > v[i][3])
                    count++, l++, r--;
            }
            if (count >= mid)
                return true;
        }
        return count >= mid;
    };
    for (int i = n; i >= 1; i--) {
        if (ok(i)) {
            cout << i << endl;
            return;
        }
    }
    // cerr << endl;
    cout << ans << endl;
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