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
int bits(int x)
{
    int count = 0;
    while (x)
        x /= 2, count++;
    return count;
}
void marwan()
{
    int n;
    cin >> n;
    // cout << bits(n) << endl;
    int ans = n;
    for (int i = 0; i < bits(n); i += 2)
    {
        int x = (1 & (n >> i)), y = (1 & (n >> (i + 1)));
        if (x != y)
        {
            ans = (ans ^ (3 << i));
        }
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