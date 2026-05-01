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
void marwan() {
    int x, y;
    cin >> x >> y;
    if (x > y || ((y - x) > 0 && ((y - x) % 2 != 0))) {
        cout << -1 << endl;
        return;
    }
    y = (y - x) / 2ll;
    vector<int> ans;
    int mx = max(__lg(x), __lg(y));
    for (int i = 0; i <= mx; i++) {
        int a = (1ll & (x >> i)), b = (1ll & (y >> i));
        if (a && b) {
            while (ans.size() < 3)
                ans.push_back(0ll);
            for (auto &vl : ans)
                vl |= (1ll << i);
        } else if (a) {
            while (!ans.size())
                ans.push_back(0ll);
            ans[0] |= (1ll << i);
        } else if (b) {
            while (ans.size() < 2)
                ans.push_back(0ll);
            ans[0] |= (1ll << i);
            ans[1] |= (1ll << i);
        }
    }
    cout << ans.size() << endl;
    if (ans.size()) {
        for (auto vl : ans)
            cout << vl << " ";
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}