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
    vector<int> a(n), b(n);
    vector<int> pr(n), ps(n);
    for (auto &vl : a) {
        cin >> vl;
    }
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++) {
        pr[i] = a[i] + ((i) ? pr[i - 1] : 0);
    }
    for (int j = n - 1; j >= 0; j--) {
        ps[j] = b[j] + ((j != n - 1) ? ps[j + 1] : 0);
    }
    int mn = INT_MAX, mx = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (ps[i] + pr[i] > mx) {
            mx = ps[i] + pr[i];
            idx = i;
        }
    }
    cerr << idx << endl;
    int ans = 0, ans2 = 0;
    for (int i = 0; i < idx; i++)
        ans += b[i];
    for (int i = idx + 1; i < n; i++)
        ans2 += a[i];
    cout << max(ans, ans2) << endl;
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