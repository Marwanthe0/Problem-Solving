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
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '(')
                x++, y++;
            else
                x--, y--;
        } else {
            if (x > y)
                x--, y++;
            else
                x++, y--;
        }
        if (x < 0 || y < 0) {
            no;
            return;
        }
    }
    if (x || y)
        no;
    else
        yes;
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