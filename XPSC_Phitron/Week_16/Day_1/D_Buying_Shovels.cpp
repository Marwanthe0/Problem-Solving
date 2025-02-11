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
    if (k >= n)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> v;
    for (int i = 1; (i * i) <= n; i++)
    {
        if (i > k)
            break;
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i <= k)
                v.push_back(n / i);
        }
    }
    int ans = INT_MAX;
    sort(all(v));
    for (auto vl : v)
    {
        ans = min(ans, n / vl);
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