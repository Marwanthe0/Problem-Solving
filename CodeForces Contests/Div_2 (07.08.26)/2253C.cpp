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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int i = x - 1, j = y - 1, taken = 0, l = 0, r = 0, ans = 0;
    while ((i >= 0 || j >= 0) && taken < n + m - 1) {
        int valA = i >= 0 ? a[i] : 0;
        int valB = j >= 0 ? b[j] : 0;
        if (valA > valB) {
            if (l < n) {
                l++, ans += valA, taken++;
            }
            i--;
        } else if (valB > valA) {
            if (r < m) {
                r++, ans += valB, taken++;
            }
            j--;
        } else if (valA == valB) {
            ans += valA, taken++, i--, j--;
        }
    }
    cout << ans << endl;
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