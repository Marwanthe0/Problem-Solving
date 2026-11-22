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
void marwan(int cs) {
    int x;
    cin >> x;
    int y = sqrt(x - 1);
    int c = 1, r = 1;
    if (y % 2 == 0) {
        int diff = x - y * y;
        if (diff <= y + 1)
            c = y + 1, r = x - y * y;
        else
            r = y + 1, c = (y + 1) * (y + 1) - x + 1;
    } else {
        int diff = x - y * y;

        if (diff <= y + 1)
            r = y + 1,
            c = x - y * y;
        else
            c = y + 1, r = (y + 1) * (y + 1) - x + 1;
    }
    cout << c << " " << r << endl;
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