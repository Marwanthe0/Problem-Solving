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
vector<int> v = {2, 3, 5, 7, 30, 42, 70, 105};
vector<int> t = {6, 10, 14, 15, 21, 35, 210};
void marwan() {
    int l, r;
    cin >> l >> r;
    int ans = r - l + 1;
    for (int i = 0; i < v.size(); i++) {
        int x = (l - 1) / v[i], y = r / v[i];
        ans -= y - x;
    }
    for (int i = 0; i < t.size(); i++) {
        int x = (l - 1) / t[i], y = r / t[i];
        ans += y - x;
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