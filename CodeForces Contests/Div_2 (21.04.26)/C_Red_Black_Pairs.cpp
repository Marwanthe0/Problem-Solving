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
    string a, b;
    cin >> a;
    cin >> b;
    vector<int> dp(n + 2, INT_MAX);
    dp[0] = 0;
    dp[1] = (a[0] != b[0]);
    for (int i = 2; i <= n; i++) {
        int ekta = dp[i - 1] + (a[i - 1] != b[i - 1]);
        int duita = dp[i - 2] + (a[i - 1] != a[i - 2]) + (b[i - 1] != b[i - 2]);
        dp[i] = min(ekta, duita);
    }
    cout << dp[n] << endl;
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