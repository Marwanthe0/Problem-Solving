#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "-1" << endl
void marwan()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else if (n == 3)
        {
            cout << 1 << endl;
        }
        else
            no;
    }
    else
    {
        if ((n >> 1) & 1)
        {
            if (n == 2)
            {
                cout << 1 << endl;
                return;
            }
            else if (n == 6)
            {
                cout << 2 << endl;
            }
            else
            {
                no;
            }
        }
        else
        {
            int count = 0, hi = __lg(n);
            if ((n & (n - 1)) == 0)
            {
                cout << hi << endl;
                return;
            }
            for (int i = 2; i <= hi; i++)
            {
                if ((n >> i) & 1)
                    continue;
                else
                    count++;
            }
            cout << hi + 2 << endl;
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