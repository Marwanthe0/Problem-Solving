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
#define make_unique v.erase(unique(v.begin(), v.end()), v.end());
vector<int> v;
void marwan()
{
    int n;
    cin >> n;
    int ans = __builtin_popcountll(n);
    for (int mask = 1; mask <= (1ll << 12); mask++)
    {
        int sum = 0ll, count = 0ll;
        for (int i = 0; i < 12; i++)
        {
            if (1 & (mask >> i))
            {
                sum += v[i];
            }
        }
        if (sum > n)
            continue;
        count = __builtin_popcountll(mask);
        count += __builtin_popcountll(n - sum);
        ans = min(ans, count);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x = 1ll;
    for (int i = 1ll; i <= 14; i++)
    {
        x *= i;
        if (x > 2)
            v.push_back(x);
    }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}