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
    int n, b, c;
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    if (n & 1) {
        b = (1 + (n * n)) / 2, c = ((n * n) - 1) / 2;
    } else {
        b = (((n * n) / 2) + 2) / 2, c = ((n * n) / 2 - 2) / 2;
    }
    cout << c << " " << b << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}