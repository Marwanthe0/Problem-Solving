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
string a, b, s;
int n;
void marwan(int cs) {
    string s;
    cin >> s;
    a.clear();
    b.clear();
    n = s.size();
    for (int i = 0; i < n; i++) {
        a.push_back('0' + (i & 1));
        b.push_back('0' + ((i + 1) & 1));
    }
    // cout << s << endl;
    // cout << a << endl;
    // cout << b << endl;
    int ans = 0, count = 0, ans2 = 0, count2 = 0, count3 = 0, ans3 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == a[i] || s[i] == '?')
            count++;
        else {
            ans += (count * (count + 1)) / 2, count = 0;
        }

        if (s[i] == b[i] || s[i] == '?')
            count2++;
        else
            ans2 += (count2 * (count2 + 1)) / 2, count2 = 0;

        if (s[i] == '?')
            count3++;
        else
            ans3 += (count3 * (count3 + 1)) / 2, count3 = 0;
    }
    ans += count * (count + 1) / 2;
    ans2 += count2 * (count2 + 1) / 2;
    ans3 += count3 * (count3 + 1) / 2;
    // cerr << ans << " " << count << endl;
    // cerr << ans2 << " " << count2 << endl;
    // cerr << ans3 << " " << count3 << endl;
    // cerr << endl;
    cout << ans + ans2 - ans3 << endl;
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