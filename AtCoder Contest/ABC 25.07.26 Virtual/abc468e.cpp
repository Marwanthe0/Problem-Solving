#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
        b >>= 1ll;
    }
    return ans % M;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0ll;
    for (auto &vl : v) {
        cin >> vl;
        sum = mod(sum + vl);
    }
    vector<int> t;
    int i = 0, j = n - 1;
    int tsum = 0ll, count = 1ll;
    while (i <= j) {
        t.push_back(mod(mod(sum * 1ll * count) + tsum));
        sum = mod(sum - v[i] + M);
        sum = mod(sum - v[j] + M);
        tsum = mod(tsum + mod(count * 1ll * mod(v[i] + v[j])));
        count++;
        i++, j--;
    }
    vector<int> tt(t.rbegin(), t.rend());
    t.insert(t.end(), tt.begin() + (n & 1), tt.end());
    // for (auto vl : t)
    //     cout << vl << " ";
    // cout << endl;
    int ans = 0ll;
    for (int i = 1; i <= (int)t.size(); i++) {
        // cerr << t[i - 1] << " " << i << endl;
        ans = mod(ans + mod(mod(t[i - 1]) * 1ll * (binexp(i, M - 2) % M)));
        ans %= M;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}