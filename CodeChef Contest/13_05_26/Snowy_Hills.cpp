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
int x, y;
int lsb(int n) {
    return n & -n;
}
int f(int a, int b) {
    if (b <= a)
        return (a - b) * x;
    else if (a + lsb(a) <= b)
        return f(a + lsb(a), b);
    else {
        return min(y + f(a + 1, b), f(a + lsb(a), b));
    }
}
void marwan() {
    int n;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0ll;
    for (int i = 0; i + 1 < n; i++) {
        int val = f(v[i], v[i + 1]);
        ans += val;
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
    // for (int i = 1; i <= 100; i++)
    //     cout << i << " " << i + lsb(i) << endl;
    return 0;
}