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
    vector<int> v(n + 1);
    forn cin >> v[i];
    auto ok = [&](int mid)
    {
        vector<int> t(v.begin(), v.begin() + mid + 1);
        sort(all(t));
        // for (auto vl : t)
        //     cerr << vl << " ";
        // cerr << endl;
        int x = k;
        while (!t.empty())
        {
            x -= t.back();
            t.pop_back();
            if (!t.empty())
                t.pop_back();
            if (x < 0)
                return false;
        }
        return true;
    };
    int l = 0, r = n - 1, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (ok(mid))
        {
            ans = mid + 1, l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}