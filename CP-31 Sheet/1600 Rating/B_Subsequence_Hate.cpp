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
void marwan() {
    string s;
    cin >> s;
    int n = s.size();
    bool x = false, y = false;
    int count = 0, count2 = 0, one = 0, zero = 0;
    int mx0 = 0, mx1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
            mx1 = max(mx1, count);
            x = true;
        } else {
            one++;
            mx0 = max(mx0, count2);
            y = true;
        }
        if (x && s[i] == '1')
            count++;
        if (y && s[i] == '0')
            count2++;
    }
    int mx = n;
    int lzero = 0, lone = 0;
    for (int i = 0; i < n; i++) {
        // left e 1 right e zero
        if (s[i] == '1')
            one--, lone++;
        else
            zero--, lzero++;
        mx = min(mx, lzero + one);

        // left e 0 right e 1
        mx = min(mx, lone + zero);
    }
    cout << min({count, count2, mx}) << endl;
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