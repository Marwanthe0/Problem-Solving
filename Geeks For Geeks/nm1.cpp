#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())

class SGTree {
  public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(int idx, int left, int right, vector<int> &v) {
        if (left == right) {
            seg[idx] = v[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, v);
        build(2 * idx + 2, mid + 1, right, v);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    void update(int idx, int left, int right, int ind, int val) {
        if (left == right) {
            seg[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (ind <= mid)
            update(2 * idx + 1, left, mid, ind, val);
        else
            update(2 * idx + 2, mid + 1, right, ind, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int left, int right, int l, int r) {
        if (r < left || l > right)
            return 0;
        else if (l <= left && right <= r) {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        int a = query(2 * idx + 1, left, mid, l, r);
        int b = query(2 * idx + 2, mid + 1, right, l, r);
        return a + b;
    }
};
vector<int> fact(N + 5, 0ll), ifact(N + 5, 0ll);
int mod(int x, int m = M) { return (x % m + m) % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1;
    }
    return mod(ans);
}
void pre() {
    fact[0] = 1ll;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(fact[i - 1] * 1ll * i);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--) {
        ifact[i - 1] = mod(ifact[i] * 1ll * i);
    }
}
int nCr(int n, int r) {
    if (n < r || r < 0)
        return 0ll;
    if (r == 0 || n == r)
        return 1ll;
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan()
{
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}