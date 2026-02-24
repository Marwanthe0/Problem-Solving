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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int a, b;
    cin >> a >> b;
    if (b < 0)
    {
        if (a >= (4 * (-b)) && ((a + 4 * b) % 3) == 0)
            yes;
        else
            no;
    }
    else
    {
        if (a >= (2 * b) && (a - 2 * b) % 3 == 0)
            yes;
        else
            no;
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