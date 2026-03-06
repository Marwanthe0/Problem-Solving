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
int f(int n) {
    return (n * 1ll * (n - 1)) / 2;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    int mn, mx = f(n - (m - 1));
    if (n % m == 0)
        mn = m * (f(n / m));
    else {
        int rem = n % m;
        mn = f(n / m) * (m - rem) + f(n / m + 1) * rem;
    }
    cout << mn << " " << mx << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}