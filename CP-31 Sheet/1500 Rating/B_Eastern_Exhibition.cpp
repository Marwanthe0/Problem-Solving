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
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    int ans = 1;
    // sort(all(a));
    // sort(all(b));
    // make_unique(a);
    // make_unique(b);
    sort(all(a));
    sort(all(b));
    int x = a.size(), y = b.size();
    if (a.size() % 2 == 0)
        ans = (a[(x / 2)] - a[x / 2 - 1] + 1);
    if (b.size() % 2 == 0)
        ans *= (b[(y / 2)] - b[y / 2 - 1] + 1);
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