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
int n, k;
vector<int> v;
void marwan(int cs) {
    cin >> n >> k;
    v.assign(n, 0);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    v.insert(v.begin(), 0);
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = i - 2; j >= 1; j--) {
            if (v[i] - v[j] <= 2 * k)
                dp[i] = min(dp[i], dp[j - 1] + 1);
            else
                break;
        }
    }
    if (dp[n] < 1e9)
        cout << dp[n] << endl;
    else
        minus;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}