#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
class info {
  public:
    int l = 0, r = 0, f = 0;
    info() {};
    info(int left, int right, int full) {
        this->l = left, this->r = right, this->f = full;
    }
};
info merge(info left, info right) {
    info ans(0, 0, 0);
    ans.f = left.f + right.f + min(left.l, right.r);
    ans.l = left.l + right.l - min(left.l, right.r);
    ans.r = left.r + right.r - min(left.l, right.r);
    return ans;
}
void build(int idx, int left, int right, vector<info> &seg, string &s) {
    if (left == right) {
        if (s[left] == '(')
            seg[idx] = info(1, 0, 0);
        else
            seg[idx] = info(0, 1, 0);
        return;
    }
    int mid = (left + right) / 2;
    build(2 * idx + 1, left, mid, seg, s);
    build(2 * idx + 2, mid + 1, right, seg, s);
    seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}
info query(int idx, int left, int right, int l, int r, vector<info> &seg) {
    if (right < l || left > r)
        return info(0, 0, 0);
    if (left >= l && right <= r)
        return seg[idx];
    int mid = (left + right) / 2;
    info baam = query(2 * idx + 1, left, mid, l, r, seg);
    info daan = query(2 * idx + 2, mid + 1, right, l, r, seg);
    return merge(baam, daan);
}
void marwan() {
    string s;
    cin >> s;
    int n, m;
    cin >> m;
    n = s.size();
    vector<info> seg(4 * n);
    build(0, 0, n - 1, seg, s);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        info temp = query(0, 0, n - 1, l, r, seg);
        cout << (temp.f) * 2 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}