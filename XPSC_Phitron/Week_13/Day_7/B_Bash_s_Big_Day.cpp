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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        map<int, int> m;
        for (int j = 2; (j * j) <= v[i]; j++)
        {
            while (v[i] % j == 0)
            {
                m[j]++;
                v[i] /= j;
            }
        }
        if (v[i] > 1)
            m[v[i]]++;
        for (auto vl : m)
        {
            mp[vl.first]++;
        }
    }
    int ans = INT_MIN;
    for (auto vl : mp)
        ans = max(ans, vl.second);
    if (ans != INT_MIN)
        cout << ans << endl;
    else
        cout << 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}