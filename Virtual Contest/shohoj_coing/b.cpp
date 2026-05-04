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
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = 2 * c + (min(a, b));
    if (abs(a - b) <= 1)
        ans += max(a, b);
    else
        ans += min(a, b) + 1;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}