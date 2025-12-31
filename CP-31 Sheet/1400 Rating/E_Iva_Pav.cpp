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
    vector<int> v(n + 10);
    vector<vector<int>> pf(n + 10, vector<int>(32, 0));
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mx = max(mx, __lg(v[i]));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = mx; j >= 0; j--)
        {
            int x = ((v[i] >> j) & 1);
            //cerr << x;
        }
        //cerr << endl;
    }
    //cerr << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = mx; j >= 0; j--)
        {
            int x = ((v[i] >> j) & 1);
            pf[i][j] = pf[i - 1][j] + (!x);
            //cerr << pf[i][j] << " ";
        }
        //cerr << endl;
    }
    //cerr << endl;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, k;
        cin >> l >> k;
        if (v[l] < k)
        {
            cout << -1 << " ";
            continue;
        }
        int r = n, ans = l;
        auto ok = [&](int m)
        {
            int x = 0;
            for (int i = mx; i >= 0; i--)
            {
                if (pf[m][i] == pf[l - 1][i])
                {
                    x |= (1 << i);
                }
            }
            //cerr << l << " " << m << " " << x << endl;
            return x >= k;
        };
        int left = l;
        while (left <= r)
        {
            int m = left + (r - left) / 2;
            if (ok(m))
            {
                ans = m;
                left = m + 1;
            }
            else
                r = m - 1;
        }
        cout << ans << " ";
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