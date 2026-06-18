#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - '0';
        dp[i][x]++;
        bool flag = true, tflag = true;
        int tx = x, count = 1;
        for (int j = i - 1; j > 0; j--) {
            if (s[j - 1] - '0' != x)
                flag = false;
            else if (flag)
                count++;
            if (flag) {
                if (pow(2, __lg(count)) == count) {
                    cerr << "Found";
                    if (__lg(count) % 2)
                        dp[i][!x]++;
                    else
                        dp[i][x]++;
                }
            }
            if (s[j - 1] - '0' == tx && tflag) {
                dp[i][!tx] += dp[j][tx];
                tx = !tx;
                tflag = false;
            } else if (flag == false)
                break;
            cerr << dp[i][0] << " " << dp[i][1] << " ";
            cerr << count << endl;
        }
        cerr << dp[i][0] << " " << dp[i][1] << endl;
        ans += dp[i][0] + dp[i][1];
    }
    cout << ans << endl;
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