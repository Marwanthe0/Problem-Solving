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
struct SGTree {
    vector<int> sgt;
    vector<int> a;
    int n;
    SGTree(int n) {
        this->n = n;
        a.assign(n, 0);
        sgt.assign(4 * n, 0);
    }
    int combine(int a, int b) {
        return a + b; // -> sum
        // return min(a, b);    // -> min
        // return max(a, b);    // -> max
    }
    void build(int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);
        sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] += value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(node * 2 + 1, l, mid, idx, value);
        } else {
            update(node * 2 + 2, mid + 1, r, idx, value);
        }
        sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return 0; // Edit here
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        int left = query(node * 2 + 1, l, mid, ql, qr);
        int right = query(node * 2 + 2, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build() { build(0, 0, n - 1); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};
struct event {
    int x, y1, y2, idx, val;
    bool operator<(const event &other) const {
        return x < other.x;
    }
};
void marwan(int cs) {
    cout << "Case " << cs << ":" << endl;
    int n, q, j = 0;
    cin >> n >> q;
    vector<pair<int, int>> points(n);
    vector<int> ys, ans(q, 0);
    for (auto &[x, y] : points) {
        cin >> x >> y;
        ys.push_back(y);
    }
    vector<event> events;
    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x2, y1, y2, i, 1});
        events.push_back({x1 - 1, y1, y2, i, -1});
    }
    sort(all(events));
    sort(all(points));
    make_unique(ys);
    int m = ys.size();
    SGTree sg1(m);
    for (auto [x, y1, y2, i, val] : events) {
        while (j < n && points[j].first <= x) {
            int idx = lower_bound(all(ys), points[j].second) - ys.begin();
            sg1.update(idx, 1);
            j++;
        }
        int l = lower_bound(all(ys), y1) - ys.begin();
        int r = upper_bound(all(ys), y2) - ys.begin() - 1;
        int count = sg1.query(l, r);
        ans[i] += val * count;
    }
    for (auto vl : ans)
        cout << vl << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000005
// #define INF 1e17
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define minus cout << "-1" << endl
// #define zero cout << "0" << endl
// #define make_unique(x) \
//     sort(all((x)));    \
//     (x).erase(unique(all((x))), (x).end())
// struct SGTree {
//     vector<int> sgt;
//     vector<int> a;
//     int n;
//     SGTree(int n) {
//         this->n = n;
//         a.assign(n + 1, 0);
//         sgt.assign((n + 1) * 4, 0);
//     }
//     int combine(int a, int b) {
//         return a + b; // -> sum
//         // return min(a, b);    // -> min
//         // return max(a, b);    // -> max
//     }
//     void build(int node, int l, int r) {
//         if (l == r) {
//             sgt[node] = a[l];
//             return;
//         }
//         int mid = l + (r - l) / 2;
//         build(node * 2 + 1, l, mid);
//         build(node * 2 + 2, mid + 1, r);
//         sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
//     }
//     void update(int node, int l, int r, int idx, int value) {
//         if (l == r) {
//             // as we are updating frequency not replacing
//             // that's why plusequals
//             sgt[node] += value;
//             return;
//         }
//         int mid = l + (r - l) / 2;
//         if (idx <= mid) {
//             update(node * 2 + 1, l, mid, idx, value);
//         } else {
//             update(node * 2 + 2, mid + 1, r, idx, value);
//         }
//         sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
//     }
//     int query(int node, int l, int r, int ql, int qr) {
//         if (l > qr or r < ql) {
//             return 0; // Edit here
//         }
//         if (l >= ql and r <= qr) {
//             return sgt[node];
//         }
//         int mid = l + (r - l) / 2;
//         int left = query(node * 2 + 1, l, mid, ql, qr);
//         int right = query(node * 2 + 2, mid + 1, r, ql, qr);
//         return combine(left, right);
//     }
//     void build() { build(0, 0, n); }
//     void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
//     int query(int l, int r) { return query(0, 0, n - 1, l, r); }
// };
// struct event {
//     int x, y1, y2, i, val;

//     bool operator<(const event &other) const {
//         return x < other.x;
//     }
// };
// void marwan(int cs) {
//     int n, q;
//     cin >> n >> q;
//     vector<pair<int, int>> points(n);
//     vector<int> ys, ans(q, 0);
//     for (auto &[x, y] : points) {
//         cin >> x >> y;
//         ys.push_back(y);
//     }
//     sort(all(points));
//     make_unique(ys);
//     int m = ys.size();
//     vector<event> events;
//     for (int i = 0; i < q; i++) {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         events.push_back({x2, y1, y2, i, 1});
//         events.push_back({x1 - 1, y1, y2, i, -1});
//     }
//     sort(all(events));

//     SGTree sg1(m);
//     // for (auto [x, y] : points)
//     // cerr << x << " " << y << endl;
//     // cerr << endl;
//     int j = 0;
//     for (auto [x, y1, y2, i, val] : events) {
//         // cerr << x << " " << y1 << " " << y2 << " " << i << " " << val << endl;
//         while (j < n && points[j].first <= x) {
//             auto [xx, yy] = points[j];
//             int idx = lower_bound(all(ys), yy) - ys.begin();
//             sg1.update(idx, 1);
//             j++;
//         }
//         // Must be upper bound - 1 for r
//         int l = lower_bound(all(ys), y1) - ys.begin(), r = upper_bound(all(ys), y2) - ys.begin() - 1;
//         int tans = sg1.query(l, r);
//         ans[i] += val * tans;
//     }
//     for (auto vl : ans)
//         cout << vl << endl;
// }
// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++) {
//         cout << "Case " << i << ":" << endl;
//         marwan(i);
//     }
//     return 0;
// }
