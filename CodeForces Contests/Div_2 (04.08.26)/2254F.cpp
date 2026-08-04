#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> s;
    map<int, int> m;
    int mx = INT_MIN;
    for (auto &vl : a) {
        cin >> vl;
        mx = max(mx, vl);
        s.insert(vl);
    }
    for (auto &vl : b) {
        cin >> vl;
        mx = max(mx, vl);
        m[vl]++;
    }
    vector<int> vis(mx + 1, 0);
    sort(all(a));
    sort(all(b));
    if (a == b) {
        yes;
        return;
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