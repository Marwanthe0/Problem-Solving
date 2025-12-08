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
    string s, t;
    cin >> s >> t;
    map<char, int> a, b;
    int n = s.size(), m = t.size();
    for (auto c : s)
        a[c]++;
    for (auto c : t)
        b[c]++;
    for (auto [x, y] : a)
    {
        if (b[x] < y)
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    string ans;
    for (auto &[x, y] : b)
    {
        while (y > a[x])
            ans.push_back(x), y--;
    }
    // cout << ans << endl;
    int l = 0, r = 0;
    while (l < n && r < ans.size())
    {
        if (s[l] <= ans[r])
        {
            cout << s[l++];
        }
        else
            cout << ans[r++];
    }
    while (l < n)
        cout << s[l++];
    while (r < ans.size())
        cout << ans[r++];
    cout << endl;
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