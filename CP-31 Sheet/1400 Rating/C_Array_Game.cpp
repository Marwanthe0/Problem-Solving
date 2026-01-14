#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()

void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (k >= 3)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(v));
    int ans = v[0];

    if (k == 1)
    {
        for (int i = 1; i < n; i++)
            ans = min(ans, v[i] - v[i - 1]);

        cout << ans << endl;
        return;
    }
    int mn = ans;
    vector<int> ms = v;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = v[j] - v[i];
            mn = min(mn, x);
            if (x == 0)
            {
                cout << 0 << endl;
                return;
            }
            auto it = lower_bound(all(ms), x);
            if (it != ms.end())
                mn = min(mn, abs(*it - x));
            if (it != ms.begin())
                mn = min(mn, abs(*prev(it) - x));
            if (mn == 0)
            {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << mn << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        marwan();
}
