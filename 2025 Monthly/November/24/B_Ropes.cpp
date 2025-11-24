#include <bits/stdc++.h>
using namespace std;

#define int long long

void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;

    long double l = 0.0;
    long double r = *max_element(v.begin(), v.end()); // upper bound = longest rope
    long double ans = 0.0;

    auto ok = [&](long double m) -> bool
    {
        if (m == 0.0L)
            return true; // avoid division by zero
        long long cnt = 0;
        for (int len : v)
        {
            cnt += (long long)((long double)len / m);
            if (cnt >= k)
                return true;
        }
        return false;
    };

    // binary search on the length
    for (int it = 0; it < 100; ++it)
    { // 100 iterations is plenty
        long double mid = (l + r) / 2.0L;
        if (ok(mid))
        {
            ans = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << fixed << setprecision(10) << (long double)ans << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    marwan();
    return 0;
}
