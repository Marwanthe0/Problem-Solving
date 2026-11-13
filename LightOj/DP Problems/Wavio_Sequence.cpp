#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
int n;
vector<int> v, a, pf, sf;

void marwan(int cs) {
    cin >> n;
    a.clear();
    v.assign(n, 0);
    pf.assign(n, 0);
    sf.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        auto it = lower_bound(all(a), v[i]);
        if (it == a.end())
            a.push_back(v[i]);
        else
            *it = v[i];
        pf[i] = a.size();
    }
    a.clear();
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(all(a), v[i]);
        if (it == a.end())
            a.push_back(v[i]);
        else
            *it = v[i];
        sf[i] = a.size();
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 2 * min(pf[i], sf[i]) - 1);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}