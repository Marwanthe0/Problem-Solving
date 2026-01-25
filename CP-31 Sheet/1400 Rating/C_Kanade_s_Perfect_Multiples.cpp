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
    set<int> s, ans, ch;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        ch.insert(x);
    }

    auto it = s.begin();
    while (1)
    {
        if (it == s.end())
            break;
        for (int i = *it; i <= k; i += *it)
        {
            if (ch.find(i) == ch.end())
            {
                cout << -1 << endl;
                return;
            }
            else if (i != *it && s.find(i) != s.end())
                s.erase(i);
        }
        ans.insert(*it);
        if (it == s.end())
            break;
        it++;
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