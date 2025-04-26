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
    string s, t;
    cin >> s >> t;
    if (s.front() != t.front())
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != t[i] && s[i] == '0')
        {
            if (s[i - 1] == '1')
            {
                s[i] = t[i], ans.push_back(i);
            }
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] != t[i])
        {
            if (s[i - 1] == '1')
                s[i] = t[i], ans.push_back(i);
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for (auto vl : ans)
        cout << vl << " ";
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