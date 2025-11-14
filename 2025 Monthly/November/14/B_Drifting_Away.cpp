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
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int start = 0, end = n - 1, count = 0, ans = INT_MIN, star = 0;
    // cout << (int32_t(s[0])) << endl;
    while (start < n)
    {
        if (s[start] == '<')
            start++, count++, star = 0;
        else if (s[start] == '*' && count > 0 && star < 1)
        {
            star++, count++;
        }
        else
            break;
    }
    if (count > 0)
        ans = max(ans, count);
    count = 0;
    while (end >= 0)
    {
        if (s[end] == '>')
            end--, count++, star = 0;
        else if (s[end] == '*' && count > 0 && star < 1)
            star++, count++;
        else
            break;
    }
    if (count > 0)
        ans = max(ans, count);
    if (ans == INT_MIN)
        cout << -1 << endl;
    else
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