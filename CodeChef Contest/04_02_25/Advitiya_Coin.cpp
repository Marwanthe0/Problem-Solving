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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int mn = INT_MAX, mx = INT_MIN, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mn != INT_MAX && abs(v[i] - mn) > k)
        {
            count++, mn = INT_MAX,mx = INT_MIN;
        }
        else if (mx != INT_MIN && abs(v[i] - mx) > k)
        {
            count++, mx = INT_MIN,mn = INT_MAX;
        }
        else
            mn = min(mn, v[i]), mx = max(mx, v[i]);
    }
    cout << count << endl;
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