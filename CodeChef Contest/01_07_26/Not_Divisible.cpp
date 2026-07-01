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
    vector<int> v(n);
    int x = n + 1;
    for (auto &vl : v)
        cin >> vl;
    bool flag = true;
    int xx = INT_MIN;
    for (int i = 0; i < n; i++) {
        // cerr << x - v[i] << " ";
        if (xx != INT_MIN && xx != (x - v[i])) {
            flag = false;
        }
        xx = x - v[i];
    }
    // cerr << endl;
    if (flag) {
        minus;
        return;
    }
    vector<int> pf(n, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] == v[i + 1])
            pf[i] = pf[i + 1];
        else
            pf[i] = i + 1;
    }
    pf.back() = n;
    // for (auto vl : pf)
    //     cout << vl << " ";
    // cout << endl;
    int idx = 1, i = 0;
    vector<int> vis(n + 1, 0), ans(n, 0);
    int count = 0;
    while (idx <= n) {
        while ((v[i] + idx) == (n + 1)) {
            i = pf[i];
            if (i == n)
                i = 0;
        }
        while (1) {
            while (vis[i]) {
                i++;
                if (i == n)
                    i = 0;
            }
            while (v[i] + idx == (n + 1)) {
                i = pf[i];
                if (i == n)
                    i = 0;
            }
            if (vis[i] == 0 && (v[i] + idx) != (n + 1))
                break;
        }
        vis[i] = 1;
        ans[i] = idx;
        idx++;
        count++;
        if (count > n)
            break;
    }
    for (auto vl : ans)
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