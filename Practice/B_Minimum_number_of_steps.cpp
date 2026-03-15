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
int mod(int x, int m = M) { return x % m; }
void marwan() {
    string s;
    cin >> s;
    int n = s.size();
    int b = 0ll, ans = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b')
            b++;
        else {
            ans = mod(ans + b);
            b = mod(b * 2ll);
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}