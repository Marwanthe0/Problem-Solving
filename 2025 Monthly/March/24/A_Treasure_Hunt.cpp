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
    int a, b, c;
    cin >> a >> b >> c;
    int x = ((c / (a + b)) + (c % (a + b) != 0)) - 1;
    for (int i = (x * (a + b));;)
    {
        i += a;
        if (i > c)
        {
            no;
            return;
        }
        i += b;
        if (i > c)
        {
            yes;
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