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
string a, b;
int n;
int dp[10][2][2][2][10];
int f(int i, bool ltight, bool tight, bool lz, int cnt) {
    if (i == n)
        return cnt;

    if (dp[i][ltight][tight][lz][cnt] != -1)
        return dp[i][ltight][tight][lz][cnt];

    int ans = 0;
    int low = ltight ? a[i] - '0' : 0;
    int high = tight ? b[i] - '0' : 9;

    for (int d = low; d <= high; d++) {
        bool nlz = lz && d == 0;
        ans += f(i + 1, ltight && (d == low), tight && (d == high), nlz, cnt + (nlz == 0 && d == 0));
    }

    return dp[i][ltight][tight][lz][cnt] = ans;
}
void marwan(int cs) {
    cin >> a >> b;
    int x = a == "0";
    while (a.size() < b.size())
        a = '0' + a;
    n = b.size();
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 1, 1, 1, 0);
    cout << ans + x << endl;
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