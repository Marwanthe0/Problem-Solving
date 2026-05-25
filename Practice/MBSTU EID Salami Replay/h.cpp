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
vector<int> v;
int sum;
int n;
int dp[16][1 << 16][4];
bool f(int i, int mask, int x, int count) {
    if (count == 2)
        return true;
    if (x == 0) {
        return f(n - 1, mask, sum / 3, count + 1);
    }
    if (i < 0)
        return false;
    if (dp[i][mask][count] != -1)
        return dp[i][mask][count];
    bool nitamna = f(i - 1, mask, x, count);
    bool nimu = false;
    if (x >= v[i] && ((mask >> i) & 1) == 0)
        nimu = f(i - 1, mask | (1 << i), x - v[i], count);

    return dp[i][mask][count] = (nimu || nitamna);
}
void marwan() {
    cin >> n;
    v.resize(n, 0);
    for (auto &vl : v)
        cin >> vl;
    sum = accumulate(all(v), 0ll);
    int x = sum / 3;
    if (sum % 3) {
        no;
        return;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (1 << n); j++) {
            for (int k = 0; k <= 3; k++)
                dp[i][j][k] = -1;
        }
    }

    bool ans = f(n - 1, 0, x, 0);
    if (ans)
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