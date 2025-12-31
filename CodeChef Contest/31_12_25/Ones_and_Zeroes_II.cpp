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
    string s;
    cin >> s;
    int z = 0, o = 0, ans = 0, x = 0, y = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            x++;
        else
        {
            y++;
            v.push_back(i);
        }
    }
    string t;
    for (int i = 0; i < n; i++)
    {
        if (y > 0 && (t.empty() || (!t.empty() && t.back() == '0')))
        {
            t.push_back('1'), y--;
        }
        else if (x > 0)
            t.push_back('0'), x--;
    }
    while (y--)
        t.push_back('1');
    // cerr << t << endl;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '0')
            o++;
        else
            z++;
        if (z >= o)
            ans++;
    }
    int sum = 0, l = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '1')
        {
            sum += max(0ll, v[l++] - i);
        }
    }
    cout << ans << " " << sum << endl;
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