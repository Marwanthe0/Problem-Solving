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
int n;
vector<int> v, nxt, nxto, dp;
// map<pair<int, int>, int> dp;
int f(int i) {
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int shamne = nxt[i], shamneo = nxto[i];
    if (shamne == n)
        shamne = v[i];
    else {
        shamne = f(shamne);
    }
    if (shamneo == n)
        shamneo = v[i];
    else {
        shamneo = f(shamneo) + v[i];
    }
    return dp[i] = max(shamne, shamneo);
}
void marwan() {
    cin >> n;
    v.assign(n, 0);
    for (auto &vl : v)
        cin >> vl;
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    nxt.assign(n + 1, n);
    dp.assign(n + 1, -1);
    nxto.assign(n + 1, n);
    vector<int> pos(n + 1, 0);
    int nop = n;
    for (int i = n - 1; i >= 0; i--) {
        nxto[i] = nop;
        pos[v[i]] = i;
        if (v[i] == 1)
            nop = i;
        if (v[i] < n && pos[v[i] + 1])
            nxt[i] = pos[v[i] + 1];
    }
    // for (int i = 0; i < n; i++) {
    //     cerr << nxt[i] << " ";
    // }
    // cerr << endl;
    // for (int i = 0; i < n; i++) {
    //     cerr << nxto[i] << " ";
    // }
    // cerr << endl;
    // cerr << endl;
    // return;
    int idx = 0;
    while (idx < n && v[idx] != 1)
        idx++;
    int ans = f(idx);
    // for (auto vl : dp)
    //     cerr << vl << " ";
    // cerr << endl;
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