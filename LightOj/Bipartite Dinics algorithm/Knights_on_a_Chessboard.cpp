#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int f(int x, int y) {
    return ((x + 1) / 2) * ((y + 1) / 2) + (x / 2) * (y / 2);
}
void marwan(int cs) {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    if (min(a, b) == 1)
        cout << a * b << endl;
    else if (min(a, b) == 2)
        cout << (b / 4) * 4 + min(2ll, b % 4) * 2 << endl;
    else
        cout << max({f(a, b), f(b, a)}) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}