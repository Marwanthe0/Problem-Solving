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
int sz(int n)
{
    int count = 0;
    while (n)
        n /= 10, count++;
    return count;
}
void marwan()
{
    int n;
    cin >> n;
    int x = 1, count = 0;
    while (x <= n)
    {
        if ((sz(x) == sz(n)))
        {
            if ((sz(n) & 1))
                count += ((n - x) + 1ll);
            break;
        }
        if (sz(x) & 1)
        {
            int nx = x * 10ll;
            count += (nx - x);
        }
        x *= 10ll;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}