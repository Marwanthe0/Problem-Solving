#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    string s;
    cin >> s;
    int l = 0, r = 0, flag = -1, ans = 0, n = s.size();
    while (r < n) {
        if (s[r] == '?') {
            if (flag != -1) {
                flag = !flag;
            }
        } else {
            if (flag == -1)
                flag = 1 - (s[r] - '0');
            else if (flag == s[r] - '0')
                flag = !flag;
            else {
                int x = r - l;
                ans += x * (x - 1) / 2;
                flag = 1 - (s[r] - '0');
                l = r;
                while (l - 1 >= 0 && s[l - 1] == '?')
                    l--;
            }
        }
        // cerr << l << " " << r << " " << flag << endl;
        r++;
    }
    // cerr << endl;
    int x = r - l;
    ans += x * (x - 1) / 2;
    cout << ans + n << endl;
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