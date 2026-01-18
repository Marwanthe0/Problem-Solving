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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), a(n);
    vector<pair<int, int>> t(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        a[i] = v[i];
    }
    vector<pair<int, int>> op;
    int last = -1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        op.push_back({x, y});
        if (last > t[x].second)
        {
            t[x].first = 0;
        }
        t[x].first += y;
        t[x].second = i;
        if (v[x] + t[x].first > k)
        {
            last = i;
            t[x].first = 0;
        }
    }
    // cout << last << endl;
    for (int i = last + 1; i < m; i++)
        v[op[i].first] += op[i].second;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
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