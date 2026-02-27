#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000009
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> p(N + 1, 0), mp(N + 1, 0);
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (is_sorted(all(v)))
    {
        no;
        return;
    }
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, mp[v[i]]);
        cerr << v[i] << " " << p[v[i]] << " " << mp[v[i]] << endl;
        if (p[v[i]] < mx)
        {
            yes;
            return;
        }
    }
    cerr << endl;
    no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p[1] = 1, mp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!p[i])
        {
            for (int j = i; j <= N; j += i)
            {
                if (!p[j])
                    p[j] = i;
                mp[j] = max(mp[j], i);
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}