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
    for (auto &c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A') + 'a';
        }
    }
    map<char, int> m;
    multiset<int, greater<int>> ms;
    for (auto c : s)
    {
        m[c]++;
    }
    for (auto [x, y] : m)
        ms.insert(y);
    if (ms.size() > 1)
        cout << *ms.begin() + *(++ms.begin()) << endl;
    else
        cout << *ms.begin() << endl;
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