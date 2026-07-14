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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    if (x == 1 || y == 1) {
        yes;
        return;
    }
    if (x == y) {
        for (int i = 1; i <= n; i++) {
            if (v[i] == i)
                continue;
            if (abs(v[i] - i) % x != 0) {
                no;
                return;
            }
        }
        yes;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == i)
            continue;
        if (abs(v[i] - i) % x == 0 || abs(v[i] - i) % y == 0 || (abs(v[i] - i) % (__gcd(x, y)) == 0))
            continue;
        else {
            no;
            return;
        }
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