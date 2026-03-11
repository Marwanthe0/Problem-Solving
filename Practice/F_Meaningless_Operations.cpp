#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
map<int, int> pr;
int f(int x) {
    int ans = 0ll;
    vector<int> div;
    div.push_back(1);
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            div.push_back(i);
            if (x / i != i)
                div.push_back(x / i);
        }
    }
    make_unique(div);
    for (auto vl : div) {
        ans = max(ans, __gcd(vl, x - vl));
    }
    return ans;
}
void marwan() {
    int a;
    cin >> a;
    if (pr.count(a))
        cout << pr[a] << endl;
    else {
        int x = 0ll;
        for (int i = __lg(a); i >= 0; i--) {
            if (!(1 & (a >> i)))
                x |= (1ll << i);
        }
        cout << __gcd(a ^ x, a & x) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1ll; i <= 25; i++) {
        int x = (1ll << i) - 1ll;
        pr[x] = f(x);
    }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}