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
vector<pair<int, int>> v;
int n;
vector<int> dp;
int table[16][16];
vector<map<pair<int, int>, vector<int>>> pre;
int f(int mask) {
    if (mask == ((1ll << n) - 1))
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int i = 0;
    for (; i < n; i++) {
        if ((mask & (1 << i)) == 0)
            break;
    }

    int ans = 1 + f(mask | (1 << i));

    for (int j = 0; j < n; j++) {
        if (j != i && ((mask & (1 << j)) == 0)) {
            ans = min(ans, 1 + f(mask | (table[i][j])));
        }
    }
    return dp[mask] = ans;
}
void marwan(int cs) {
    cin >> n;
    v.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    memset(table, -1, sizeof(table));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ydif = v[j].second - v[i].second, xdif = v[j].first - v[i].first;
            int g = __gcd(ydif, xdif);
            if (g)
                ydif /= g, xdif /= g;
            int tmask = (1 << i) | (1 << j);
            for (int k = 0; k < n; k++) {
                int ydif2 = v[k].second - v[i].second, xdif2 = v[k].first - v[i].first;
                int g2 = __gcd(ydif2, xdif2);
                
                if (g2)
                    ydif2 /= g2, xdif2 /= g2;

                if ((ydif2 == ydif && xdif2 == xdif))
                    tmask |= (1 << k);
            }
            table[i][j] = tmask;
        }
    }

    int ans = 0, msk = (1ll << n);
    dp.assign(msk, -1);
    ans = f(0);
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