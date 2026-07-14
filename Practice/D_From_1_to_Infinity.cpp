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
    int count = 1, inc = 9, x = 0ll, sum = 0ll;
    while (1) {
        int tx = x + count * 1ll * inc;
        if (tx > n)
            break;
        x = tx;
        int tsum = (count * 45) * (inc / 9);
        cerr << x << " " << tsum << endl;
        sum += tsum;
        count++;
        inc *= 10ll;
    }

    int rem = n - x;
    int jabe = rem / count;
    int extra = rem % count;
    
    cout << x << " " << inc / 9 << " " << sum << " " << rem << " " << count << endl;
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