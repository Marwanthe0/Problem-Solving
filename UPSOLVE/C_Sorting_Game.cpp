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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
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
    int l = 0, r = n - 1;
    while (s[l] != '1')
        l++;
    while (s[r] != '0')
        r--;
    int to = 0, tz = 0, co = 0, cz = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '1')
            to++;
        else
            tz++;
    }
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '1')
            co++;
        else
            tz--;
        if (co == tz)
        {
            cout << "Alice" << endl;
            set<int> ans;
            for (int j = l; j <= r; j++)
            {
                if (j <= i && s[j] == '1')
                    ans.insert(j + 1);
                if (j >= i && s[j] == '0')
                    ans.insert(j + 1);
            }
            cout << ans.size() << endl;
            for (auto vl : ans)
                cout << vl << " ";
            cout << endl;
            return;
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