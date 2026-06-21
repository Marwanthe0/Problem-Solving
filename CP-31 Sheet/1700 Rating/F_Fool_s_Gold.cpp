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
    int cnt = 0;
    int count = 0;
    auto lcm = [](int a, int b) { return (a / __gcd(a, b)) * 1ll * b; };
    set<int> s;
    for (int i = 1; i <= 1e3; i++) {
        if (n % i == 0) {
            int x = i, y = n / i;
            if ((__gcd(x, n) + lcm(x, n)) == x + n)
                s.insert(x);
            if ((__gcd(y, n) + lcm(y, n)) == y + n)
                s.insert(y);
        }
        if (n % (i * i) == 0) {
            int x = i * i, y = n / (i * i);
            if ((__gcd(x, n) + lcm(x, n)) == x + n)
                s.insert(x);
            if ((__gcd(y, n) + lcm(y, n)) == y + n)
                s.insert(y);
        }
    }
    for (auto vl : s) {
        if (vl == n)
            continue;
        if ((int)sqrt(vl) * (int)(sqrt(vl)) == vl) {
            count++;
            // cerr << vl << " ";
        }
    }
    // cerr << endl;
    cout << count << endl;
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