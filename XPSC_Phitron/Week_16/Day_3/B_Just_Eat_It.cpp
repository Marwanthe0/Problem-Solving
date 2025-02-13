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
    vector<int> v(n), pf(n + 1, 0);
    bool zero = false;
    forn
    {
        cin >> v[i];
        pf[i + 1] = pf[i] + v[i];
        if (pf[i + 1] == 0)
            zero = true;
        // cout << pf[i + 1] << " ";
    }
    int sum = pf.back(), mxsum = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!s.empty())
        {
            mxsum = max(mxsum, pf[i] - *s.begin());
        }
        s.insert(pf[i]);
    }
    if (zero)
    {
        mxsum = max(mxsum, pf.back());
    }
    else
    {
        s.erase(0);
        mxsum = max(mxsum, sum - *s.begin());
    }
    if (mxsum >= sum)
        no;
    else
        yes;
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