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
    vector<int> v(n), a, b, ans;
    for (auto &vl : v)
    {
        cin >> vl;
        if (vl & 1)
            a.push_back(vl);
        else
            b.push_back(vl);
    }
    sort(all(a));
    sort(all(b));
    int l = 0, r = 0;
    for (auto vl : v)
    {
        if (vl & 1)
        {
            ans.push_back(a[l++]);
        }
        else
            ans.push_back(b[r++]);
    }
    if (is_sorted(all(ans)))
        yes;
    else
        no;
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