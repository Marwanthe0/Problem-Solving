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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i)
                div.push_back(n / i);
        }
    }
    sort(all(div));
    int ans = 0;
    for (auto vl : div) {
        int m = 0;
        for (int i = vl; i < n; i++)
            m = __gcd(m, abs(v[i] - v[i - vl]));
        if (m != 1)
            ans++;
    }
    cout << ans << endl;
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