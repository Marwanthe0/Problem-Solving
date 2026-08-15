#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1;
    }
    return ans;
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "^#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    t += "$";
    int m = (int)t.length();
    vector<int> P(m, 0ll);
    int C = 0ll, R = 0ll;
    int ans = 0ll;
    int dv2 = binexp(2, M - 2) % M;
    // cerr << mod(10 * dv2) << endl;
    // return;
    for (int i = 1; i < m - 1; i++) {
        int i_mirror = 2 * 1ll * C - i;
        if (R > i) {
            P[i] = min(R - i, P[i_mirror]);
        } else {
            P[i] = 0ll;
        }
        while (t[i - 1 - P[i]] == t[i + 1 + P[i]]) {
            P[i]++;
            P[i] %= M;
        }
        if (i + P[i] > R) {
            C = i;
            R = mod(i + P[i]);
        }
        ans = mod(ans + mod((P[i] + 1) / 2));
    }
    ans = mod(ans - n + M);
    int x = count(all(s), '0'), y = count(all(s), '1');
    cout << mod(mod(mod(mod((n * 1ll * (n - 1)) / 2) - ans + M) - mod(x * 1ll * y) + M) + 1) << endl;
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