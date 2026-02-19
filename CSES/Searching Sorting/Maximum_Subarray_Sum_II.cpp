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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n), pf(n, 0);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = 0, ans = LONG_MIN;
    multiset<int> ms;
    bool flag = true;
    while (r < n)
    {
        pf[r] = (r ? pf[r - 1] + v[r] : v[r]);
        if (r - a == -1)
            ms.insert(0);
        else if (r - a >= 0)
        {
            ms.insert(pf[r - a]);
        }
        if (r - b - 1 == -1)
        {
            if (ms.find(0) != ms.end())
                ms.erase(ms.find(0));
        }
        else if ((r - b) - 1 >= 0)
            ms.erase(ms.find(pf[(r - b) - 1]));
        if (ms.size())
            ans = max(ans, pf[r] - *ms.begin());

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