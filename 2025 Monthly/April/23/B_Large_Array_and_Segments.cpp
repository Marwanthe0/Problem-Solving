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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int sum = accumulate(all(v), 0ll);
    if (k * sum < x)
    {
        cout << 0 << endl;
        return;
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum >= x)
        {
            cout << n * k - i << endl;
            return;
        }
    }
    vector<int> pf(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    // e == koto number segment e shesh oise,rem == oi segment er pore koyta baki ase aar
    int e = (x / (sum)), rem = x - (e * sum);
    if (rem == 0)
    {
        cout << (n * k) - (e * n) + 1 << endl;
        return;
    }
    reverse(all(pf));
    pf.pop_back();
    reverse(all(pf));
    cerr << e << " " << rem << endl;
    cout << (n * k) - ((e * n) + ((lower_bound(all(pf), rem) - pf.begin() - 1))) << endl;
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