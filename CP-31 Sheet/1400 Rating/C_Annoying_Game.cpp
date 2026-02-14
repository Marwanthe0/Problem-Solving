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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    if (k % 2 == 0)
    {
        int mx = 0, sum = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            ans = max(ans, sum - mx);
            mx = min(mx, sum);
        }
        cout << ans << endl;
    }
    else
    {
        vector<int> prm(n), sfm(n);
        for (int i = 0; i < n; i++)
        {
            prm[i] = (i && prm[i - 1] > 0 ? prm[i - 1] : 0) + a[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            sfm[i] = (i < n - 1 && sfm[i + 1] > 0 ? sfm[i + 1] : 0) + a[i];
        }
        // for (auto vl : prm)
        //     cerr << vl << " ";
        // cerr << endl;
        // for (auto vl : sfm)
        //     cerr << vl << " ";
        // cerr << endl;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (b[i] - a[i]) + prm[i] + sfm[i]);
        }
        cout << ans << endl;
    }
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