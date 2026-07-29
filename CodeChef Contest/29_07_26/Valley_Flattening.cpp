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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i + 1 < n; i++) {
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            t.push_back({v[i], i});
        }
    }
    sort(all(t));
    reverse(all(t));
    for (auto [x, y] : t) {
        if (v[y + 1] > v[y] && v[y - 1] > v[y]) {
            v[y + 1] = v[y - 1] = v[y];
        }
    }
    cout << accumulate(all(v), 0ll) << endl;
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