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
int tt(int a, int b)
{
    int x = a;
    for (int i = 0; i < b; i++)
    {
        a *= x;
        if (a > 26)
            return 27;
    }
    return a;
}
void marwan()
{
    int a, v, l, n;
    cin >> a >> v >> l >> n;
    if (n >= min(tt(a, l), v))
        no;
    else
        yes;
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