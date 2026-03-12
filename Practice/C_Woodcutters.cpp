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
void marwan() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    int l = INT_MIN, r, ans = 1, last = v[0].first;
    for (int i = 1; i < n - 1; i++) {
        if (v[i].first - v[i].second > last) {
            ans++, last = v[i].first;
        } else if (v[i].first + v[i].second < v[i + 1].first)
            ans++, last = v[i].first + v[i].second;
        else
            last = v[i].first;
    }
    if (n > 1)
        ans++;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}