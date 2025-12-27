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
    int ans = 1, mn = INT_MAX;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                int x = n / i;
                int y = n - x;
                if ((x * y) / __gcd(x, y) < mn)
                {
                    mn = (x * y) / __gcd(x, y);
                    ans = x;
                }
            }
            int x = i;
            int y = n - x;
            if ((x * y) / __gcd(x, y) < mn)
            {
                mn = (x * y) / __gcd(x, y);
                ans = x;
            }
        }
    }
    cout << min(ans, n - ans) << " " << max(ans, n - ans) << endl;
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