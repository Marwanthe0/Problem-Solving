#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int odd = 0, even = 0, odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            if (i & 1)
                odd++;
            else
                even++;
        }
        if (a[i] == '1') {
            if (i & 1)
                odds++;
            else
                evens++;
        }
    }
    if (odds == odd && evens == even)
        yes;
    else
        no;
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