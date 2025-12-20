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
    string s;
    cin >> s;
    int n = s.size();
    int o = 0;
    for (auto c : s)
        if (c == '1')
            o++;
    if (o == 0)
    {
        cout << 0 << endl;
    }
    else if (o == n)
        cout << n * n << endl;
    else
    {
        int count = 0, mx = INT_MIN;
        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i % n] == '1')
                count++;
            else
                mx = max(mx, count), count = 0;
        }
        int ans = 0;
        for (int i = 1; i <= mx; i++)
        {
            int x = i - 1, y = mx - i;
            ans = max(ans, (x + 1) * (y + 1));
        }
        cout << ans << endl;
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