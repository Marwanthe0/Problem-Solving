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
    int sum = accumulate(all(v), 0ll);
    int mn = 0, last = 0, x = v.front();
    for (int i = 0; i < n - 1; i++)
    {
        mn = min(mn, last);
        if (i)
            x = min(x, last);
        last += v[i];
        if ((last - mn) >= sum)
        {
            no;
            return;
        }
    }
    x = min(x, last);
    if (sum - x >= sum)
    {
        no;
        return;
    }
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