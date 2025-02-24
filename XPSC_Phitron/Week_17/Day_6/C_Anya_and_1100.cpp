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
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> m;
    if (s.size() > 3)
    {
        string x;
        for (int i = 0; i < n; i++)
        {
            x.push_back(s[i]);
            if (i >= 3)
            {
                if (x == "1100")
                {
                    m[i]++, m[i - 1]++, m[i - 2]++, m[i - 3]++;
                }
                x.erase(x.begin());
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        a--;
        if (m.find(a) != m.end())
        {
            string tt;
            for (int i = max(0ll, a - 3); i < min(n, a + 4); i++)
            {
                tt.push_back(s[i]);
                if (tt.size() == 4)
                {
                    if (tt == "1100")
                    {
                        m.erase(i);
                        m.erase(i - 1);
                        m.erase(i - 2);
                        m.erase(i - 3);
                    }
                    tt.erase(tt.begin());
                }
            }
            s[a] = b;
            tt.clear();
            for (int i = max(0ll, a - 3); i < min(n, a + 4); i++)
            {
                tt.push_back(s[i]);
                if (tt.size() == 4)
                {
                    if (tt == "1100")
                    {
                        m[i]++, m[i - 1]++, m[i - 2]++, m[i - 3]++;
                    }
                    tt.erase(tt.begin());
                }
            }
            if (m.size())
            {
                yes;
            }
            else
                no;
        }
        else
        {
            s[a] = b;
            string tt;
            for (int i = max(0ll, a - 3); i < min(n, a + 4); i++)
            {
                tt.push_back(s[i]);
                if (tt.size() == 4)
                {
                    if (tt == "1100")
                    {
                        m[i]++, m[i - 1]++, m[i - 2]++, m[i - 3]++;
                    }
                    tt.erase(tt.begin());
                }
            }
            if (m.size())
            {
                yes;
            }
            else
                no;
        }
    }
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