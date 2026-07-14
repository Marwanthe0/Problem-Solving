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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#')
            count++;
        else {
            mx = max(mx, count);
            count = 0;
        }
    }
    mx = max(mx, count);
    cout << mx / 2 + (mx % 2 != 0) << endl;
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