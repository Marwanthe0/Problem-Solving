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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int l = 0, r = 0;
    while (l < m)
    {
        while (r < n && a[r] != b[l])
            r++;
        if (r == n && l != m)
        {
            cout << -1 << endl;
            return;
        }
        l++;
    }
    int l = 0, r = 0, ans = 0;
    if (a == b)
    {
        cout << 0 << endl;
    }
    while (r < m)
    {
        while ()
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