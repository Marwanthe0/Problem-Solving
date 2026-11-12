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
vector<int> dp;
int f(int i, vector<int> &v) {
    if (i >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = f(i + 1, v);
    ans = max(ans, v[i] + f(i + 2, v));
    return dp[i] = ans;
}
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> t = v;
    v.pop_back();
    t.erase(t.begin());
    dp.assign(n, -1);
    int ans = f(0, v);
    dp.assign(n, -1);
    ans = max(ans, f(0, t));
    cout << ans << endl;
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