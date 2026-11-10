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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (auto &[x, y] : a)
        cin >> x >> y;
    for (auto &[x, y] : b)
        cin >> x >> y;
    sort(all(a));
    sort(all(b));
    int j = 0, k = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && a[j].first < b[i].first) {
            j++;
        }
        while (k < j && a[k].second < b[i].second)
            k++;
        ans += (j - k);
    }
    j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && b[j].first < a[i].first) {
            j++;
        }
        while (k < j && b[k].second < a[i].second)
            k++;
        ans += (j - k);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}