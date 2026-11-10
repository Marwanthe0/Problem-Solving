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
vector<int> tree;
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int update(int node, int l, int r, int k) {
    if (l == r) {
        tree[node] = 0;
        return l;
    }
    int mid = l + (r - l) / 2;
    int ans;
    if (tree[2 * node] >= k) {
        ans = update(2 * node, l, mid, k);
    } else {
        ans = update(2 * node + 1, mid + 1, r, k - (tree[2 * node]));
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return ans;
}
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n + 1), a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    tree.assign(4 * n + 4, 0);
    build(1, 1, n);
    for (int i = n; i >= 1; i--) {
        a[i] = update(1, 1, n, i - v[i]);
    }
    cout << a[1] << endl;
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