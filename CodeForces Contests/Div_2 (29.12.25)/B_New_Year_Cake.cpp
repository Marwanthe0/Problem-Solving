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
    int xa = a, xb = b;
    int count = 0, x = 1ll, count2 = 0ll;
    bool flag = true;
    while (1)
    {
        if (flag && a >= x)
            a -= x;
        else if (flag == 0 && b >= x)
            b -= x;
        else
            break;
        x *= 2, count++;
        flag = !flag;
    }
    x = 1ll;
    flag = false;
    a = xa, b = xb;
    while (1)
    {
        if (flag && a >= x)
            a -= x;
        else if (flag == 0 && b >= x)
            b -= x;
        else
            break;
        x *= 2, count2++;
        flag = !flag;
    }
    cout << max(count, count2) << endl;
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