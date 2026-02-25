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
bool f(int i, int j, int k, string &s, string &t)
{
    if (k == t.size())
        return true;
    if (s[k] == t[i])
    {
        return f(i + 1, j, k + 1, s, t);
    }
    else if (s[k] == t[j])
        return f(i, j - 1, k + 1, s, t);
    else
    {
        if (s[k] == '?')
        {
            if (t[i] == t[j])
                return f(i + 1, j, k + 1, s, t);
            else
            {
                return f(i + 1, j, k + 1, s, t) || f(i, j - 1, k + 1, s, t);
            }
        }
        else
        {
            return false;
        }
    }
}
void marwan()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (i & 1)
            t.push_back('b');
        else
            t.push_back('a');
    if (f(0, n - 1, 0, s, t))
        yes;
    else
        no;
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