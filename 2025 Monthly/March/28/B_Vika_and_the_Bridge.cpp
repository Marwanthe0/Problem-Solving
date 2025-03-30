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
    vector<int> pos(k + 1, -1);
    vector<pair<int, int>> v(k + 1, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int dif = i - pos[x] - 1;
        pos[x] = i;
        if (dif >= v[x].first)
        {
            v[x].second = v[x].first;
            v[x].first = dif;
        }
        if (dif != v[x].first)
            v[x].second = max(v[x].second, dif);
    }
    for (int i = 1; i <= k; i++)
    {
        int dif = n - pos[i] - 1;
        if (dif >= v[i].first)
        {
            v[i].second = v[i].first;
            v[i].first = dif;
        }
        if (dif != v[i].first)
            v[i].second = max(v[i].second, dif);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        // cout << i << "::";
        // cout << v[i].first << " " << v[i].second << endl;
        ans = min(ans, max(v[i].first / 2, v[i].second));
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