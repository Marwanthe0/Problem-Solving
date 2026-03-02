#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YA" << endl
#define no cout << "TIDAK" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(n), a;
    unordered_set<int> s;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (!s.count(x))
            a.push_back(x);
        s.insert(x);
    }
    int idx = 0;
    for (auto vl : a) {
        // cerr << vl << " ";
        // cerr << vl << " " << v[idx] << endl;
        if (vl != v[idx]) {
            no;
            return;
        }
        idx++;
    }
    // cerr << endl;
    yes;
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