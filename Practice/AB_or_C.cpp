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
    vector<array<int, 2>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            v.push_back({x, i});
        }
    }
    sort(all(v));
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i][0] << " ";
    // cout << endl;
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i][1] << " ";
    // cout << endl;
    // cout << endl;
    map<int, int> m;
    int l = 0, r = 0, ans = INT_MAX;
    while (r < 3 * n) {
        m[v[r][1]]++;
        while (m.size() >= n) {
            m[v[l][1]]--;
            ans = min(ans, v[r][0] - v[l][0]);
            if (m[v[l][1]] <= 0)
                m.erase(v[l][1]);
            l++;
        }
        r++;
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