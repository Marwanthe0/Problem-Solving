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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i)
            v[i] += v[i - 1];
        // cout << v[i] << " ";
    }
    int sum = v.back(), ans = 0ll;
    if (sum % 3ll) {
        cout << 0 << endl;
        return;
    }
    map<int, int> m;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] == sum / 3ll)
            ans += m[(sum / 3ll) * 1ll * 2];
        m[v[i]]++;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}