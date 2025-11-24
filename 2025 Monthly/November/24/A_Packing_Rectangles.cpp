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
    int w, h, n;
    cin >> w >> h >> n;
    int l = 1, r = max(w, h) * (1ll) * n, ans;
    auto ok = [&](long long m)
    {
        long long a = m / w;
        long long b = m / h;
        if (a == 0 || b == 0)
            return false;
        if (a > n)
            a = n;
        if (b > n)
            b = n;
        return a * b >= n; // a, b, n ≤ 1e9 → product ≤ 1e18, safe
    };

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
        {
            ans = m, r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}