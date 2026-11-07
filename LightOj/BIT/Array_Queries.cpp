#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())

class SparseTable {
    int n, K;

    vector<int> lg;
    vector<vector<int>> mn, mx, sm;

  public:
    SparseTable(vector<int> &a) {
        n = a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        K = lg[n] + 1;
        mn.assign(K, vector<int>(n));
        mx.assign(K, vector<int>(n));
        sm.assign(K, vector<int>(n));
        // Level 0
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i];
            mx[0][i] = a[i];
            sm[0][i] = a[i];
        }
        // Build Sparse Table
        for (int k = 1; k < K; k++) {
            int len = (1 << k), half = (1 << (k - 1));
            for (int i = 0; i + len <= n; i++) {
                mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + half]);

                mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + half]);

                sm[k][i] = sm[k - 1][i] + sm[k - 1][i + half];
            }
        }
    }
    // Range Minimum
    int queryMin(int l, int r) {
        int k = lg[r - l + 1];
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    }
    // Range Maximum
    int queryMax(int l, int r) {
        int k = lg[r - l + 1];
        return max(mx[k][l], mx[k][r - (1 << k) + 1]);
    }
    // Range Sum
    int querySum(int l, int r) {
        int ans = 0;
        while (l <= r) {
            int k = lg[r - l + 1];
            ans += sm[k][l];
            l += (1 << k);
        }
        return ans;
    }
};

void marwan(int cs) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    SparseTable st(v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.queryMin(l, r) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}