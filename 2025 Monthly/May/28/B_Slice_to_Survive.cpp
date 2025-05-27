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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int count = 2;
    if (a == 1)
        count--;
    if (b == 1)
        count--;
    // c = min(c, a - c + 1), d = min(d, b - d + 1);
    if (max(c, a - c + 1) > max(d, b - d + 1))
    {
        c = min(c, a - c + 1);
    }
    else
        d = min(d, b - d + 1);
    // if (c != 1)
    //     count++;
    // if (d != 1)
    //     count++;
    while (c > 1)
    {
        c = (c / 2 + (c % 2)), count++;
    }
    while (d > 1)
    {
        d = (d / 2 + (d % 2)), count++;
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