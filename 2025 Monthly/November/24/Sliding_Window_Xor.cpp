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
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++)
    {
        v[i] = (v[i - 1] * a + b) % c;
    }
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    int l = 0, r = 0, xr = 0, ans = 0;
    while (r < n)
    {
        xr ^= v[r];
        if (r - l + 1 == k)
        {
            ans ^= xr;
            xr ^= v[l++];
        }
        r++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}