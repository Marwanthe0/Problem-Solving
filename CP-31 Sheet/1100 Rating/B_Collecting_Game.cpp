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
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
    }
    vector<int> t(all(v)), pf(n + 1, 0);
    sort(all(t));
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + t[i - 1];
    }
    int l = 0, r = 1;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        while (l < n && t[l] <= pf[i] + sum)
        {
            if (l >= i)
                sum += t[l];
            l++;
        }
        m[t[i - 1]] = l - 1;
        // cerr << l << " ";
    }
    for (auto vl : v)
    {
        cout << m[vl] << " ";
    }
    cout << endl;
    // cerr << endl;
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