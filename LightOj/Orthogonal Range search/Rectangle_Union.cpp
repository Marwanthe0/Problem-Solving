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
int n;
struct ev {
    int x, y1, y2, val;

    bool operator<(const ev &other) const {
        return x < other.x;
    }
};
class SegmentTree {
    int n;
    vector<int> ys, cover, len;
    void pull(int node, int l, int r) {
        if (cover[node] > 0) {
            len[node] = ys[r + 1] - ys[l];
        } else if (l == r) {
            len[node] = 0;
        } else {
            len[node] = len[2 * node + 1] + len[2 * node + 2];
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r)
            return;
        if (ql <= l && qr >= r) {
            cover[node] += val;
            pull(node, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        update(2 * node + 1, l, mid, ql, qr, val);
        update(2 * node + 2, mid + 1, r, ql, qr, val);
        pull(node, l, r);
    }

  public:
    SegmentTree(vector<int> &y) {
        ys = y;
        this->n = (int)y.size() - 1;
        cover.assign(4 * n, 0);
        len.assign(4 * n, 0);
    }
    void update(int ql, int qr, int val) {
        update(0, 0, n - 1, ql, qr, val);
    }
    int query() {
        return len[0];
    }
};
void marwan(int cs) {
    cin >> n;
    vector<ev> v;
    vector<int> y;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, y1, y2, 1});
        v.push_back({x2, y1, y2, -1});
        y.push_back(y1);
        y.push_back(y2);
    }
    make_unique(y);
    sort(all(v));
    SegmentTree sg1(y);
    int idx = 0, ans = 0;
    for (auto [x, y1, y2, val] : v) {
        if (idx) {
            int length = x - v[idx - 1].x;
            int height = sg1.query();
            ans += length * 1ll * height;
        }
        int l = lower_bound(all(y), y1) - y.begin();
        int r = lower_bound(all(y), y2) - y.begin();
        r--;
        if (l <= r) {
            sg1.update(l, r, val);
        }
        idx++;
    }
    cout << ans << endl;
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