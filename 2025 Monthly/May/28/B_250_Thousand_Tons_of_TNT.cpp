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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    set<int> ml;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            ml.insert(i), ml.insert(n / i);
    }
    ml.insert(1);
    ml.insert(n);
    int ans = INT_MIN;
    for (auto xxs : ml)
    {
        int mn = INT_MAX, mx = INT_MIN, count = xxs, sum = 0;
        for (auto vl : v)
        {
            if (count > 0)
            {
                sum += vl;
            }
            count--;
            if (count <= 0)
            {
                count = xxs;
                mn = min(sum, mn), mx = max(sum, mx), sum = 0;
            }
            // if (mx != INT_MIN && mn != INT_MAX)
                ans = max(mx - mn, ans);
        }
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