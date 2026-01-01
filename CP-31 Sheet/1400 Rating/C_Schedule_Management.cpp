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
    cin >> k >> n;
    vector<int> v(n);
    map<int, int> m;
    int mx = INT_MIN;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
        mx = max(mx, m[vl]);
    }
    int l = 1, r = mx, ans = mx;
    auto ok = [&](int mid)
    {
        int count = 0;
        for (int i = 1; i <= k; i++)
        {
            if (m[i] >= mid)
                count += mid;
            else
                count += m[i] + ((mid - m[i]) / 2);
        }
        // cerr << mid << " " << count << endl;
        // ;
        return count >= n;
    };
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    // cerr << endl;
    // cerr << ok(ans) << endl;
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