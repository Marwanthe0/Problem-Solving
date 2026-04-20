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
    vector<int> v(m);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    vector<vector<int>> ans(m, vector<int>(6, 0));
    int l = 0, r = m - 1, count = 0;
    while (l <= r && count < n) {
        if (count % 2 == 0) {
            for (int i = 0; i < 6; i++) {
                if (i & 1)
                    cout << v[l] << " ";
                else
                    cout << v[r] << " ";
            }
        } else {
            for (int i = 0; i < 6; i++) {
                if (i & 1)
                    cout << v[r] << " ";
                else
                    cout << v[l] << " ";
            }
            l++, r--;
        }
        cout << endl;
        count++;
    }
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