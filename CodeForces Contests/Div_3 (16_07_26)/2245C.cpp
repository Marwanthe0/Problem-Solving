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
    int n, k;
    cin >> n >> k;
    if (__lg(k) > __lg(n)) {
        no;
        return;
    }
    int x = n ^ k;
    multiset<int> t;
    for (int i = __lg(x); i >= 0; i--) {
        // cout << (1 & (x >> i));
        if (1 & (x >> i))
            t.insert(1ll << i);
    }
    // cout << endl;
    // for (auto vl : t)
    //     cout << vl << " ";
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (!t.count(i))
            ans.push_back(i);
    }
    for (auto vl : t) {
        if (vl >= n) {
            no;
            return;
        }
        ans.push_back(vl);
    }
    int xr = 0ll, mex = 0;
    vector<int> vis(n, 0);
    for (auto vl : ans) {
        vis[vl]++;
        while (mex < n && vis[mex])
            mex++;
        // cerr << mex << " ";
        xr ^= mex;
    }
    // cerr << endl;
    if (xr != k) {
        no;
        return;
    }
    yes;
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