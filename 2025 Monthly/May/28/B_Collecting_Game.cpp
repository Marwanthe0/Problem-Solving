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
    vector<int> v(n), t, pf(n + 1, 0), ans(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]] = i;
    }
    t = v;
    sort(all(t));
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + t[i - 1];
    // for (int i = 0; i < n; i++)
    //     cout << t[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << pf[i] << " ";
    // cout << endl;
    int last = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        m[t[i]] = last;
        if (pf[i] < t[i])
            last = i - 1;
    }
    for (auto vl : v)
        cout << m[vl] << " ";
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