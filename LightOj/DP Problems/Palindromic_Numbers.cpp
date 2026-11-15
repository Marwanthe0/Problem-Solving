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
int x, y;
string a, b;
int n;
int dp[20][20][2][2];
int f(int i, int start, bool tight, bool lz, string &s, string &t) {
    if (i == n) {
        return 1;
    }
    if (dp[i][start][tight][lz] != -1)
        return dp[i][start][tight][lz];
    int ans = 0, high = tight ? s[i] - '0' : 9;

    for (int d = 0; d <= high; d++) {
        bool nlz = lz && (d == 0);
        int nstart = start;
        if (nlz == 0 && nstart == n)
            nstart = i;
        if (nlz == 0) {
            int l = nstart, r = n - 1;
            int mid = l + (r - l) / 2;
            if (i > mid) {
                int mirror = l + (r - i);
                // cerr << l << " " << r << " " << mid << " " << d << " " << t[mirror] << " " << mirror << endl;
                // cerr << t << " " << nlz << " " << nstart << endl;
                if (d + '0' != t[mirror])
                    continue;
            }
        }
        t.push_back(d + '0');
        ans += f(i + 1, nstart, tight && d == high, nlz, s, t);
        t.pop_back();
    }
    return dp[i][start][tight][lz] = ans;
}
void marwan(int cs) {
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    x--;
    a = to_string(x);
    b = to_string(y);
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    n = a.size();
    string t = "";
    memset(dp, -1, sizeof(dp));
    int ans = f(0, n, 1, 1, b, t);
    memset(dp, -1, sizeof(dp));
    int ans2 = x >= 0 ? f(0, n, 1, 1, a, t) : 0;
    cout << ans - ans2 << endl;
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