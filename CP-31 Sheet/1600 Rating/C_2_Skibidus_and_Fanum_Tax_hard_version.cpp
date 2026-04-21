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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(b));
    if (b.front() < 2 * a.front())
        a.front() = b.front() - a.front();
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(all(b), a[i - 1] + a[i]);
        if (it != b.end()) {
            if (a[i] >= a[i - 1])
                a[i] = min(*it - a[i], a[i]);
            else
                a[i] = *it - a[i];
        }
    }
    if (is_sorted(all(a)))
        yes;
    else
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