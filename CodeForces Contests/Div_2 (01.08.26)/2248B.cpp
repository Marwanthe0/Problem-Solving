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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0, i1 = n - 1, j1 = m - 1;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            j++, i++;
        } else {
            no;
            return;
        }
    }
    while (j1 >= 0 && i1 >= 0) {
        if (a[i1] >= b[j1]) {
            j1--, i1--;
        } else {
            no;
            return;
        }
    }
    i--, i1++;
    // cerr << j << " " << j1 << " " << i << " " << i1 << endl;
    if (j < m || j1 >= 0 || (i >= i1)) {
        no;
    } else
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