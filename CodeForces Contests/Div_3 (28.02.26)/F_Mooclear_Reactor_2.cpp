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
    vector<vector<int>> v(n + 2);
    vector<int> tt(n + 2, 0ll);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[y + 1].push_back(x);
    }
    multiset<int> ms;
    int sum = 0ll, mx = 0ll;
    for (int i = n + 1; i; i--) {
        for (auto vl : v[i]) {
            ms.insert(vl);
            sum += vl;
        }
        while (ms.size() > i) {
            sum -= *ms.begin();
            ms.erase(*ms.begin());
        }
        mx = max(mx, sum);
        tt[i] = ms.size() < i ? sum : sum - *ms.begin();
    }
    for (int i = 1; i <= n + 1; i++) {
        tt[i] = max(tt[i], tt[i - 1]);
        cerr << i << " " << tt[i] << endl;
    }
    cerr << endl;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << max(mx, tt[y + 1] + x) << " ";
    }
    cout << endl;
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