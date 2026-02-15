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
    vector<int> a(n + 1, 0), v(n + 1);
    map<int, int> m, ml;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        m[v[i]] = i;
        a[i] = v[i];
    }
    sort(all(a));

    for (int i = 1; i <= n; i++)
    {
        if (ml[i])
            continue;
        for (int j = i; j <= n; j *= 2)
        {
            ml[j] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != v[i])
        {
            if (ml[m[a[i]]] != ml[m[v[i]]])
            {
                no;
                return;
            }
        }
    }
    yes;
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