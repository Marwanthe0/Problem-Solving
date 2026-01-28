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
    vector<int> v(n), pf(n + 1, 0), df(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + ((i != 1) ? abs(v[i - 1]) : v[i - 1]);
    for (int i = n - 1; i >= 0; i--)
        df[i] = df[i + 1] - v[i];
    // for (auto vl : pf)
    //     cerr << vl << " ";
    // cerr << endl;
    df.insert(df.begin(), 0);
    // for (auto vl : df)
    //     cerr << vl << " ";
    // cerr << endl;
    int ans = INT_MIN;
    for (int i = 1; i < pf.size(); i++)
    {
        ans = max(ans, pf[i - 1] + df[i + 1]);
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