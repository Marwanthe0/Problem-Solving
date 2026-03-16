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
    vector<int> a(n);
    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ms.insert({a[i], i});
    }
    int last = n - 1, ans = 0;
    while (!ms.empty()) {
        pair<int, int> x = *(--ms.end());
        while (last >= x.second) {
            ms.erase(ms.find({a[last], last}));
            last--;
        }
        ans++;
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