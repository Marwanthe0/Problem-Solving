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
    int l = 0, r = n - 1;
    while (l < n && s[l] != '*')
        l++;
    while (r >= 0 && s[r] != '*')
        r--;
    if (r < l)
    {
        cout << 0 << endl;
        return;
    }
    string t;
    for (int i = l; i <= r; i++)
    {
        t.push_back(s[i]);
    }
    s = t;
    int star = 0, sidx = 0;
    for (auto c : s)
        if (c == '*')
            star++;
    n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
            sidx++;
        if (sidx == ((star / 2) + (star % 2)))
        {
            sidx = i;
            break;
        }
    }
    int ans = 0, cnt = 0, tnt = 0;
    for (int i = sidx; i >= 0; i--, tnt++)
    {
        if (s[i] == '*')
        {
            ans += (tnt - cnt);
            cnt++;
        }
    }
    cnt = 0, tnt = 0;
    for (int i = sidx; i < n; i++, tnt++)
    {
        if (s[i] == '*')
        {
            ans += (tnt - cnt);
            cnt++;
        }
    }
    if (n && (n % 2 == 0))
    {
        sidx++;
        int ans2 = 0;
        cnt = 0, tnt = 0;
        for (int i = sidx; i >= 0; i--, tnt++)
        {
            if (s[i] == '*')
            {
                ans2 += (tnt - cnt);
                cnt++;
            }
        }
        cnt = 0, tnt = 0;
        for (int i = sidx; i < n; i++, tnt++)
        {
            if (s[i] == '*')
            {
                ans2 += (tnt - cnt);
                cnt++;
            }
        }
        cout << min(ans2, ans) << endl;
        return;
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