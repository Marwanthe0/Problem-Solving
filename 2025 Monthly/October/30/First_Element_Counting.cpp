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
    vector<int> v(n), t;
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    t = v;
    sort(all(t));
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
            m[t[i]] = -1;
        else
        {
            int low = t[i - 1], hi = t[i + 1];
            int d1 = (t[i] - low - 1) / 2, d2 = ceil((hi - t[i] - 1) / 2.0);
            m[t[i]] = d1 + d2 + 1;
        }
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