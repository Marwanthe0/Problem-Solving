#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Bob" << endl
#define no cout << "Alice" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    int g = 0;
    int mx = 0;
    for (auto &vl : v) {
        cin >> vl;
        g = __gcd(vl, g);
        mx = max(mx, vl);
    }
    if (g == 1) {
        if ((mx - n) & 1) {
            no;
        } else
            yes;
        return;
    } else {
        if (((mx / g) - n) & 1)
            no;
        else
            yes;
        return;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}