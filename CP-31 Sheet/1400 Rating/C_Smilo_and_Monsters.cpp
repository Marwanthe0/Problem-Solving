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
    sort(all(v));
    int cnt = 0, lb = 0, ans = 0ll;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] - cnt <= i - lb)
        {
            ans += i - lb + 1;
            cnt++;
        }
        else
        {
            if (v[i] > cnt)
            {
                int val = v[i] - cnt;
                ans += ((v[i] - cnt) / 2) + 1;
                if (val != 1 && (val & 1))
                    ans++;
            }
        }
        lb = (upper_bound(all(v), cnt) - v.begin());
        // cerr << ans << " " << cnt << " " << lb << endl;
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