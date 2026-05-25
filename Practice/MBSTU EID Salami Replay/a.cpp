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
vector<int32_t> dv(N + 1, 0);
void marwan() {
    int n;
    cin >> n;
    n /= 2;
    int ans = INT_MAX;
    for (int i = 1; i <= (n / 2); i++) {
        int x = i, y = n - i;
        int xy = x * 1ll * y;
        ans = min(ans, (int)dv[xy]);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i)
            dv[j]++;
    }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}