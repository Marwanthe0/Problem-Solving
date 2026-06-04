#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 2000005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int mod(int x, int m = M) { return x % m; }
int f(int x) {
    return mod((mod((1ll << (x - 2))) * 1ll * (x + 1)) - 1 + M);
}
void marwan() {
    int n;
    cin >> n;
    vector<unordered_set<int>> v(n);
    map<int, int> m;
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 1)
            ans = mod(ans + x);
        for (int j = 1; j * j <= x; j++) {
            int tans = 0ll;
            if (x % j == 0) {
                if (j != 1) {
                    m[j]++;
                    int tar = m[j];
                    cerr << j << " " << tar << "::";
                    if (tar > 1)
                        tans = mod(tans + j * 1ll * f(tar));
                }
                if ((x / j) != j) {
                    m[x / j]++;
                    int tar = m[x / j];
                    // cerr << x / j << " " << tar << ":::";
                    if (tar > 1)
                        tans = mod(tans + mod((x / j) * 1ll * mod(f(tar))));
                }
            }
            // cerr << tans << endl;
            ans = mod(ans + tans);
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}