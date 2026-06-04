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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int ans = 0;
    sort(all(b));
    for (int i = 0; i < n; i++) {
        int it = upper_bound(all(b), a[i]) - b.begin();
        if (it == m)
            ans = max(ans, abs(a[i] - b[m - 1]));
        else if (it == 0)
            ans = max(ans, abs(a[i] - b[0]));
        else
            ans = max(ans, min(abs(a[i] - b[it]), abs(a[i] - b[it - 1])));
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}