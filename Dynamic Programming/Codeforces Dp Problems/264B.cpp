#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 100000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<vector<int32_t>> divs(N + 5);
vector<int> mx(N + 5, 0);
void pre() {
    for (int i = 2; i <= N; i++) {
        if (divs[i].empty()) {
            for (int j = i; j <= N; j += i) {
                divs[j].push_back(i);
            }
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        // cerr << v[i] << endl;
        for (auto d : divs[v[i]]) {
            // cerr << d << " ";
            dp[i] = max(dp[i], mx[d] + 1);
        }
        for (auto d : divs[v[i]])
            mx[d] = max(dp[i], mx[d]);
        // cerr << endl;
        // cout << dp[i] << " ";
    }
    cout << *max_element(all(dp)) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    pre();
    marwan();
    return 0;
}