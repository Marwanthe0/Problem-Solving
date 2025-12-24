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
bool pal(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mn = INT_MAX;
    for (char c = 'a'; c <= 'z'; c++)
    {
        string t;
        for (auto ch : s)
            if (ch != c)
                t.push_back(ch);
        if (pal(t))
        {
            int l = 0, r = n - 1, count = 0;
            while (l < r)
            {
                if (s[l] != s[r])
                {
                    if (s[l] == c)
                        l++, count++;
                    else
                        r--, count++;
                }
                else
                    l++, r--;
            }
            mn = min(mn, count);
        }
    }
    if (mn == INT_MAX)
        cout << -1 << endl;
    else
        cout << mn << endl;
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