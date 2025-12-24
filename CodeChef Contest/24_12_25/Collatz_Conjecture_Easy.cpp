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
    if (n & 1)
    {
        if (n == 1 || n == 3)
            yes;
        else
            no;
    }
    else
    {
        if ((n >> 1) & 1)
        {
            int x = __lg(n);
            bool flag = false;
            for (int i = x; i >= 0; i--)
            {
                int t = ((n >> i) & 1);
                if (!t)
                    flag = true;
                if (flag && t)
                {
                    no;
                    return;
                }
            }
            if (n == 2 || n == 6)
            {
                yes;
                return;
            }
            else if (((n >> 1) & 1))
            {
                no;
            }
            else
                yes;
        }
        else
            yes;
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