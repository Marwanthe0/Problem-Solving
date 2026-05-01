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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (auto &vl : v) {
        cin >> vl;
        s.insert(vl);
    }
    if (s.size() == 2) {
        cout << 1e17 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        int x = v[i] - v[i - 1];
        s.clear();
        for (auto vl : v) {
            s.insert(vl % x);
        }
        if (s.size() == 2) {
            cout << x << endl;
            return;
        }
    }
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