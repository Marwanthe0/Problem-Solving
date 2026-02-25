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
    int x, y;
    cin >> x >> y;
    if (y < x)
        cout << x - y << endl;
    else
    {
        int count = 0;
        while (x != y)
        {
            if (x > y)
                y++;
            else
            {
                if (y & 1)
                    y++;
                else
                    y /= 2;
            }
            count++;
        }
        cout << count << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}