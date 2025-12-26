#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int fact(int x)
{
    if (x <= 0)
        return 1;
    else
        return ((fact(x - 1) * x)) % M;
}
void marwan()
{
    string s;
    cin >> s;
    int n = s.size(), a = 0, b = 1, x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            x++;
            if (y > 1)
            {
                a += (y - 1), b = ((b * (y)) % M);
            }
            y = 0;
        }
        else
        {
            y++;
            if (x > 1)
            {
                a += (x - 1), b = ((b * x) % M);
            }
            x = 0;
        }
    }
    if (x > 1)
        a += (x - 1), b = (b * x) % M;
    if (y > 1)
        a += (y - 1), b = ((b * (y)) % M);
    b = (b * fact(a)) % M;
    cout << a << " " << max(b, 1ll) << endl;
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