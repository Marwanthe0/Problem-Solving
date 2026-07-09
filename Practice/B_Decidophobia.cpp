#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> v(n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        v[i] = {x, i};
    }
    vector<int> t(all(a));
    for (auto vl : a)
        t.push_back(vl);
    // vector<int> tt(all(t));
    // reverse(all(tt));
    sort(all(v));
    reverse(all(v));
    // for (auto [x, y] : v)
    //     cout << x << " " << y << endl;
    // cout << endl;
    int l = 0, r = n, last = 0;
    auto ok = [&](int mid) {
        vector<int> mark(n, 0);
        int tans = 0ll;
        for (int i = 0; i < mid; i++) {
            mark[v[i].second] = 1;
        }
        int count = 0, tcount = 0;
        for (int i = 0; i < n + d; i++) {
            if (i - d >= 0) {
                if (mark[i % n]) {
                    tans += count * t[i];
                } else {
                    tans -= (d - count) * t[i];
                }
                count -= mark[(i - d + n) % n] == 0;
            }
            count += mark[i % n] == 0;
            cerr << i << " " << tans << endl;
        }
        count = 0;
        for (int i = n + d - 1; i >= 0; i--) {
            if (i < n) {
                if (mark[i % n]) {
                    tans += count * t[i];
                } else
                    tans -= (d - count) * t[i];
                count -= mark[(i + d) % n] == 0;
            }
            cerr << i << " " << tans << endl;
            count += mark[i % n] == 0;
        }
        cerr << endl;
        return tans;
    };
    // while (l <= r) {
    //     int mid = l + (r - l) / 2;
    //     int x = ok(mid);
    //     cerr << mid << "::" << x << endl;
    //     if (x > last) {
    //         l = mid + 1, last = x;
    //     } else
    //         r = mid - 1;
    // }
    for (int i = 0; i <= n; i++) {
        cout << i << ":::" << ok(i) << endl;
    }
    cerr << endl;
    cout << last << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}