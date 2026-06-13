#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    vector<int> nxt(n, 0);
    int last = n;
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] != v[i + 1]) {
            nxt[i] = i + 1;
        } else
            nxt[i] = nxt[i + 1];
    }
    // for (auto vl : nxt)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 0; i < n; i) {
        int x = i + 1, y = v[i] + k;
        while (x < n && v[x] <= y) {
            int z = v[x] + k;
            int elem = lower_bound(v.begin() + x + 1, v.end(), z) - v.begin() + x + 1;
            if (elem % 2 == 0) {
                // cout << i << " " << x << " " << endl;
                yes;
                return;
            }
            x = nxt[x];
        }
        i = nxt[i];
    }
    no;
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