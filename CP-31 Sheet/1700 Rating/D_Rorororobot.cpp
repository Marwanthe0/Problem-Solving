#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
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
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
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
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int query(int idx, int left, int right, int l, int r) {
        if (r < left || l > right)
            return 0;
        else if (left >= l && r >= right) {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        int a = query(2 * idx + 1, left, mid, l, r);
        int b = query(2 * idx + 2, mid + 1, right, l, r);
        return max(a, b);
    }
};
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &vl : v)
        cin >> vl;
    SGTree sg1(m);
    sg1.build(0, 0, m - 1, v);
    int q;
    cin >> q;
    auto f = [&](int end, int start, int x1, int x2, int k) {
        if (abs(x1 - x2) % k)
            return false;
        int mn = min(x1, x2);
        int high = max(0ll, end - mn), low = max(0ll, start - mn);
        if (high % k == 0 || low % k == 0 || (high / k) != (low / k))
            return true;
        return false;
    };
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if ((x1 == x2 && y1 == y2)) {
            yes;
            continue;
        }
        if (abs(y2 - y1) % k) {
            no;
            continue;
        }
        int mn = sg1.query(0, 0, m - 1, min(y1, y2) - 1, max(y1, y2) - 1) + 1;
        if (mn > n) {
            no;
            continue;
        }
        if (!f(n, mn, x1, x2, k)) {
            no;
            continue;
        }
        yes;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}