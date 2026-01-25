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
    int n, m, mx = INT_MIN;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i].first;
    for (int i = 0; i < m; i++)
        cin >> v[i].second;
    sort(all(v));
    for (int i = 0; i < m; i++)
    {
        if (v[i].first <= mx)
            mx = max(mx, v[i].second);
        else
        {
            cout << i << endl;
            return;
        }
    }
    cout << m << endl;
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