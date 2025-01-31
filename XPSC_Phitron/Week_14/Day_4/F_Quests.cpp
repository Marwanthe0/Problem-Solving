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
void marwan()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    if (v.back() * d < c)
    {
        cout << "Impossible\n";
        return;
    }
    int sum = 0;
    for (int i = 0; i < min(d, n); i++)
    {
        sum += v[n - i - 1];
    }
    if (sum >= c)
    {
        cout << "Infinity\n";
        return;
    }
    auto ok = [&](int mid)
    {
        int sum = 0, count = 0;
        for (int i = 1; i <= d; i++)
        {
            if (count < n)
                sum += v[(n - count) - 1];
            count++;
            if (count > mid)
                count = 0;
        }
        return sum >= c;
    };
    int l = 0, r = 1e12, mid, ans;
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        if (ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
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