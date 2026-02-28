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
    vector<int> a(n), b, pos(n + 1), v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (auto &vl : v)
        cin >> vl;
    b.push_back(v[0]);
    for (int i = 1; i < n; i++)
        if (v[i] != v[i - 1])
            b.push_back(v[i]);
    for (int i = 1; i < b.size(); i++) {
        if (pos[b[i]] < pos[b[i - 1]]) {
            no;
            return;
        }
    }
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