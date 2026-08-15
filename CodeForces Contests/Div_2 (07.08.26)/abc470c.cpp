#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    map<int, int> m;
    int dc = 0, ans = 0, odds = 0;
    while (k--) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            // ans = ans ^ v[y];
            // cerr << v[y] << " " << v[y] << endl;
            ans = ans ^ max(0ll, (v[y] - dc));
            int age = m[v[y]] % 2;
            m[v[y]]--;
            if (m[v[y]] < 0)
                m[v[y]] = 0;
            int pore = m[v[y]] % 2;
            odds += pore - age;
            v[y]++;
            ans = ans ^ max(0ll, (v[y] - dc));
            age = m[v[y]] % 2;
            m[v[y]]++;
            pore = m[v[y]] % 2;
            odds += pore - age;
            for (auto [x, y] : m) {
                cerr << x << " " << y << endl;
            }
            cerr << "odss" << odds << endl;
            // cerr << v[y] << " " << v[y] << endl;
            // ans = ans ^ v[y];
            cout << ans << endl;
        } else {
            dc++;
            ans -= odds;
            cout << ans << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}