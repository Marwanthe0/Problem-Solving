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
void marwan(int tc) {
    int n;
    cin >> n;
    cout << "Case " << tc << ": ";
    long double x = 0.5 * sqrt(2) * (sqrt((((n - 2) / 2) * ((n - 2) / 2)) + ((n / 2) * (n / 2))));
    x -= 0.5;
    x *= 4;
    cout << (int)x << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}