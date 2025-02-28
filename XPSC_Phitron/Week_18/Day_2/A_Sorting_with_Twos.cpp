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
    if (is_sorted(all(v)))
    {
        yes;
        return;
    }
    vector<int> boro;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            // if ((((i + 1) & i)) == 0)
            // {
            //     yes;
            //     return;
            // }
            // else
            // {
            //     no;
            //     return;
            // }
            boro.push_back(i);
            // cout << i + 1 << endl;
            // return;
        }
    }
    for (auto vl : boro)
    {
        if ((vl + 1) & vl)
        {
            no;
            return;
        }
        // cout << vl << " ";
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