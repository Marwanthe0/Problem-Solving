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
    sort(all(v));
    if (v[0] == v[1] && v[0] == 1)
    {
        no;
        return;
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]] = i;
    }
    for (auto vl : m)
    {
        int x = vl.first;
        bool flag = true;
        if (vl.second > 1)
            continue;
        for (int j = vl.se; j >= 0; j--)
        {
            if (x >= v[j])
                x %= v[j];
            if (x <= 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            yes;
            return;
        }
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