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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= q)
        {
            count++;
        }
        else
        {
            if (count >= k)
            {
                int t = (count - k + 1);
                // cerr << count << " ";
                ans += (t * (t + 1)) / 2;
            }
            count = 0;
        }
    }
    if (count >= k)
    {
        int t = (count - k + 1);
        // cerr << count << " ";
        ans += (t * (t + 1)) / 2;
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