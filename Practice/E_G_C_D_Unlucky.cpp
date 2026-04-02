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
int lcm(int a, int b) { return a * (b / __gcd(a, b)); }
void marwan() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++) {
        c[i] = lcm(a[i], b[i]);
    }
    int g = 0, t = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        g = __gcd(g, c[i]);
        t = __gcd(t, c[j]);
        if (g != a[i]) {
            no;
            return;
        }
        if (t != b[j]) {
            no;
            return;
        }
    }
    yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}