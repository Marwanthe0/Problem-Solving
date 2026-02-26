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
int binexp(int a, int b)
{
    int ans = 1ll;
    while (b)
    {
        if (b & 1ll)
            ans = (a * 1ll * ans) % M;
        a = (a * 1ll * a) % M;
        b >>= 1ll;
    }
    return ans;
}
void marwan()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }
    if (n > 1)
        m[n]++;
    int ans = 1ll;
    for (auto [x, y] : m)
    {
        ans = ans * 1ll * x;
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