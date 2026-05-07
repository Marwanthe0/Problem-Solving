#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
#define int long long
#define M 998244353
#define N 2005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int mod(int x, int m = M) {
    return x % m;
}
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1ll;
    }
    return mod(ans);
}
vector<int> fact(N + 1), ifact(N + 1);
void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(i * 1ll * fact[i - 1]);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifact[i] = mod((i + 1) * 1ll * ifact[i + 1]);
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> m;
    for (auto &vl : a)
        cin >> vl;
    for (int &vl : b) {
        cin >> vl;
        m[vl]++;
    }
    // make_unique(b);
    // for (auto [x, y] : m)
    //     if (y > 1)
    //         b.push_back(x);
    vector<long double> tb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                tb.push_back((long double)b[i] / (long double)b[j]);
        }
    }
    sort(all(tb));
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long double x = (long double)a[i] / (long double)a[j];
            int l = 0, r = tb.size() - 1, tans = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (tb[mid] < x) {
                    tans = mid, l = mid + 1;
                } else
                    r = mid - 1;
            }
            ans += (tans + 1);
        }
    }
    int perm = mod(n * 1ll * (n - 1));
    ans = mod(ans * 1ll * binexp(perm, M - 2));
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}