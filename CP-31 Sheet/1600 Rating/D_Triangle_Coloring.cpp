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
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1ll;
    }
    return ans;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int x = (n / 3);
    vector<int> t(x);
    for (int i = 0; i < x; i++) {
        vector<int> temp(3);
        temp[0] = v[3 * i], temp[1] = v[3 * i + 1], temp[2] = v[3 * i + 2];
        sort(all(temp));
        if (temp.front() == temp.back())
            t[i] = 3;
        else if (temp[0] == temp[1])
            t[i] = 2;
        else
            t[i] = 1;
    }
    sort(all(t), greater<int>());
    int ans = 1ll;
    for (int i = 0; i < x / 2; i++)
        ans = mod(ans * 1ll * t[i]);
    int y = 1;
    for (int i = x; i > (x / 2); i--, y++) {
        ans = mod(ans * 1ll * i);
        ans = mod(ans * 1ll * binexp(y, M - 2));
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}