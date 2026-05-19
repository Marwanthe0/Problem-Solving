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
    string s;
    cin >> s;
    int n = s.size();
    int four = 0, three = 0, two = 0, one = 0;
    bool flag = false;
    for (auto &c : s) {
        if (c == '4')
            four++;
        if (c == '3' || c == '1')
            c = '1', one++;
        if (c == '2')
            two++;
    }
    cerr << s << endl;
    // cerr << one << " " << two << endl;
    int ans = min(one, two);
    one = 0;
    for (auto c : s) {
        if (c == '1')
            one++;
        else if (c == '2')
            two--;
        ans = min(ans, one + two);
        // cerr << one << " " << two << " " << ans << endl;
    }
    // cerr << endl;
    cout << four + ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan(t);
    }
    return 0;
}