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
    vector<int> v(n), ans;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = i, as = i;
        auto ok = [&](int m)
        {
            return v[m] >= ((i - m) + 1);
        };
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (ok(m))
            {
                as = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        ans.push_back((i - as) + 1);
    }
    for (auto vl : ans)
        cout << vl << " ";
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