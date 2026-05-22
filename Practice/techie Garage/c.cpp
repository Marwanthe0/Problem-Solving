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
    int n, h, a, s;
    cin >> n >> h >> a >> s;
    int ans = (6 - n) * 10 + h * 2 + (a / 5) + (s / 10);
    if (ans >= 30)
        cout << "hungry" << endl;
    else
        cout << "not hungry" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}