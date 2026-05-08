#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 2001
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int8_t dp[N][N][3][3][2];
int f(int i, int j, int r1, int r2, bool a, vector<int> &v) {
    if (i > j) {
        return !a;
    }
    int tr1 = r1, tr2 = r2;
    if (tr1 == -1)
        tr1 = 2;
    if (tr2 == -1)
        tr2 = 2;
    if (dp[i][j][tr1][tr2][a] != -1)
        return dp[i][j][tr1][tr2][a];

    if (a) {
        bool flag = false;
        if (r1 == -1) {
            flag |= f(i + 1, j, v[i] & 1, r2, !a, v);
            flag |= f(i, j - 1, v[j] & 1, r2, !a, v);
        }
        if (r1 == 0) {
            if (v[i] & 1) {
                flag |= f(i + 1, j, 1, r2, !a, v);
            }
            if (v[j] & 1) {
                flag |= f(i, j - 1, 1, r2, !a, v);
            }
        } else {
            if (v[i] % 2 == 0) {
                flag |= f(i + 1, j, 0, r2, !a, v);
            }
            if (v[j] % 2 == 0) {
                flag |= f(i, j - 1, 0, r2, !a, v);
            }
        }
        return dp[i][j][tr1][tr2][a] = flag;
    } else {
        bool flag = true;
        if (r2 == -1) {
            flag &= f(i + 1, j, r1, v[i] & 1, !a, v);
            flag &= f(i, j - 1, r1, v[j] & 1, !a, v);
        }
        if (r2 == 0) {
            if (v[i] & 1) {
                flag &= f(i + 1, j, r1, 1, !a, v);
            }
            if (v[j] & 1) {
                flag &= f(i, j - 1, r1, 1, !a, v);
            }
        } else {
            if (v[i] % 2 == 0) {
                flag &= f(i + 1, j, r1, 0, !a, v);
            }
            if (v[j] % 2 == 0) {
                flag &= f(i, j - 1, r1, 0, !a, v);
            }
        }
        return dp[i][j][tr1][tr2][a] = flag;
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    for (int t = 0; t < 2; t++)
                        dp[i][j][k][l][t] = (int8_t)-1;
                }
            }
        }
    }
    bool ans = f(0, n - 1, -1, -1, 1, v);
    if (ans)
        cout << "Roy" << endl;
    else
        cout << "Hridoy" << endl;
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