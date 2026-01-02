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
    int ans = 0ll;
    int x = 0ll, y = 1ll;
    for (int i = 1ll; (1ll << (i - 1ll)) <= n; i++)
    {
        ans += i * (max(0ll, ((n - (1ll << x)) / (1ll << y)) + 1ll));
        x++, y++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // map<int, int> m;
    // for (int i = 0; i < 500; i++)
    // {
    //     cout << i + 1 << endl;
    //     m[__builtin_popcount(i ^ (i + 1))]++;
    //     for (auto &[x, y] : m)
    //         cout << x << " " << y << endl;
    // }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}