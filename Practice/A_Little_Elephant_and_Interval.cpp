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
int dp[22][10][2][2][11];
int solve(int a) {
    string s = to_string(a);
    int n = s.size();
    if (n == 1)
        return s[0] - '0';
    for (int a = 0; a < 22; a++) {
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 2; c++)
                for (int d = 0; d < 2; d++)
                    for (int e = 0; e < 11; e++)
                        dp[a][b][c][d][e] = -1;
    }
    function<int(int, int, bool, bool, int)> f = [&](int i, int x, bool is_tight, bool firstflag, int first) -> int {
        if (i == n)
            return x == first;
        if (dp[i][x][is_tight][firstflag][first] != -1)
            return dp[i][x][is_tight][firstflag][first];
        int ways = 0ll;
        int lim = is_tight ? s[i] - '0' : 9;
        for (int j = 0; j <= lim; j++) {
            ways += f(i + 1, j, is_tight && (j == lim), firstflag || (j != 0), (firstflag) ? first : (j ? j : first));
        }
        return dp[i][x][is_tight][firstflag][first] = ways;
    };
    return f(0, 0, true, false, -1);
}
void marwan() {
    int a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}