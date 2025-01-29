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
    vector<int> v(n), dif;
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (int i = 1; i <= n; i++)
        dif.push_back(v[i] - v[i - 1]);
    if (dif.size() == 0)
    {
        cout << 1 << endl;
    }
    else if (dif.size() == 1)
    {
        if (dif[0] != 1)
        {
            cout << dif[0] + 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else
    {
        int x = __gcd(dif[0], dif[1]), ans = 0;
        for (auto vl : dif)
            x = __gcd(x, vl);
        for (auto vl : v)
        {
            ans += (v.back() - vl) / x;
        }
        cout << ans + 1 << endl;
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