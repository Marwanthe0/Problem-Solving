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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int low = 0, up = 1e18, ans = 0;
    auto ok = [&](int m)
    {
        int sum = 0;
        for (auto vl : v)
        {
            sum += max(0ll, m - vl);
            if (sum > k)
                return false;
        }
        return true;
    };
    while (low <= up)
    {
        int mid = low + ((up - low) / 2);
        if (ok(mid))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            up = mid - 1;
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