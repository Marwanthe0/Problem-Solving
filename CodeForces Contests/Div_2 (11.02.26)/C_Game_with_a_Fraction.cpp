#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int p, q;
    cin >> p >> q;
    int d = q - p;
    if (d <= 0) {
        yes;
        return;
    }
    int t1 = 2ll * d, t2 = 3ll * d;
    if (p >= t1 && q >= t2) {
        no;
        return;
    }
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