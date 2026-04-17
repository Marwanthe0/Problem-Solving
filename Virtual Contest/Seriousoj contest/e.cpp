#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Roy" << endl
#define no cout << "Hridoy" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (m.count(i) == 0 || (m[i] < 2))
                m[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        if (!m.count(n) || (m[n] < 2))
            m[n]++;
    }
    int ans = 0;
    for (auto [x, y] : m) {
        ans += y;
    }
    if (ans & 1)
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