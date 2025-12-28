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
    int t = 2 * n - 1, total = (n * (n + 1)) / 2;
    if (k <= total)
    {
        int ans = (int)(sqrt(1 + 8 * k) - 1) / 2;
        if (k > (ans * (ans + 1)) / 2)
            ans++;
        cout << ans << endl;
    }
    else if (k <= total + ((n * (n - 1)) / 2))
    {
        int z = n, rem = k - (((n * (n + 1)) / 2));
        n--;
        rem = ((n * (n + 1)) / 2) - rem;
        int ans = (int)((sqrt(1 + 8 * rem) - 1) / 2);
        cout << z + n - ans << endl;
    }
    else
        cout << t << endl;
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