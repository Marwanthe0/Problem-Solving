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
int mod(int x, int m = M) { return x % m; }
int binexp(int a, int b, int m) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a, m);
        a = mod(a * 1ll * a, m);
        b >>= 1;
    }
    return mod(ans, m);
}
void marwan() {
    int n = 500;
    vector<int> v;
    int a = 13;
    for (int i = 1; i < n; i++) {
        v.push_back(mod(a * i, n));
    }
    sort(all(v));
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}