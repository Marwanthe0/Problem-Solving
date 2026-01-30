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
#define make_unique v.erase(unique(v.begin(), v.end()), v.end());
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return;
    }
    bool flag = true;
    if (s[0] == '1')
        v.push_back(0);
    for (auto c : s)
        if (c == '1')
            flag = false;
    if (flag)
    {
        cout << (n / 3 + (n % 3 != 0)) << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0, tt = 0;
        while (i < n && s[i] == '0')
        {
            i++, count++;
        }
        if (count)
            v.push_back(count);
    }
    if (s[n - 1] == '1')
        v.push_back(0);
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0 || i == v.size() - 1)
        {
            if (v[i] >= 1)
            {
                // cerr << "tc" << endl;
                int x = v[i] - 1;
                ans += (x / 3 + (x % 3 != 0));
            }
        }
        else if (v[i] >= 2)
        {
            int x = v[i] - 2;
            ans += (x / 3 + (x % 3 != 0));
        }
    }
    // cerr << ans << endl;
    for (auto vl : s)
        if (vl == '1')
            ans++;
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