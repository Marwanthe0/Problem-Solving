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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    make_unique(divs);
    int l = 0, r = divs.size() - 1;
    int a = 1, b = n;
    while (l <= r) {
        int x = divs[l], y = divs[r];
        if ((x / __gcd(x, y)) * 1ll * y == n) {
            if (y < b)
                a = x, b = y;
        }
        l++, r--;
    }
    cout << a << " " << b << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}