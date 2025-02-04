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
    vector<int> v(n + 1, 0), nne(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int l = n, ll = n;
    for (int i = n; i >= 1; i--)
    {
        if (v[i] == v[l] && v[i] == v[ll])
        {
            nne[i] = n + 1;
            ll = l, l = i;
        }
        else if (v[i] != v[l])
        {
            nne[i] = l;
            ll = l, l = i;
        }
        else if (v[i] != v[ll])
        {
            nne[i] = ll;
            l = i;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << nne[i] << " ";
    // cout << endl;
    int q;
    cin >> q;
    vector<pair<int, int>> query(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        if (nne[query[i].first] <= query[i].second)
        {
            cout << query[i].first << " " << nne[query[i].first] << endl;
        }
        else
            cout << -1 << " " << -1 << endl;
    }
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