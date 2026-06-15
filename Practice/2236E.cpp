#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> ans((n / 2) + 1, vector<int>(n + 1, 0)), mni(n, vector<int>(n, 0)), mxi(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int mx = v[i], mn = v[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, v[j]), mx = max(mx, v[j]);
            mni[i][j] = mn, mxi[i][j] = mx;
        }
    }
    int uttor = 0;
    for (int i = n / 2; i >= 1; i--) {
        int l = 0, r = 0;
        vector<int> vis(n + 1, 0);
        bool flag = false;
        int unique = 0;
        while (r < n) {
            if (!vis[v[r]])
                unique++;
            vis[v[r]]++;
            if (r - l + 1 == i) {
                int mn = mni[l][r], mx = mxi[l][r];
                if (mx - mn + 1 == unique && mx - mn + 1 == i) {
                    ans[i][mx] = 1;
                    if ((mx - i >= 0 && ans[i][mx - i]) || (mx + i <= n && ans[i][mx + i])) {
                        uttor = max(uttor, i);
                        flag = true;
                    }
                }
                vis[v[l]]--;
                if (vis[v[l]] <= 0)
                    unique--;
                l++;
            }
            r++;
        }
        if (flag)
            break;
    }
    cout << uttor << endl;
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