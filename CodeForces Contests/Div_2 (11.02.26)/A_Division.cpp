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
vector<int> primes, pr(N + 1, 0);
void marwan() {
    int p, q;
    cin >> p >> q;
    if (p % q != 0) {
        cout << p << endl;
        return;
    }
    vector<int> pf;
    int temp = q;
    for (auto i : primes) {
        if (i > q)
            break;
        if ((q % i) == 0) {
            while ((q % i) == 0) {
                q /= i;
            }
            pf.push_back(i);
        }
    }
    if (q > 1)
        pf.push_back(q);
    q = temp;
    int ans = 0ll;
    for (auto vl : pf) {
        // cerr << vl << " ";
        int x = p;
        while ((x % q) == 0) {
            x /= vl;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i * i <= N; i++) {
        if (!pr[i]) {
            for (int j = i * i; j <= N; j += i)
                pr[j] = 1;
        }
    }
    for (int i = 2; i <= N; i++)
        if (!pr[i]) {
            primes.push_back(i);
        }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}