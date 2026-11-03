#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<int> v;
vector<vector<int>> divs;
void pre() {
    divs.assign(N + 1, vector<int>());
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i)
            divs[j].push_back(i);
    }
}
void marwan() {
    cin >> n;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (auto d : divs[i]) {
            if (v[d] < v[i])
                dp[i] = max(dp[i], dp[d] + 1);
        }
    }
    cout << *max_element(all(dp)) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}