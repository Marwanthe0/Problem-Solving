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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int>> a, b;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        x--, y--;
        if (x == y)
            v[x] = (op == 1 ? 1 : -1);
        else {
            g[x].push_back({y, (op == 1 ? 1 : -1)});
            g[y].push_back({x, (op == 1 ? 1 : -1)});
        }
        // if (op == 1) {
        //     if (x == y)
        //         v[x] = 1;
        //     else
        //         a.push_back({x, y});
        // } else {
        //     if (x == y)
        //         v[x] = -1;
        //     else
        //         b.push_back({x, y});
        // }
    }
    for (int i = 0; i < n; i++) {
        // cerr << v[i] << endl;
        int flag = 0;
        for (auto [x, y] : g[i]) {
            // cerr << x << " " << y << endl;
            if (v[i] > 0 && v[x] > 0 && y < 0) {
                no;
                return;
            } else if (v[i] < 0 && v[x] < 0 && y > 0) {
                no;
                return;
            }
            if (v[i] < 0 && v[x] > 0) {
                if (flag == 0)
                    flag = y;
                else if (flag != y) {
                    no;
                    return;
                }
                if (flag < 0)
                    v[i] = -2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            for (auto [x, y] : g[i]) {
                if (y > 0 && v[x] + v[i] < 0) {
                    no;
                    return;
                } else if (y < 0 && v[x] + v[i] >= 0) {
                    no;
                    return;
                }
            }
        }
    }
    // cerr << endl;
    // cout << endl;
    yes;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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