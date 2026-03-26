#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void build(int ind, int left, int right, vector<pair> &seg, vector<int> &v) {
    if (left == right)
        seg[ind] = v[left];
    int mid = (left + right) / 2;
    build(2 * seg + 1, left, mid, seg, v);
    build(2 * seg + 2, mid + 1, right, seg, v);
    seg[ind] = 
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<int> seg(4 * n);
    build(0, 0, n - 1, seg, b);
    while (k--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, y, r;
            l--, y--, r--;
            cin >> l >> y >> r;
            r += l;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}