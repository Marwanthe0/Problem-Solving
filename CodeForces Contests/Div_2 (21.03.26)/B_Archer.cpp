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
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    long double p = (a / b), q = (c / d);
    // cerr << p << " " << q << endl;
    cout << setprecision(10) << (p / (p + q - (p * q))) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}