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
    string s, t;
    cin >> s;
    t = s;
    for (int i = 0; i + 1 < 2 * n; i++) {
        if (t[i] == '1' && t[i + 1] == '0') {
            cerr << i << " " << i + 1 << endl;
            s[i] = '0';
            s[i + 1] = '1';
            i++;
        }
    }
    // cout << s << endl;
    if (t[0] == '0' && t.back() == '1') {
        s[0] = '1';
        s.back() = '0';
    }
    // cerr << s << endl;
    int x = 0, y = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] - '0') {
            if (i & 1)
                x++;
            else
                y++;
        }
    }
    cout << x << " " << y << endl;
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