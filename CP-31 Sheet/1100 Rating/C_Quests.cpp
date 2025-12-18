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
    int n, k, ans = 0, count = 0, rem;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    rem = k - 1;
    int mx = INT_MIN;
    for (int i = 0; i < min(n, k); i++)
    {
        if (i < n)
            count += a[i];
        mx = max(b[i], mx);
        ans = max(ans, count + (rem * mx));
        // cerr << ans << "  ";
        // cerr << a[i] << " " << b[i] << endl;
        // cerr << count << ":" << ans << endl;
        rem--;
    }
    if (rem > 0)
    {
        ans = max(ans, count + (rem * mx));
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