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
int n, w, k;
vector<int> v;
map<int, int> m;
vector<vector<int>> dp;
int f(int i, int rem) {
    if (i >= n)
        return 0;
    if (dp[i][rem] != -1)
        return dp[i][rem];
    int ans = f(i + 1, rem), sum = m[v[i]], j = i + 1;
    if (rem > 0) {
        for (; j < n; j++) {
            if (v[j] - v[i] <= w)
                sum += m[v[j]];
            else
                break;
        }
        int tval = f(j, rem - 1);
        ans = max(ans, sum + tval);
    }
    return dp[i][rem] = ans;
}
void marwan(int cs) {
    v.clear();
    m.clear();
    cin >> n >> w >> k;
    for (int i = 0; i < n; i++) {
        int kajer_na, x;
        cin >> kajer_na >> x;
        v.push_back(x);
        m[x]++;
    }
    make_unique(v);
    n = v.size();
    dp.assign(n + 1, vector<int>(k + 1, -1));
    cout << f(0, k) << endl;
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