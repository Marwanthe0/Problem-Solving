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
int ans(vector<int> &v, int idx, int n, int last, map<int, int> &dp)
{
    if (idx >= n)
        return (v[idx] > last);
    if (v[idx] <= last)
        return 0;
    int mx = 1;
    for (int i = idx + idx; i <= n; i += idx)
    {
        int point = ans(v, i, n, v[idx], dp) + 1;
        mx = max(mx, point);
    }
    return mx;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    map<int, int> dp;
    int final = 1;
    for (int i = 1; i <= n; i++)
    {
        final = max(ans(v, i, n, (-1) * 1e18, dp), final);
    }
    cout << final << endl;
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