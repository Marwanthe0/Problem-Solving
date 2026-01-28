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
    if (is_sorted(all(s)))
    {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    int first, last;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            first = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '0')
        {
            last = i;
            break;
        }
    // cerr << first << " " << last << endl;
    vector<int> pf(last - first + 1), df(last - first + 1);
    int xx = last;
    for (int i = first; i <= last; i++, xx--)
    {
        if (s[i] == '1')
        {
            pf[i - first] = ((i - first) ? pf[(i - first) - 1] + 1 : 1);
        }
        else
        {
            pf[i - first] = ((i - first) ? pf[(i - first) - 1] : 1);
        }
        if (s[xx - first] == '0')
            df[xx - first] = (xx - last ? df[(xx - first) + 1] + 1 : 1);
        else
            df[xx - first] = (xx - last ? df[(xx - first) + 1] : 1);
    }
    set<int> ans;
    for (int i = 0; i < pf.size(); i++)
    {
        // cerr << pf[i] << " ";
        if (pf[i] == df[i])
            ans.insert(i + first + 1);
        else if (pf[i] < df[i] && s[i + first] == '1')
            ans.insert(i + first + 1);
        else if (pf[i] > df[i] && s[i + first] == '0')
            ans.insert(i + first + 1);
    }
    // cerr << endl;
    // for (auto vl : df)
    //     cerr << vl << " ";
    // cerr << endl;
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