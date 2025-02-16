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
    vector<int> v(n), pf1(n + 1, 0), pf2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > 0)
        {
            pf1[i + 1] = pf1[i] + v[i];
        }
        else
            pf1[i + 1] = pf1[i];
    }
    vector<int> t = v;
    reverse(all(t));
    for (int i = 0; i < n; i++)
    {
        if (t[i] < 0)
        {
            t[i] = abs(t[i]);
            pf2[i + 1] = pf2[i] + t[i];
        }
        else
            pf2[i + 1] = pf2[i];
    }
    reverse(all(pf2));
    pf1.erase(pf1.begin());
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pf1[i] + pf2[i]);
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