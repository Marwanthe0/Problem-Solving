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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int gd1 = v[0], gd2 = v[1];
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            gd2 = __gcd(gd2, v[i]);
        else
            gd1 = __gcd(gd1, v[i]);
    }
    // cerr << gd1 << " " << gd2 << endl;
    if (gd1 == gd2)
        cout << 0 << endl;
    else
    {
        bool flag1 = true, flag2 = true;
        for (int i = 1; i < n; i += 2)
        {
            if (v[i] % gd1 == 0)
            {
                flag1 = false;
                break;
            }
        }
        for (int i = 0; i < n; i += 2)
        {
            if (v[i] % gd2 == 0)
            {
                flag2 = false;
            }
        }
        if (flag1 && flag2)
        {
            cout << max(gd1, gd2) << endl;
        }
        else if (flag1)
        {
            cout << gd1 << endl;
        }
        else if (flag2)
        {
            cout << gd2 << endl;
        }
        else
            cout << 0 << endl;
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