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
    if (s.size() == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1] && s[i] == '*')
        {
            cout << -1 << endl;
            return;
        }
        else if (s[i] == '<' && s[i - 1] == '>')
        {
            cout << -1 << endl;
            return;
        }
        else if (s[i] == '<' && s[i - 1] == '*')
        {
            cout << -1 << endl;
            return;
        }
        else if (s[i] == '*' && s[i - 1] == '>')
        {
            cout << -1 << endl;
            return;
        }
    }
    int count = 0, st = 0, end = n - 1, ans = 0;
    while (st < n)
    {
        if (s[st] == '>')
            break;
        else
            count++, st++;
    }
    ans = max(ans, count);
    count = 0;
    while (end >= 0)
    {
        if (s[end] == '<')
            break;
        else
            count++, end--;
    }
    ans = max(ans, count);
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