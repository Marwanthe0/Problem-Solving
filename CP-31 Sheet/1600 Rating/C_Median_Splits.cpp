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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> gpr(n), lpr(n,INT_MAX), gsr(n), lsr(n);
    int countGreater = 0, countLess = 0, countGreaterr = 0, countLessr = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (v[i] > k)
            countGreater++;
        else
            countLess++;
        gpr[i] += (countLess - countGreater);

        if (v[j] > k)
            countGreaterr++;
        else
            countLessr++;
        gsr[j] += (countLessr - countGreaterr);
    }
    // for (auto vl : gpr)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : gsr)
    //     cerr << vl << " ";
    // cerr << endl;
    int mx = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (gpr[i] >= mx) {
            // cout << "t1" << endl;
            yes;
            return;
        }
        if (gpr[i] >= 0)
        mx = min(mx, gpr[i]);
    }
    mx = INT_MAX;
    for (int i = n - 1; i > 0; i--) {
        if (gsr[i] >= mx) {
            // cout << "t2" << endl;
            yes;
            return;
        }
        if (gsr[i] >= 0)
        mx = min(mx, gsr[i]);
        if (i == n - 1) {
            lpr[i] = gsr[i];
        } else
        lpr[i] = max(lpr[i + 1], gsr[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        if (gpr[i] >= 0 && lpr[i + 2] >= 0) {
            // cout << "t3" << endl;
            yes;
            return;
        }
    }
    no;
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