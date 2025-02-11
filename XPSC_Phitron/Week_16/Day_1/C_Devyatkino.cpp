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
bool cont(string s)
{
    for (auto c : s)
        if (c == '7')
            return true;
    return false;
}
void marwan()
{
    int n;
    cin >> n;
    int x = n, count = 0, y = 0, z = x, ans = INT_MAX;
    while (1)
    {
        y = (y * 10) + 9;
        count = 0;
        for (int i = 0; i <= 7; i++, count++)
        {
            if (cont(to_string(x)))
            {
                ans = min(ans, count);
                // cerr << count << " " << y << " " << x << endl;
            }
            x += y;
        }
        x = z;
        if (to_string(y).size() == to_string(n).size())
        {
            break;
        }
    }
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