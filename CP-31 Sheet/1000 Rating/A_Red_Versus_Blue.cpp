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
    int n, x, y;
    cin >> n >> x >> y;
    int k = (x / (y + 1)) + (x % (y + 1) != 0), rem = x % (y + 1), flag = rem;
    int t = k;
    for (int i = 0; i < n; i++)
    {
        if (t && x)
        {
            cout << 'R';
            t--, x--;
        }
        else
        {
            cout << 'B';
            if (x)
                t = k;
            if (flag)
            {
                rem--;
                if (rem <= 0)
                    t--;
            }
        }
    }
    cout << endl;
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