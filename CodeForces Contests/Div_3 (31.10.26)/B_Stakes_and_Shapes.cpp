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
    int r, p, s;
    cin >> r >> s >> p;
    int mx = max({r, p, s});

    char ans;
    if (r == mx) {
        ans = 'P';
    } else if (p == mx)
        ans = 'S';
    else
        ans = 'R';
        
    for (int i = 0; i < r + p + s; i++)
        cout << ans;
    cout << endl;
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