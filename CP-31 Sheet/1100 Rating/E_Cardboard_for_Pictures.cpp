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
    int mn = 0;
    for (auto &vl : v)
    {
        cin >> vl;
        mn += vl * vl;
    }
    int l = 1, r = 1e10, ans = 0;
    auto ok = [&](int m)
    {
        int sum = 0;
        for (auto vl : v)
        {
            if (sum + (((vl + (2 * m)) * (vl + (2 * m)))) > k)
            {
                return 1;
            }
            sum += ((vl + (2 * m)) * (vl + (2 * m)));
        }
        if (sum == k)
            return 0;
        else if (sum < k)
            return -1;
        else
            return 1;
    };
    while (l <= r)
    {
        int m = l + ((r - l) / 2);
        // cerr << m << " ";
        if (ok(m) == 0)
        {
            cout << m << endl;
            return;
        }
        else if (ok(m) < 0)
        {
            l = m + 1;
        }
        else
            r = m - 1;
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