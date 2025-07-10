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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b < a)
    {
        if ((a & 1) && a - 1 == b)
            cout << y << endl;
        else
            cout << -1 << endl;
        return;
    }
    int op = 0;
    while (a != b)
    {
        if (a & 1)
        {
            op += x;
        }
        else
            op += min(x, y);
        a++;
    }
    cout << op << endl;
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