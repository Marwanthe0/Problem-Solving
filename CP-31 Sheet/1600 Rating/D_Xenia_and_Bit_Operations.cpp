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
int flag;
void build(int idx, int low, int high, vector<int> &v, vector<int> &seg) {
    if (low == high) {
        seg[idx] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build((2 * idx) + 1, low, mid, v, seg);
    build((2 * idx) + 2, mid + 1, high, v, seg);
    if ((__lg(idx + 1) & 1) == flag)
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    else
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}
void update(int idx, int low, int high, int ind, int val, vector<int> &v, vector<int> &seg) {
    if (low == high) {
        seg[idx] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (ind <= mid) {
        update(2 * idx + 1, low, mid, ind, val, v, seg);
    } else
        update(2 * idx + 2, mid + 1, high, ind, val, v, seg);
    if ((__lg(idx + 1) & 1) == flag)
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    else
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}
void marwan() {
    int n, k;
    cin >> n >> k;
    flag = !(n & 1);
    n = (1 << n);
    vector<int> v(n), seg(4 * n);
    for (auto &vl : v)
        cin >> vl;
    build(0, 0, n - 1, v, seg);
    // for (int i = 0; i < seg.size(); i++)
    //     cerr << seg[i] << " ";
    // cerr << endl;
    for (int i = 0; i < k; i++) {
        int ind, val;
        cin >> ind >> val;
        update(0, 0, n - 1, ind - 1, val, v, seg);
        cout << seg[0] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}