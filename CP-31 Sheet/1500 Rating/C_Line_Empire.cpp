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
    int sum = accumulate(all(v), 0ll), cnt = n, last = 0ll, ans = 0ll;
    for (int i = 0; i < n; i++)
    {
        sum -= v[i], cnt--;
        int nanile = (sum - cnt * last) * b;
        int nile = (sum - cnt * v[i]) * b + a * (v[i] - last);
        ans += b * (v[i] - last);
        if (nile < nanile)
        {
            ans += a * (v[i] - last);
            last = v[i];
        }
        // cerr << ans << " " << last << " " << nile << " " << nanile << endl;
    }
    // cerr << endl;
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