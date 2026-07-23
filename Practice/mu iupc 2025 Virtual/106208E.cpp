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
    string s;
    cin >> s;
    if (k == 0) {
        cout << s << endl;
        return;
    }
    string t(all(s));
    for (int i = 1; i + 1 < n; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1')
            t[i] = (1 - (t[i] - '0')) + '0';
    }
    if (k == 1) {
        cout << t << endl;
        return;
    }
    s = t;
    if (k >= 2) {
        for (int i = 1; i + 1 < n; i++) {
            if (s[i - 1] == '1' && s[i + 1] == '1')
                t[i] = 1 - (t[i] - '0') + '0';
        }
    }
    s = t;
    if (k == 2) {
        cout << s << endl;
        return;
    }
    for (int i = 1; i + 1 < n; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1')
            t[i] = 1 - (t[i] - '0') + '0';
    }
    s = t;
    if (k & 1) {
        cout << s << endl;
        return;
    }
    for (int i = 1; i + 1 < n; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1')
            t[i] = 1 - (t[i] - '0') + '0';
    }
    cout << t << endl;
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