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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (n == 1 || n == 2)
    {
        cout << -1 << endl;
        return;
    }
    int sum = accumulate(all(v), 0ll);
    int l = 0, r = 1e18, mid, ans = -1;
    auto ok = [&](int mid)
    {
        double x = ((double)sum + (double)mid) / (2 * (double)n);
        int count = 0;
        for (auto vl : v)
        {
            if (((double)x - (double)vl > 1e-15))
                count++;
        }
        return count > (n / 2);
    };

    while (l <= r)
    {
        mid = (l + (r - l) / 2);
        if (ok(mid))
        {
            ans = mid, r = mid - 1;
        }
        else
            l = mid + 1;
    }
    int count = 0;
    double ls = (sum + (int)ans) / (2 * n);
    for (auto vl : v)
    {
        if ((double)(vl) < ls)
            count++;
    }
    cout << (int)ans << endl;
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