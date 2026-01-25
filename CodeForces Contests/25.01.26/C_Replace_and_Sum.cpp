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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), pf(n + 1, 0ll);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int mx = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        mx = max({mx, a[i], b[i]});
        a[i] = mx;
    }
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + a[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << " ";
    }
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