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
    int n, k, mx = INT_MIN;
    cin >> n >> k;
    vector<int> v(n), pf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pf[i + 1] = pf[i] + x;
        mx = max(mx, x);
        v[i] = mx;
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        int pos = (upper_bound(all(v), x) - v.begin());
        cout << pf[pos] << " ";
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