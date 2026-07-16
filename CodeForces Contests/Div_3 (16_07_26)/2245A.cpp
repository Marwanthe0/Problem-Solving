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
    if (k > n / 2) {
        minus;
        return;
    }
    string t = s;
    int r = 0, l = 0, op = 0, op2 = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'R')
            r++;
        else {
            if (r < k)
                t[i] = 'R', r++, op++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            l++;
        } else {
            if (l < k)
                l++, op2++;
        }
    }
    cout << op + op2 << endl;
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