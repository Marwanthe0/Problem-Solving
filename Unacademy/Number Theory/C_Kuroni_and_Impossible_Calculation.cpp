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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &vl : v) {
        cin >> vl;
    }
    sort(all(v));
    for (auto &vl : v)
        vl %= m;
    set<int> s(all(v));
    if (s.size() != n) {
        cout << 0 << endl;
        return;
    }
    int ans = 1ll;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans = (ans * 1ll * ((v[i] - v[j] + m))) % m;
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}