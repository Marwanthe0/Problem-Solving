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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1ll, l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int count = 1;
        while (i < n && (s[i] - '0') + (s[i - 1] - '0') == 9) {
            i++, count++;
        }
        if (count > 2 && count & 1)
            ans = (ans * 1ll * ((count / 2ll) + 1ll));
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}