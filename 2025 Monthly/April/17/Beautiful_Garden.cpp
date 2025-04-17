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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (n == k)
    {
        cout << 0 << endl;
        return;
    }
    k = n - k;
    sort(all(v));
    int ans = k;
    for (int i = 0; i < k; i++)
    {
        ans += (d - 1) / (v[i]);
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