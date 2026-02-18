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
    int l = 0, r = 0, ans = 1;
    map<int, int> m;
    while (r < n)
    {
        m[v[r]]++;
        while (((r - l + 1) > m.size()))
        {
            m[v[l]]--;
            if (m[v[l]] <= 0)
            {
                m.erase(v[l]);
            }
            l++;
        }
        if (r - l + 1 == m.size())
        {
            ans = max(ans, r - l + 1);
        }
        r++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}