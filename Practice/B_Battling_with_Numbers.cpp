#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1ll)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1ll;
    }
    return ans;
}
void marwan() {
    int x;
    cin >> x;
    vector<pair<int, int>> a(x);
    unordered_map<int, int> m, n;
    for (int i = 0; i < x; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < x; i++)
        cin >> a[i].second;
    int y;
    cin >> y;
    vector<pair<int, int>> b(y);
    for (int i = 0; i < y; i++) {
        cin >> b[i].first;
    }
    for (int i = 0; i < y; i++)
        cin >> b[i].second;
    for (auto [x, y] : a)
        m[x] = y;
    for (auto [x, y] : b) {
        n[x] = y;
        if (m.count(x) == 0 || (m[x]) < y) {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1ll, cnt = 0ll;
    for (auto [x, y] : m) {
        if (n.count(x)) {
            if (n[x] != y)
                cnt++;
            n.erase(x);
        } else
            cnt++;
    }
    cnt += n.size();
    cout << binexp(2ll, cnt) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}