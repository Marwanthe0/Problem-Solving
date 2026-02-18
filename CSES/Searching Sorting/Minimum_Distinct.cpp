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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), t;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i && v[i] != v[0])
            m[v[i]]++;
    }
    for (auto [x, y] : m)
    {
        t.push_back(y);
    }
    sort(t.begin(), t.end());
    int ans = m.size() + 1;
    for (auto vl : t)
    {
        if (vl <= k)
            ans--, k -= vl;
        else
            break;
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