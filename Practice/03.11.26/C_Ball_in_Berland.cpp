#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    int a, b, n;
    cin >> a >> b >> n;
    vector<pair<int, int>> v(n);
    map<int, int> ma, mb;
    map<pair<int, int>, int> mp;
    for (auto &[x, y] : v) {
        cin >> x;
        ma[x]++;
    }
    for (auto &[x, y] : v) {
        cin >> y;
        mb[y]++;
    }
    sort(all(v));
    for (auto &[x, y] : v) {
        mp[{x, y}]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x, y] = v[i];
        int tans = n - 1;
        tans -= (ma[x] - 1);
        tans -= (mb[y] - 1);
        tans += mp[{x, y}] - 1;
        ans += tans;
    }
    cout << ans / 2 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}