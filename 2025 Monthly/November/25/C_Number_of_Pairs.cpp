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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    int ans = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int left = a - v[i], right = b - v[i];
        auto l = lower_bound(v.begin() + i + 1, v.end(), left), r = upper_bound(v.begin() + i + 1, v.end(), right);
        left = l - v.begin(), right = r - v.begin();
        ans += max(0ll, right - left);
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