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
    int a, b, x;
    cin >> a >> b >> x;
    int ans = 0, dist = abs(a - b);
    while (a != b) {
        if (a > b)
            swap(a, b);
        if (abs(a - b) == 1) {
            a++;
        } else
            b /= x;
        ans++;
        dist = min(dist, ans + abs(a - b));
    }
    cout << min(dist, ans) << endl;
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