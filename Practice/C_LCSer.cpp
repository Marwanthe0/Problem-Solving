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
vector<vector<int>> dv(101);
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> t(101);
    for (int i = 1; i <= 100; i++)
        t[i] = {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (t[v[i]].first == -1)
            t[v[i]].first = i;
        t[v[i]].second = i;
    }
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        int low = n, high = 0;
        cerr << v[i] << endl;
        cerr << t[v[i]].first << " " << t[v[i]].second << endl;
        for (auto vl : dv[v[i]]) {
            if (vl == v[i])
                continue;
            cerr << vl << " ";
            low = min(low, t[vl].first);
            high = max(high, t[vl].second);
        }
        cerr << endl;
        ans = max(ans, high - low + 1);
    }
    cerr << endl;
    cout << max(2ll, ans) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                dv[i].push_back(j);
                if (i / j != j)
                    dv[i].push_back(i / j);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}