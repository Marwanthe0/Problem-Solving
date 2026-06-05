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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        int aage = (i - v[i]) - 1, pore = i + v[i];
        if (aage >= 0)
            dp[i] = (dp[i] | dp[aage]);
        if (dp[i - 1] && pore <= n)
            dp[pore] = (dp[pore] | dp[i - 1]);
        cerr << dp[i] << " ";
    }
    cerr << endl;
    // cerr << dp[n + 1] << endl;
    if (dp[n])
        yes;
    else
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