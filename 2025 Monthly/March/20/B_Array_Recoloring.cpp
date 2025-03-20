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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (k == 1)
    {
        int x = v[0], y = v[n - 1], mx = 0, mn = 0;
        for (int i = 0; i < n; i++)
        {
            if (i)
                mx = max(mx, v[i]);
            if (i != n - 1)
                mn = max(mn, v[i]);
        }
        cout << max(v[0] + mx, v[n - 1] + mn) << endl;
    }
    else
    {
        int sum = 0;
        sort(all(v), greater<int>());
        for (int i = 0; i <= k; i++)
            sum += v[i];
        cout << sum << endl;
    }
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