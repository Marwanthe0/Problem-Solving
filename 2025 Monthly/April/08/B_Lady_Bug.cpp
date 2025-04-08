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
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0, m = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
            if (i & 1)
                x++;
            else
                y++;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0')
        {
            if (i & 1)
                t++;
            else
                m++;
        }
    }
    x -= m, y -= t;
    if (x <= 0 && y <= 0)
        yes;
    else
        no;
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