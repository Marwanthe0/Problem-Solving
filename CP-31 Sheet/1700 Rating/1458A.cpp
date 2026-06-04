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
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    sort(all(a));
    int g = 0ll;
    for (int i = 1; i < n; i++)
        g = __gcd(g, a[i] - a[i - 1]);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cout << __gcd(b[i] + a[0], g) << " ";
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}