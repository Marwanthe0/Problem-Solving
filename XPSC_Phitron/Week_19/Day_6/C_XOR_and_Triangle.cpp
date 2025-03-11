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
bool valid(int x, int y, int z)
{
    int temp = x + y + z;
    return (x + y > z && y + z > x && x + z > y);
}
void marwan()
{
    int n;
    cin >> n;
    if (((n & (n - 1)) == 0))
    {
        cout << -1 << endl;
        return;
    }
    if ((n & (n + 1)) == 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (valid(n, n ^ i, i))
        {
            cout << i << endl;
            return;
        }
    }
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