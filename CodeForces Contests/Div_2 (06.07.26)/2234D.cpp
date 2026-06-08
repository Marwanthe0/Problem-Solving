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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int one1 = 0, one2 = 0, one3 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            one1++;
        if (t[i] == '1')
            one2++;
        if (s[i] != t[i])
            one3++;
    }
    int m = (1ll << k) + 1ll;
    int c = m / 3ll;
    int a = c, b = c;
    if (k % 2 == 0)
        a++, b++;
    cout << one1 * 1ll * (n - one1) * 1ll * a + one2 * 1ll * (n - one2) * 1ll * b + one3 * 1ll * (n - one3) * 1ll * c << endl;
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