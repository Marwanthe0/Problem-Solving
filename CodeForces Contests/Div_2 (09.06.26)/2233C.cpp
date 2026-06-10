#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    string s, ans,ttans;
    cin >> s;
    int last = INT_MAX;
    for (int i = 0; i < n; i++)
        ttans.push_back('0');
    for (int j = 0; j <= k; j++) {
        int xx = j, yy = k - j;
        // cerr << k << " " << xx << " " << yy << endl;
        string a, tans = ttans;
        int open = 0, close = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (xx) {
                    tans[i] = '1';
                    xx--;
                    continue;
                }
                open++;
            } else if (open)
                open--;
        }
        // cerr << xx << " " << yy << endl;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                if (yy) {
                    tans[i] = '1', yy--;
                    continue;
                }
                close++;
            } else if (close)
                close--;
        }
        open = 0, close = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (tans[i] == '1') {
                count++;
                continue;
            }
            if (s[i] == '(')
                open++;
            else if (open)
                open--, mx++;
        }
        // cerr << count << endl;
        if (mx < last)
            last = mx, ans = tans;
    }
    cout << ans << endl;
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