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
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a > b)
        swap(a, b);
    if (b % a)
    {
        cout << -1 << endl;
        return;
    }
    int x = b / a;
    int count = 0;
    while (x)
    {
        if (x <= 8)
        {
            if (x == 2 || x == 4 || x == 8)
            {
                count++;
                break;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        else
        {
            if (x % 8 == 0)
            {
                x /= 8;
            }
            else if (x % 4 == 0)
            {
                x /= 4;
            }
            else if (x % 2 == 0)
            {
                x /= 2;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
            count++;
        }
    }
    cout << count << endl;
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