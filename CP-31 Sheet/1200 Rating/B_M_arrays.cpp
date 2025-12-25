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
    vector<int> v(n);
    map<int, int> m;
    set<int> s;
    for (auto &vl : v)
    {
        cin >> vl;
        vl %= k;
        m[vl]++;
        s.insert(vl);
    }
    int ans = 0;
    if ((m.find(0) != m.end()))
        ans++, m.erase(0);
    // for (auto [x, y] : m)
    // {
    //     cerr << x << " " << y << endl;
    // }
    for (auto vl : s)
    {
        // cerr << ans << " ";
        if (m.find(vl) == m.end())
            continue;
        else
        {
            int rem = k - vl;
            if ((k % 2) == 0 && vl == (k / 2))
            {
                ans++;
            }
            else if (m.find(rem) != m.end())
            {
                int x = m[vl], y = m[rem];
                if (abs(x - y) <= 1)
                {
                    ans++;
                }
                else
                {
                    ans += abs(x - y);
                }
                m.erase(rem);
            }
            else
            {
                ans += m[vl];
            }
            m.erase(vl);
        }
    }
    // cerr << endl;
    cout << ans << endl;
    // cout << endl;
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