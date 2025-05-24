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
    bool z = true, o = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
            z = false;
        else
            o = false;
    }
    if (z || o)
    {
        yes;
        return;
    }
    for (int i = 0; i < n - 1; i++)
        if (v[i] == 0 && v[i + 1] == 0)
        {
            yes;
            return;
        }
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