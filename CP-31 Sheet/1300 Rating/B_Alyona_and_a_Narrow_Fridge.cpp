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
    int l = 0, r = n - 1, ans = 0;
    auto ok = [&](int m)
    {
        vector<int> t(v.begin(), v.begin() + m + 1);
        sort(all(t), greater<int>());
        int x = k;
        for (int i = 0; i < t.size(); i += 2)
        {
            x -= t[i];
            if (x < 0)
                return false;
        }
        return true;
    };
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
        {
            ans = m + 1;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}