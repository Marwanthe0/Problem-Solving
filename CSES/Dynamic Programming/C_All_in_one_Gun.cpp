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
void marwan()
{
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int sum = accumulate(all(v), 0ll), ans = h / sum;
    h = h - (ans * sum);
    int rem = (ans - (h == 0)) * k;
    ans *= n;
    ans += rem;
    // cerr << ans << " " << h << endl;
    if (h == 0)
    {
        cout << ans << endl;
        return;
    }
    int l = 0, r = n - 1, last = n - 1;
    auto ok = [&](int m)
    {
        int psum = accumulate(v.begin(), v.begin() + m + 1, 0ll), pmin = *min_element(v.begin(), v.begin() + m + 1), pmax = *max_element(v.begin() + m + 1, v.end());
        // cerr << m << " " << psum << " " << pmin << " " << pmax << endl;
        if (pmin < pmax)
            psum += (pmax - pmin);
        return psum >= h;
    };
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
            last = m + 1, r = m - 1;
        else
            l = m + 1;
    }
    // cerr << endl;
    cout << ans + last << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}