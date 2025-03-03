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
bool sub(string s, string t)
{
    int l = 0;
    for (auto c : s)
    {
        if (c == t[l])
        {
            l++;
        }
    }
    return l == t.size();
}
void marwan()
{
    string a, b;
    cin >> a;
    cin >> b;
    int x = a.size(), y = b.size(), l = b.size() - 1;
    vector<int> v(x);
    for (int i = x - 1; i >= 0; i--)
    {
        if (a[i] == b[l])
        {
            v[i] = 1;
            l--;
        }
        else
            v[i] = 0;
        if (l < 0)
            break;
    }
    if (l >= 0)
    {
        cout << -1 << endl;
        return;
    }
    int count = 1, ans = 0;
    for (auto vl : v)
    {
        if (vl)
        {
            count++;
        }
        else
            ans += count;
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