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
    int mx = INT_MIN, mn = INT_MAX;
    set<int> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            mx = max(mx, b);
        }
        else if (a == 2)
        {
            mn = min(mn, b);
        }
        else
            v.insert(b);
    }
    int ans = max(0ll, (mn - mx) + 1);
    int count = 0;
    for (auto vl : v)
        if (vl >= mx && vl <= mn)
            ans--;
    cout << ans << endl;
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