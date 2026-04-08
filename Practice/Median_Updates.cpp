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
int f(string &s, int n, int cnt) {
    string k;
    for (int i = 0; i < n; i++) {
        char x = i ? s[i - 1] : s[n - 1], y = s[i], z = (i == n - 1) ? s[0] : s[i + 1];
        if (x == y && y == z || (x == y) || x == z) {
            k.push_back(x);
        } else if (y == z)
            k.push_back(y);
    }
    if (s == k)
        return 1;
    else if (cnt > n)
        return -1;
    else {
        int x = f(k, n, cnt + 1);
        if (x == -1)
            return -1;
        else
            return x + 1;
    }
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = ; i < n; i++) {
        if()
    }
    cout << f(s, n, 0) << endl;
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