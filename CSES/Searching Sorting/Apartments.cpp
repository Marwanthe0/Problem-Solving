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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), a(m);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : a)
        cin >> vl;
    sort(all(a));
    sort(all(v));
    int l = 0, r = 0, ans = 0;
    while (l < n)
    {
        while (r < m && v[l] - k > a[r])
        {
            r++;
        }
        if (r == m)
            break;
        if (v[l] + k >= a[r])
            ans++, r++;
        l++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}