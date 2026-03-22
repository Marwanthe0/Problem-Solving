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
    string s, t;
    cin >> s >> t;
    long double target = 0, current = 0, k = 0;
    for (auto c : s) {
        if (c == '+')
            target++;
        else
            target--;
    }
    for (auto c : t) {
        if (c == '+')
            current++;
        else if (c == '-')
            current--;
        else
            k++;
    }
    if (((int)target - (int)current + (int)k) % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    int x = (target - current + k) / 2;
    if (x < 0 || x > k) {
        cout << 0 << endl;
        return;
    }
    long double fact = 1, temp = k, ckx = 1;
    for (int i = 1; i <= x; i++, temp--) {
        fact = fact * i;
        ckx = ckx * temp;
    }
    // cerr << x << " " << k << endl;
    ckx = (ckx) / fact;
    cout << setprecision(10) << (long double)ckx / (1ll << (int)k) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}