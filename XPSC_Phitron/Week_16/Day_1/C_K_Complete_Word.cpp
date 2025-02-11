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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int vis[n] = {0}, cnt = 0;
    vector<string> vs;
    for (int i = 0; i < n / 2; i++)
    {
        string x;
        if (!vis[i])
        {
            for (int j = i; j < n; j += k)
            {
                if (vis[j] == 0)
                {
                    x.push_back(s[j]);
                    vis[j] = 1;
                }
                if (vis[n - j - 1] == 0)
                {
                    x.push_back(s[n - j - 1]);
                    vis[n - j - 1] = 1;
                }
            }
        }
        if (x.size())
            vs.push_back(x);
    }
    int ans = 0;
    for (auto vl : vs)
    {
        map<char, int> m;
        int x = INT_MIN, y;
        for (auto c : vl)
        {
            m[c]++;
            if (m[c] > x)
            {
                x = m[c], y = c;
            }
        }
        for (auto c : vl)
            if (c != y)
                ans++;
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