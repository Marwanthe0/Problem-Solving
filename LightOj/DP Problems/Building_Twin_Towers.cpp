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
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int sum = accumulate(all(v), 0ll);

    vector<int> dp(sum + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int h = v[i];
        vector<int> nxtdp = dp;
        for (int diff = 0; diff <= sum / 2; diff++) {
            if (dp[diff] != INT_MIN) {
                int boro = dp[diff], choto = boro - diff;
                int newboro = boro, newchoto = choto;

                // boro ta er upore rakhbo
                {
                    newboro = boro + h, newchoto = choto;
                    int newdiff = newboro - newchoto;
                    nxtdp[newdiff] = max(nxtdp[newdiff], newboro);
                }

                // choto ta er upore rakhbo
                {
                    // rakhleo boro hobena
                    if (choto + h <= boro) {
                        newboro = boro, newchoto = choto + h;
                    }
                    // rakhle oitai boro hoye jabe
                    else {
                        newboro = choto + h, newchoto = boro;
                    }
                    int newdiff = newboro - newchoto;
                    nxtdp[newdiff] = max(nxtdp[newdiff], newboro);
                }
            }
        }
        dp = nxtdp;
    }
    if (dp[0])
        cout << dp[0] << endl;
    else
        cout << "impossible" << endl;
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