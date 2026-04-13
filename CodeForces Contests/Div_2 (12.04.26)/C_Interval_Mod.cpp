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

int f(int i, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &pfa, vector<int> &pfb, vector<int> &pfc, bool flag) {

    // a diye mod
    if (i - k >= -1)
        f(i - k, a, b, c, pfa, pfb, pfc) + (pfa[i] - (i - k >= 0 ? pfa[i - k] : 0));

    // b diye mode
    if (i - k >= -1) {
        f(i - k, a, b, c, pfa, pfb, pfc) + (pfb[i] - (i - k >= 0 ? pfb[i - k] : 0));
    }
    
}
void marwan() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<int> v(n), ta(n), tb(n), tc(n), td(n);
    if (a > b)
        swap(a, b);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ta[i] = v[i] % a;
        tb[i] = v[i] % b;
        tc[i] = (tb[i] % a);
    }
    for (auto vl : ta)
        cerr << vl << " ";
    cerr << endl;
    vector<int> pfa(n, 0ll), pfb(n, 0ll), pfc(n, 0ll);
    for (int i = 0; i < n; i++) {
        pfa[i] = i ? pfa[i - 1] : 0ll;
        pfa[i] += ta[i];

        pfb[i] = i ? pfb[i - 1] : 0ll;
        pfb[i] += tb[i];

        pfc[i] = i ? pfc[i - 1] : 0ll;
        pfc[i] += tc[i];
    }
    vector<int> dp(n + 1, -1);
    int ans = f(n - 1, ta, tb, tc, pfa, pfb, pfc);
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