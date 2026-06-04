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
    int mx = n - (m - 1);
    mx = (mx * (mx - 1)) / 2;
    int mna = n / m, mnb = (n / m) + (n % m != 0);
    int ext = n % m;
    int mn = ext * ((mnb * (mnb - 1) / 2));
    mn += (m - ext) * (mna * (mna - 1) / 2);
    cout << mn << " " << mx << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}